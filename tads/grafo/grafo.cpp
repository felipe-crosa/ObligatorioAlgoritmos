#pragma once
#include <iostream>
#include "../lista/lista.cpp"
#include "../../helpers/arrays.cpp"
#include "../heap/heap.cpp"
#include "../../helpers/Numeros.cpp"
using namespace std;

class Arista {
    public:
        int costo;
        int origen;
        int destino;

        Arista( int origen, int destino, int costo = 1): origen(origen), costo(costo), destino(destino){};

        Arista* clon() {
            return new Arista(origen, destino, costo);
        }
};

bool criterioComparaAristasPrim (Arista* a1, Arista* a2) {
    return (a1->origen != a2->origen) 
        ? a1->origen < a2->origen 
        : a1->destino < a2->destino;
}

class Grafo {
    private:
        bool esDirigido;
        int tope;
        int cantVertices;
        int** vertices;

        void agregarAdyacenciasHeap (int vertice, Heap<Arista*>* heap, bool* vis) {
            IteradorLista<Arista*>* iter = adyacencias[vertice]->obtenerIterador();
            while(iter->hayElemento()){
                Arista* elemento = iter->obtenerElemento();
                if(!vis[elemento->destino]){
                    heap->insertar(elemento, elemento->costo);
                } 
                iter->avanzar();
            }
        }
        


    public:
        Lista<Arista*> ** adyacencias;
        Lista<int> * listaHuecos;
        Grafo(int tope, bool esDirigido = false){
            this->tope = tope;
            this->esDirigido = esDirigido;
            cantVertices = 0;
            vertices = new int*[this->tope + 1];
            adyacencias = new Lista<Arista*>*[tope + 1];
            listaHuecos = new Lista<int>();

            for(int i=1; i<=tope; i++){
                 vertices[i] = NULL;
                 adyacencias[i] = new Lista<Arista*>();
                 listaHuecos->insertarFin(i);
            }
        }

        void insertarVertice(int vert){
            int hueco = this->listaHuecos->obtenerPpio();
            this->listaHuecos->borrarPpio();

            this->vertices[hueco] = new int(vert);
            this->cantVertices++;
        }

        void insertarArista(int origen, int destino, int costo = 1){
            Arista* arista = new Arista(origen, destino, costo);
            adyacencias[origen]->insertarPpio(arista);
            if(!esDirigido){
                Arista* arista = new Arista(destino, origen, costo);
                adyacencias[destino]->insertarPpio(arista);
            }
        }

        Heap<Arista*>* prim (int* verticesDescartar, int cantidadDescartar ){
            int cantidadMaximaAristas = (cantVertices*(cantVertices-1))/2;
            Heap<Arista*> * retorno = new Heap<Arista*>(cantidadMaximaAristas, true, criterioComparaAristasPrim);

            bool* estanDescartados = new bool[tope+1];
            for(int i=0 ; i<=tope; estanDescartados[i++] = false);
            for(int j=0 ; j<cantidadDescartar; j++ ){
                estanDescartados[verticesDescartar[j]] = true;
            }

            Heap<Arista*> * minHeap = new Heap<Arista*>(cantidadMaximaAristas);

            int vertice=1;
            while(vertice <= cantVertices){
                if(!estanDescartados[vertice]) break;
                vertice++;
            }
            estanDescartados[vertice] = true;

            this->agregarAdyacenciasHeap(vertice, minHeap, estanDescartados);    
            int cantidadAgregadas = 0;
            while( cantidadAgregadas < (cantVertices-cantidadDescartar-1) && !minHeap->esVacio() ){
                Arista* proximaArista = minHeap->obtenerProximo();
                int destino = proximaArista->destino;
                int origen = proximaArista->origen;
                int costo = proximaArista->costo;

                minHeap->borrarProximo();

                if(!estanDescartados[destino]) {
                    estanDescartados[destino] = true;
                    retorno->insertar(new Arista(min(destino, origen), max(destino, origen), costo), min(destino, origen));
                    cantidadAgregadas++;
                    this->agregarAdyacenciasHeap(destino, minHeap, estanDescartados);
                }
                
            }
            return retorno;
        }

        void dfs (int vertice , bool* vis){
            vis[vertice] = true;
            IteradorLista<Arista*>* ady = adyacencias[vertice]->obtenerIterador();
            while(ady->hayElemento()){
                Arista* arista = ady->obtenerElemento();
                if(!vis[arista->destino]) dfs(arista->destino, vis);
                ady->avanzar();
            }
        }

        bool esConexoSinDosVertices (int vertice1, int vertice2) {
            bool* vis = new bool[tope+1];
            for(int i=1; i<=tope ; vis[i++] = false);
            vis[vertice1] = true;
            vis[vertice2] = true;

            int vertice = 1;
            while(vertice <= cantVertices){
                if(!vis[vertice]) break;
                vertice++;
            }

            dfs(vertice, vis);
            int retorno = true;
            for(int i=1; i<=cantVertices && retorno; i++){
                retorno = retorno && vis[i];
            }
            delete [] vis;
            return retorno;
        }

        bool esTriconexo() {
            bool retorno = true;
            for(int i=1; i < cantVertices; i++){
                for(int j=i+1; j <= cantVertices; j++){
                    retorno = retorno && esConexoSinDosVertices(i,j);
                    if(!retorno) return retorno;
                }
            }
            return retorno;
        }
};


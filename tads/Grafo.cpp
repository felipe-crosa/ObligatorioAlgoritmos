#include "Arista.cpp";
#include "lista.cpp";

class Grafo{

private:
    int tope;
    int cantVertices;
    int* vertices;
    Lista<Arista*>** listaAdyacencia;

public: //constructor, destructor, agregar vertice, agregar una arista (pre: existan los dos vertices)
    ~Grafo(){
        delete[] listaAdyacencia;
        delete[] vertices;
    }

    Grafo(int tope){ 
        this->tope = tope;
        this->cantVertices = 0;
        this->vertices = new int[tope];
        this->listaAdyacencia = new Lista<Arista*>*[tope];
        for(int i = 0; i < tope; i++){
            this->listaAdyacencia[i] = new Lista<Arista*>();
        }
    }

    void agregarVertice(int vertice){ 
        if(cantVertices < tope){
            vertices[cantVertices] = vertice;
            cantVertices++;
        }
    }

    void agregarArista(int origen, int destino, int costo){ 
        if(existenVertices(origen, destino)){
            Arista* arista = new Arista(destino, costo);
            listaAdyacencia[devolverPosicion(origen)]->insertarPpio(arista);
        }
    }

    bool existenVertices(int origen, int destino){
        bool existeOrigen = false;
        bool existeDestino = false;
        for(int i = 0; i < cantVertices; i++){
            if(vertices[i] == origen){
                existeOrigen = true;
            }
            if(vertices[i] == destino){
                existeDestino = true;
            }
        }
        return existeOrigen && existeDestino;
    }

    int devolverPosicion(int vertice){
        int posicion = -1;
        for(int i = 0; i < cantVertices; i++){
            if(vertices[i] == vertice){
                posicion = i;
            }
        }
        return posicion;
    }
    
};
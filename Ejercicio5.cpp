#include <iostream>
#include <fstream>
#include <string>
#include "tads/heap/heap.cpp"

using namespace std;

class NodoIncidencia {
    private:
        int vertice;
        int cantidad;
    
    public:
        NodoIncidencia(int vert){
            vertice = vert;
            cantidad = 0;
        }
        void aumentarIncidencia(){
            cantidad++;
        }
        int getVertice(){
            return vertice;
        }
        int getCantidad(){
            return cantidad;
        }
};

bool compararNodos (NodoIncidencia* nodo1 , NodoIncidencia* nodo2) {
    return nodo1->getVertice() > nodo2->getVertice();
}


int main() {
    int cantidadVertices, cantidadAristas;
    cin >> cantidadVertices;
    NodoIncidencia** incidencias = new NodoIncidencia*[cantidadVertices + 1];
    for(int i = 1; i <= cantidadVertices; i++){
        incidencias[i] = new NodoIncidencia(i);
    }

    cin >> cantidadAristas;
    for (int i = 0 ; i < cantidadAristas ; i++){
        int origen, llegada, valor;
        cin >> origen;
        cin >> llegada;
        (incidencias[llegada])->aumentarIncidencia();
    }
    Heap<NodoIncidencia*>* maxHeap = new Heap<NodoIncidencia*>(cantidadVertices, false, compararNodos);
    for (int i=1; i <=cantidadVertices ; i++){
        maxHeap->insertar(incidencias[i],incidencias[i]->getCantidad());
    }
 
    for(int i=0 ; i < cantidadVertices ; i++){
        NodoIncidencia* proximo = maxHeap->obtenerProximo();
        cout << proximo->getVertice() << " " << proximo->getCantidad() << endl;
        maxHeap->borrarProximo();
    }

    delete [] incidencias;

    return 0;
}


 
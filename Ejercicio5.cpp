#include <iostream>
#include "tads/minHeap.cpp"

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

void mergeSort(NodoIncidencia** array){

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
        cin >> valor;
        cout << llegada << endl;
        (incidencias[llegada])->aumentarIncidencia();
    }

    mergeSort(incidencias);
 
    for(int i=1 ; i <= cantidadVertices ; i++){
        cout << incidencias[i]->getVertice() << " " << incidencias[i]->getCantidad() << endl;
    }
    return 0;
}
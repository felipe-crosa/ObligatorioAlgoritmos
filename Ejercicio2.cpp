#include <iostream>
#include "tads/minHeap.cpp"

using namespace std;

int main() {
    int cantidad;
    cin >> cantidad;
    MinHeap * colaP = new MinHeap(cantidad);
    while(cantidad-- > 0){
        int elemento;
        cin >> elemento;
        colaP->insertar(elemento);
    }
    while(!colaP->esVacio()){
        cout << colaP->obtenerMin() << endl;
        colaP->borrarMin();
    }
    return 0;
};
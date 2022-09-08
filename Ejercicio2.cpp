#include <iostream>
#include "tads/minHeap.cpp"

using namespace std;

int main() {
    MinHeap * colaP = new MinHeap(20);
    colaP->insertar(5);
    colaP->insertar(867234);
    colaP->insertar(27);
    colaP->insertar(1891);
    colaP->insertar(31);
    colaP->insertar(19);
    
    while(!colaP->esVacio()){
        cout << colaP->obtenerMin() << endl;
        colaP->borrarMin();
    }

    return 0;
};
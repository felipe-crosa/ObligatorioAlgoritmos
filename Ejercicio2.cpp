#include <iostream>
#include "tads/heap/heap.cpp"

using namespace std;

int main() {
    int cantidad;
    cin >> cantidad;
    Heap<int> * colaP = new Heap<int>(cantidad);

    while(cantidad-- > 0){
        int elemento;
        cin >> elemento;
        colaP->insertar(elemento, elemento);
    }

    while(!colaP->esVacio()){
        cout << colaP->obtenerProximo() << endl;
        colaP->borrarProximo();
    }
    delete colaP;
    return 0;
};
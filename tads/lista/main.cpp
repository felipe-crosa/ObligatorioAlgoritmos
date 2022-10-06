#include <iostream>
using namespace std;

#include "lista.cpp"

int main(){
    Lista<int> * lista = new Lista<int>();

    lista->insertarFin(1);
    lista->insertarFin(2);
    lista->insertarFin(3);
    lista->insertarFin(4);
    lista->insertarFin(5);

    IteradorLista<int>* it = lista->obtenerIterador();
    while(it->hayElemento()){
        int num = it->obtenerElemento();
        cout << num << endl;
        it->avanzar();
    }

    return 0;
}
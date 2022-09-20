#include <iostream>
using namespace std;
#include <string>
#include "tads/hashCerrado.cpp"

int main() {
    int num;
    cin >> num;
    HashCerrado* hash = new HashCerrado(num);

    while(num-- > 0){
        string linea;
        cin >> linea;
        hash->agregar(linea);
    }
    cout << hash->cantidadElementos() << endl;
    delete hash;
    return 0;
}

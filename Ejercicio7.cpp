#include <iostream>
#include "tads/lista/lista.cpp"
using namespace std;


int MaximaSumatoria(Lista<int>* pila1, Lista<int>* pila2, Lista<int>* pila3, int suma1, int suma2, int suma3){
    while(!pila1->esVacia() && !pila2->esVacia() && !pila3->esVacia()){
        if(suma1 == suma2 && suma1 == suma3) return suma1;

        if(suma1 >= suma2 && suma1 >= suma3){
            suma1 -= pila1->obtenerPpio();
            pila1->borrarPpio();
        }
        else if(suma2 >= suma1 && suma2 >= suma3){
                suma2 -= pila2->obtenerPpio();
                pila2->borrarPpio();
        }
        else{
            suma3 -= pila3->obtenerPpio();
            pila3->borrarPpio();
        }
    }
    return 0;
}

int cargarPila(Lista<int>* pila , int largo) {
    int suma = 0;
    for(int i=0; i<largo; i++){
        int n;
        cin >> n;
        suma += n;
        pila->insertarFin(n);
    }
    return suma;
}

int main(){
    int largo1, largo2, largo3;

    cin >> largo1;
    Lista<int>* pila1 = new Lista<int>();
    int suma1 = cargarPila(pila1, largo1);
  

    cin >> largo2;
    Lista<int>* pila2 = new Lista<int>();
    int suma2 = cargarPila(pila2, largo2);

    cin >> largo3;
    Lista<int>* pila3 = new Lista<int>();
    int suma3 = cargarPila(pila3, largo3);

    cout << MaximaSumatoria(pila1, pila2, pila3, suma1, suma2, suma3) << endl;
    delete pila1;
    delete pila2;
    delete pila3;
    return 0;
}
#include <iostream>
#include "tads/lista/lista.cpp"
using namespace std;


int MaximaSumatoria(Lista<int>* pila1, Lista<int>* pila2, Lista<int>* pila3, int suma1, int suma2, int suma3){
    int ret = 0;
    bool salir = false;
    while(!pila1->esVacia() && !pila2->esVacia() && !pila3->esVacia() && !salir){
        
        if(suma1 == suma2 && suma1 == suma3){
            ret = suma1;
            salir = true;
        }

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
    return ret;
}


int main(){
    int largo1, largo2, largo3;
    int suma1 = 0;
    int suma2 = 0;
    int suma3 = 0;
    cin >> largo1;
    Lista<int>* pila1 = new Lista<int>();
    for(int i=0; i<largo1; i++){
        int n;
        cin >> n;
        suma1 += n;
        pila1->insertarFin(n);
    }

    cin >> largo2;
    Lista<int>* pila2 = new Lista<int>();
    for(int i=0; i<largo2; i++){
        int m;
        cin >> m;
        suma2 += m;
        pila2->insertarFin(m);
    }

    cin >> largo3;
    Lista<int>* pila3 = new Lista<int>();
    for(int i=0; i<largo3; i++){
        int p;
        cin >> p;
        suma3 += p;
        pila3->insertarFin(p);
    }

    cout << MaximaSumatoria(pila1, pila2, pila3, suma1, suma2, suma3) << endl;
    delete pila1;
    delete pila2;
    delete pila3;
    return 0;
}
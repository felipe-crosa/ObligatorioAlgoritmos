#include <iostream>
#include <string>
#include "tads/heap/heap.cpp"
using namespace std;


bool compararAux(string c1, string c2, int i){
    if((c1[i] == '\0' && c1[0]>=c2[i]) || c1[i] > c2[i]) return true;
    if((c2[i] == '\0' && c2[0]>=c1[i]) || c1[i] < c2[i]) return false;
    return compararAux(c1, c2, i+1);
}


bool comparar(string c1, string c2){
    return compararAux(c1, c2, 0);
}

string MaximoNumero(Heap<string>* maxHeap, int cantElementos){
    string ret = "";
   
    while(!maxHeap->esVacio()){
        ret += maxHeap->obtenerProximo();
        maxHeap->borrarProximo();
    }

   return ret;
}


int main(){ 
    int cantElementos;
    cin >> cantElementos;
    Heap<string>* maxHeap = new Heap<string>(cantElementos, false, comparar);
    
    for(int i=0; i<cantElementos; i++){
        string num;
        cin >> num;
        maxHeap->insertar(num, 0);
    }

    cout << MaximoNumero(maxHeap, cantElementos) << endl;

    return 0;
}
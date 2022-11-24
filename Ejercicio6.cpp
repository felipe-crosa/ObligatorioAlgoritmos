#include <iostream>
using namespace std;


int NumeroSinPareja(int* elementos, int primero, int ultimo){
    if(primero == ultimo) return elementos[primero];
    
    int medio = (primero + ultimo)/2;

    if(medio%2 == 0){
        if(elementos[medio] != elementos[medio+1]){
            return NumeroSinPareja(elementos, primero, medio);
        }
        else{
            return NumeroSinPareja(elementos, medio+2, ultimo);
        }
    }
    else{
        if(elementos[medio] == elementos[medio-1]){
            return NumeroSinPareja(elementos, medio+1, ultimo);
        }
        else{
            return NumeroSinPareja(elementos, primero, medio-1);
        }

    }
}


int main(){
    int cantElementos;
    cin >> cantElementos;
    int* elementos = new int[cantElementos];
    for(int i=0; i<cantElementos; i++){
        cin >> elementos[i];
    }

    cout << NumeroSinPareja(elementos, 0, cantElementos-1) << endl;
    delete [] elementos;
    return 0;
}
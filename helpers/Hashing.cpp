#include <iostream>
#include "Numeros.cpp"
using namespace std;

int hornerMethod(string palabra, int multiplo = 37){
    int valor = 0;
    for(int i = 0 ; i < palabra.length() ; i++){
        valor = (valor * multiplo) + (int)palabra[i];
    }
    return valor;
}

int generarHash(int valor, int largo){
    return valorAbsoluto(valor) % largo;
}
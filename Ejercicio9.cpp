#include <iostream>
#include "tads/lista/lista.cpp"

using namespace std;
#define INF 99999

void SubconjuntoSumaM(int& solOptima, int solActual, int* elementos, int& cantElementos,
            int M, int pos){
    
    if(M == 0){
        if(solActual < solOptima || solOptima == INF){
            solOptima = solActual;
        }
    }
    else if (M > 0 && pos < cantElementos){
        SubconjuntoSumaM(solOptima, solActual+1, elementos, cantElementos, M-elementos[pos], pos);
        int vecesPosible = M/elementos[pos];
        for(int i=0; i<=vecesPosible; i++){
           SubconjuntoSumaM(solOptima, solActual+i, elementos, cantElementos, M-i*elementos[pos], pos+1);
        }
    }
}


int main(){
    int cantElementos, cantCasosPrueba;
    cin >> cantElementos;
    int* elementos = new int[cantElementos];
    for(int i=0; i<cantElementos; i++){
        cin >> elementos[i];
    }
    cin >> cantCasosPrueba;
    int* casosPrueba = new int[cantCasosPrueba];
    for(int i=0; i<cantCasosPrueba; i++){
        cin >> casosPrueba[i];
    }

    int solOptima, solActual, pos;

    for(int i=0; i<cantCasosPrueba; i++){
        solActual = 0;
        pos = 0;
        solOptima = INF;
        int M = casosPrueba[i];
        SubconjuntoSumaM(solOptima, solActual, elementos, cantElementos, M, pos);

        if(solOptima == INF){
            cout << "0" << endl;
        }
        else{
            cout << solOptima << endl;
        }
    }
    return 0;
}
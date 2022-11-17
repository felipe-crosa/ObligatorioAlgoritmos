#include <iostream>
#include "./helpers/Numeros.cpp"
using namespace std;
#define INF 99999


void subconjuntoSumaM(int** matDP, int* elementos, int cantElementos, int cota){
    for(int i=0; i<cantElementos; i++){
        matDP[i][0] = 0;
    }
    for(int j=0; j <= cota; j++){
        matDP[0][j] = j%elementos[0]==0 ? j/elementos[0] : INF;
    }

    for(int i=1; i<cantElementos; i++){
        for(int j=1; j<=cota; j++){
            if(j < elementos[i]){
                matDP[i][j] = matDP[i-1][j];
            } else {
                matDP[i][j] = min(matDP[i-1][j], 1+matDP[i][j-elementos[i]]);   
            }
        }
    }

}


int main(){
    int cantElementos, cantCasosPrueba, cota;
    cin >> cantElementos;
    int* elementos = new int[cantElementos];
    for(int i=0; i<cantElementos; i++){
        cin >> elementos[i];
    }
    cin >> cota;
    cin >> cantCasosPrueba;
    int* casosPrueba = new int[cantCasosPrueba];
    for(int i=0; i<cantCasosPrueba; i++){
        cin >> casosPrueba[i];
    }

    int** matDP = new int*[cantElementos];
    for(int i=0; i < cantElementos; i++){
        matDP[i] = new int[cota + 1];
    }

    subconjuntoSumaM(matDP, elementos, cantElementos, cota);
    
    for(int i=0; i<cantCasosPrueba; i++){
        int valor = matDP[cantElementos-1][casosPrueba[i]];
        cout << ((valor==INF) ? 0 : 1) << endl;
    }

    return 0;
}
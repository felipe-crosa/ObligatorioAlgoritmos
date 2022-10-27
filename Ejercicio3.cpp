#include <iostream>
#include <fstream>
#include <string>
#include "tads/grafo/grafo.cpp"
#include "tads/lista/lista.cpp"
#include "tads/lista/iteradorLista.cpp"


#include "helpers/LeerDatos.cpp"
using namespace std;

int main () {

   // string inFile;
   // cin >> inFile;
   // ifstream myFile(inFile);
   // cin.rdbuf(myFile.rdbuf());
   // ofstream myFile2 ("res.txt");
   // cout.rdbuf(myFile2.rdbuf());      
   
   Grafo* grafo = generarGrafo(true, true);

   int cantidadIngorados;
   cin >> cantidadIngorados;
   int* ignorados = new int[cantidadIngorados];
   for(int i=0 ; i<cantidadIngorados; i++) {
      cin >> ignorados[i];
   }

   Heap<Arista*>* arbolMinimoCubrimiento = grafo->prim(ignorados, cantidadIngorados);
   cout << arbolMinimoCubrimiento->cantElementos() << endl;
   while(!arbolMinimoCubrimiento->esVacio()){
      Arista* elemento = arbolMinimoCubrimiento->obtenerProximo();
      cout << elemento->origen << " " << elemento->destino << " " << elemento->costo << endl;
      arbolMinimoCubrimiento->borrarProximo();
   }
   
   return 0;
}
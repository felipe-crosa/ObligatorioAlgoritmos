#include <iostream>
#include <fstream>
#include <string>
#include "tads/grafo/grafo.cpp"
#include "tads/lista/lista.cpp"
#include "tads/lista/iteradorLista.cpp"


#include "helpers/LeerDatos.cpp"
using namespace std;

int main () {

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

   delete arbolMinimoCubrimiento;
   delete [] ignorados;

   return 0;
}
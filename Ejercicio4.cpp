#include <iostream>
#include <fstream>
#include <string>
#include "tads/grafo/grafo.cpp"
#include "helpers/LeerDatos.cpp"
using namespace std;

int main () {   
   Grafo* grafo = generarGrafo();
   cout << ((grafo->esTriconexo()) ? 1 : 0) << endl;
   delete grafo;
   return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include "tads/grafo/grafo.cpp"
#include "helpers/LeerDatos.cpp"
using namespace std;

int main () {
   // string inFile;
   // cin >> inFile;
   // ifstream myFile(inFile);
   // cin.rdbuf(myFile.rdbuf());
   // ofstream myFile2 ("res.txt");
   // cout.rdbuf(myFile2.rdbuf());   
   
   Grafo* grafo = generarGrafo();
   cout << ((grafo->esTriconexo()) ? 1 : 0);
   return 0;
}
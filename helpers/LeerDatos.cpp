#pragma once
#include <iostream>
#include "../tads/grafo/grafo.cpp"
using namespace std;

Grafo* generarGrafo(bool esDirigido = false, bool esPonderado = false){
    int cantidadVertices, cantAristas;
    cin >> cantidadVertices;
    Grafo* grafo = new Grafo(cantidadVertices);
    for(int i=1; i<=cantidadVertices; grafo->insertarVertice(i++));
    cin >> cantAristas;
    for (int i = 0 ; i < cantAristas ; i++){
        int origen, destino, valor = 1;
        cin >> origen;
        cin >> destino;
        if(esPonderado) cin >> valor;
        grafo->insertarArista(origen, destino, valor);
    }
    return grafo;
}
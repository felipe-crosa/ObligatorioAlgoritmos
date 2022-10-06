#pragma once

#include "iostream"
#include "nodoLista.cpp"
#include "iteradorLista.cpp"
using namespace std;

template <class T>
class Lista
{
private:
  NodoLista<T> *ppio, *fin;
  int cant;

  void vaciar(NodoLista<T> *&l)
  {
    if (l)
    {
      vaciar(l->sig);
      delete l;
      l = NULL;
    }
  }

public:
  Lista()
  {
    ppio = fin = NULL;
    cant = 0;
  }

  ~Lista()
  {
    vaciar(ppio);
  }

  bool esVacia()
  {
    return cant == 0;
  }

  int largo()
  {
    return cant;
  }

  void insertarPpio(T dato)
  {
    ppio = new NodoLista<T>(dato, ppio);
    if (!fin)
    {
      fin = ppio;
    }
    cant++;
  }

  void insertarFin(T dato)
  {
    if (!fin)
    {
      fin = ppio = new NodoLista<T>(dato);
    }
    else
    {
      fin->sig = new NodoLista<T>(dato);
      fin = fin->sig;
    }
    cant++;
  }

  // Pre: !esVacia()
  T obtenerPpio()
  {
    return ppio->dato;
  }

  // Pre: !esVacia()
  T obtenerFin()
  {
    return fin->dato;
  }

  void borrarPpio()
  {
    NodoLista<T> *aBorrar = ppio;
    ppio = ppio->sig;
    delete aBorrar;
    if (!ppio)
    {
      fin = NULL;
    }
    cant--;
  }

  IteradorLista<T>* obtenerIterador(){
      return new IteradorLista<T>(ppio);
  }
};
#pragma once
#include <functional>
#include <iostream>
using namespace std;
template<class T>
class NodoHeap {
    public:
        T dato;
        int prioridad;
        NodoHeap(T dato, int prioridad): dato(dato), prioridad(prioridad){}
};

template<class T>
bool Comparator (T x1, T x2) {
    return true;
}

template<class T>
class Heap {
    private:
        NodoHeap<T> ** heap;
        int largo;
        int tope;
        bool esMinHeap; //si no es Min es Max
        bool (*comparator)(T, T);

        void flotar (int pos) {
            for(; pos > 0 && pos < this->tope && compararDatos(this->heap[pos], this->heap[posPadre(pos)]); pos = posPadre(pos)){
                cambiar(pos, posPadre(pos));
            }
        }

        void hundir (int pos) {
            int cantHijos = cantidadHijos(pos);
            if(!cantHijos) return;
            int posHijo = (cantHijos == 2 && compararDatos(segundoHijo(pos), primerHijo(pos))) ? 2*pos+2 : 2*pos+1;
            if( compararDatos(heap[posHijo] , heap[pos])){
                cambiar(posHijo, pos);
                hundir(posHijo);    
            } 
        }

        bool compararDatos (NodoHeap<T>* dato1, NodoHeap<T>* dato2) {
            bool igualPrioridad = dato1->prioridad == dato2->prioridad;
            if(igualPrioridad) return comparator(dato1->dato, dato2->dato);
            return (esMinHeap) ? dato1->prioridad < dato2->prioridad :  dato1->prioridad > dato2->prioridad;
        }

        int posPadre (int pos) {
            return (pos-1) /2 ;
        }

        int cantidadHijos (int pos){
            return (2*pos +2 < this->tope) ? 2 :
                (2*pos +1 < this->tope) ? 1 : 0; 
        }


        NodoHeap<T>* primerHijo (int pos){
            return this->heap[2*pos +1];
        }

        NodoHeap<T>* segundoHijo (int pos){
            return this->heap[2*pos +2];
        }

        void cambiar(int pos1, int pos2){
            NodoHeap<T>* temp = this->heap[pos1];
            this->heap[pos1] = this->heap[pos2];
            this->heap[pos2] = temp;
        }

    public:
   
        Heap(int largo, bool esMinHeap = true, bool (*comparator)(T, T) = Comparator){
            this->largo = largo;
            this->tope = 0;
            this->heap = new NodoHeap<T>*[largo];
            this->esMinHeap = esMinHeap;
            this->comparator = comparator;
        }

        ~Heap(){
            vaciar();
            delete [] this->heap;
        }

        int cantElementos() {
            return tope;
        }

        // Pre: !esVacio()
        T obtenerProximo(){
            return heap[0]->dato;
        }

        bool esVacio(){
            return tope == 0;
        }

        bool esLleno(){
            return tope == largo;
        }

        void vaciar(){
            while(tope>0){
                delete heap[--tope];
            }
        }

        // Pre: !esLleno()
        void insertar(T dato, int prioridad){
            heap[tope++] = new NodoHeap<T>(dato, prioridad);
            flotar(tope-1);
        }

        // Pre: !esVacio
        void borrarProximo(){
            heap[0] = heap[--tope];
            hundir(0);
        }

};

#include <iostream>
using namespace std;

class MinHeap {
    private:
        int* heap;
        int largo;
        int tope;

        void flotar (int pos) {
            for(; pos > 0 && pos < this->tope && this->heap[pos] < this->heap[posPadre(pos)]; pos = posPadre(pos)){
                cambiar(pos, posPadre(pos));
            }
        }

        void hundir (int pos) {
            int cantHijos = cantidadHijos(pos);
            if(!cantHijos) return;
            int posHijoMenor = (cantHijos == 2 && primerHijo(pos) > segundoHijo(pos) ) ? 2*pos+2 : 2*pos+1;
            if(this->heap[posHijoMenor] < this->heap[pos]){
                cambiar(posHijoMenor, pos);
                hundir(posHijoMenor);    
            } 
        }

        int posPadre (int pos) {
            return (pos-1) /2 ;
        }

        int cantidadHijos (int pos){
            return (2*pos +2 < this->tope) ? 2 :
                (2*pos +1 < this->tope) ? 1 : 0; 
        }


        int primerHijo (int pos){
            return this->heap[2*pos +1];
        }

        int segundoHijo (int pos){
            return this->heap[2*pos +2];
        }

        void cambiar(int pos1, int pos2){
            int temp = this->heap[pos1];
            this->heap[pos1] = this->heap[pos2];
            this->heap[pos2] = temp;
        }

    public:
        MinHeap(int largo){
            this->largo = largo;
            this->tope = 0;
            this->heap = new int[largo];
        }

        ~MinHeap(){
            delete [] this->heap;
        }

        int cantElementos() {
            return tope;
        }

        // Pre: !esVacio()
        int obtenerMin(){
            return heap[0];
        }

        bool esVacio(){
            return tope == 0;
        }

        bool esLleno(){
            return tope == largo;
        }

        void vaciar(){
            tope = 0;
        }

        // Pre: !esLleno()
        void insertar(int dato){
            heap[tope++] = dato;
            flotar(tope-1);
        }

        // Pre: !esVacio
        void borrarMin(){
            heap[0] = heap[--tope];
            hundir(0);
        }

};

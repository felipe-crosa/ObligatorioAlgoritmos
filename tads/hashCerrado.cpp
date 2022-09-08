#include <iostream>
using namespace std;
#include <string>
#include "../helpers/NumeroPrimos.cpp"
#include "../helpers/Hashing.cpp"



class HashCerrado {
   private:
    // Variable of type T
    string** array;
    int cantidad;
    int largoArray;

   public:
    HashCerrado(int cantidad){
        this->largoArray = proximoPrimo(cantidad*2);
        this->array = new string*[this->largoArray];
        for(int i=0; i < this->largoArray ; i ++){
            this->array[i] = NULL;
        }
        this->cantidad = 0;
    }

    ~HashCerrado(){
        destruir();
        delete[] array;
    }

    void agregar(string clave){
        if(esLleno) return;
        int valorString = hornerMethod(clave);
        int pos = generarHash(valorString, this->largoArray);
        bool termino = false;
        while(!termino){
            if(this->array[pos] == NULL){
                this->array[pos] = &clave;
                this->cantidad++;
                termino = true;
            }else if(clave.compare(*(this->array[pos])) == 0){
                termino = true;
            }else{
                pos = (pos+1)%this->largoArray;
            }
        }
    }

    void destruir(){
        for(int i=0; i<this->largoArray; i++){
            delete this->array[i]; 
        }
    }

    bool esLleno() {
        return cantidad == largoArray;
    }
};

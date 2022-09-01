#include <iostream>

#include <string>
#include "NumeroPrimos.cpp"



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
    };

    void agregar(string email){
        
    }

    void destruir(){

    }
};

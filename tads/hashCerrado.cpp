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

    void agregar(string clave){
        if(esLleno) return;
        int valorString = hornerMethod(clave);
        int clave = generarHash(valorString, this->largoArray);
        
        
    }

    void borrar(string clave){}

    void destruir(){
    }

    bool esLleno() {
        return cantidad == largoArray;
    }
};

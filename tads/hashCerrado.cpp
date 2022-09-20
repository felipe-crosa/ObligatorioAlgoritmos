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

    bool insertar (int pos, string clave) {
        bool retorno = false;
        if(array[pos] == NULL){
            array[pos] = new string(clave);
            cantidad++;
            retorno = true;
        }        
        else if(clave.compare(*array[pos]) == 0) {
            retorno = true;
        }
        return retorno;
    }

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
        delete[] array;
    }

    void agregar(string clave){
        if(esLleno()) return;
        int valorString = hornerMethod(clave);
        int valorHash = generarHash(valorString, this->largoArray);
        bool termino = false;
        for(int i = 0; !termino; i++){
            int pos = (valorHash + (i*i)) % largoArray;
            termino = insertar(pos, clave);
        }
    }

    bool esLleno() {
        return cantidad == largoArray;
    }

    int cantidadElementos(){
        return this->cantidad;
    }
};

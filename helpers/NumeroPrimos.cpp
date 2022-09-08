#include <iostream>
using namespace std;

int proximoPrimo(int numero){
    while(!esPrimo(++numero));
    return numero;
}


bool esPrimo(int num){
    if(num < 2 || (num%2==0 && num>2)) return false;
    
    for(int i=3; i<num/2; i+=2){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

#pragma once
#include <iostream>
using namespace std;


void mostrarArray(int* array, int tope){
    cout << "[";
    for(int i=0; i<tope-1; i++){
        cout << array[i] << ", ";
    }
    cout << array[tope-1] << "]" << endl;
}
#include <iostream>
using namespace std;


unsigned int valorAbsoluto(int num){
    return (num < 0) ? -num : num;
}

int max (int num1, int num2){
    return (num1 > num2) ? num1 : num2;
}

int min (int num1, int num2){
    return (num1 > num2) ? num2 : num1;
}
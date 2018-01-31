#include <iostream>

using namespace std;

int suma(int a, int b) {
    return a+b;
}

int resta(int a, int b) {
    return a-b;
}

int duplica(int a) {
    return a*2;
}

template <class T, class Function>
T doTemplateFunction(T a, T b, Function f) {
    return f(a, b);
}

// Muy genérico, puede recibir o devolver lo que quiera
template <class Function>
Function getTemplateFunction(char o) {
    if(o == 's') return suma;
    if(o == 'r') return resta;
    if(o == 'd') return duplica;
    return NULL;
}

int main() {
    cout << doTemplateFunction(2,2,suma) << endl;
    cout << getTemplateFunction<int (*)(int,int)>('s')(1,5) << endl;
    cout << getTemplateFunction<int (*)(int)>('d')(4) << endl;
    return 1;
}

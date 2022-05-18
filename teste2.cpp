#include "TS.h"
#include "TSArvoreBuscaBinaria.h"
#include <string>
#include <iostream>

int main(){
    TS<string, int> * dict;
    TSArvoreBuscaBinaria<string, int> ABB = TSArvoreBuscaBinaria<string, int>();

    dict = &ABB;

    dict->add("Opa", dict->value("Opa") + 1);

    cout << dict->value("Opa") << endl;

}
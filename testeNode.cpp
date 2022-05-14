#include <iostream>
#include <string>
#include "TSArvoreBuscaBinaria.h"

using namespace std;


int main(){

    Node<string, int> raiz;

    Node<string, int> * novo = nullptr;

    if(novo == nullptr){
        novo = new Node<string, int>("ola", 10, 1);
    }

    TSArvoreBuscaBinaria<string, int> dict = TSArvoreBuscaBinaria<string, int>();

    dict.add("ao", dict.value("ao") + 1);
    dict.add("verme", dict.value("verme") + 1);

    
}
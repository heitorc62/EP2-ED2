#include "TS.h"
#include "TSArvoreBuscaBinaria.h"
#include "TSTreap.h"
#include "TSArvore23.h"
#include "TSArvoreRubroNegra.h"
#include "TSVetorOrdenado.h"

#include <string>
#include <iostream>

int main(){
    TS<string, int> * dict;
    TSArvoreBuscaBinaria<string, int> ABB = TSArvoreBuscaBinaria<string, int>();
    TSTreap<string, int> Treap = TSTreap<string, int>();
    TSVetorOrdenado<string, int> VO = TSVetorOrdenado<string, int>();




    dict = &ABB;

    dict->add("Opa", dict->value("Opa") + 1);

    cout << dict->value("Opa") << endl;

    dict = &Treap;

    dict->add("salve", dict->value("salve"));

    cout << dict->value("salve") << endl;

    dict = &VO;

    dict->add("salve", dict->value("salve"));

    cout << dict->value("salve") << endl;

}
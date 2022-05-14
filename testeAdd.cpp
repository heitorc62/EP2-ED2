#include "TSArvore23.h"
#include "TSArvoreRubroNegra.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
    TSArvoreRubroNegra<int, int> dict = TSArvoreRubroNegra<int, int>();
    dict.add(35, dict.value(35) + 1);
    dict.add(33, dict.value(33) + 1);
    dict.add(8, dict.value(8) + 1);
    dict.add(30, dict.value(30) + 1);
    dict.add(42, dict.value(42) + 1);
    dict.add(31, dict.value(31) + 1);
    cout << "valor do 35 = " << dict.value(35) << endl;
    cout << "valor do 33 = " << dict.value(33) << endl;
    cout << "valor do 8 = " << dict.value(8) << endl;
    cout << "valor do 30 = " << dict.value(30) << endl;
    cout << "valor do 42 = " << dict.value(42) << endl;
    cout << "valor do 31 = " << dict.value(31) << endl;

}
#include "TSArvore23.h"
#include "TSArvoreRubroNegra.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
    TSArvore23<int, int> dict = TSArvore23<int, int>();
    dict.add(35, dict.value(35) + 1);
    dict.add(33, dict.value(33) + 1);
    dict.add(8, dict.value(8) + 1);
    dict.add(30, dict.value(30) + 1);
    dict.add(42, dict.value(42) + 1);
    dict.add(31, dict.value(31) + 1);
    cout << "rank do 8 = " << dict.rank(8) << endl;
    cout << "select " << dict.rank(8) << " = " << dict.select(dict.rank(8)) << endl;

    cout << "rank do 30 = " << dict.rank(30) << endl;
    cout << "select " << dict.rank(30) << " = " << dict.select(dict.rank(30)) << endl;

    cout << "rank do 31 = " << dict.rank(31) << endl;
    cout << "select " << dict.rank(31) << " = " << dict.select(dict.rank(31)) << endl;
    
    cout << "rank do 33 = " << dict.rank(33) << endl;
    cout << "select " << dict.rank(33) << " = " << dict.select(dict.rank(33)) << endl;
    
    cout << "rank do 35 = " << dict.rank(35) << endl;
    cout << "select " << dict.rank(35) << " = " << dict.select(dict.rank(35)) << endl;
    
    cout << "rank do 42 = " << dict.rank(42) << endl;
    cout << "select " << dict.rank(42) << " = " << dict.select(dict.rank(42)) << endl;
}
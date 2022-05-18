#include <iostream>
#include <cstdlib>
#include "TSTreap.h"

using namespace std;

int main(){
    double num = rand();
    TSTreap<string, int> dict = TSTreap<string, int>();
    dict.add("oi", 1);
    dict.add("oola", 1);
    dict.add("salve", 2);
}
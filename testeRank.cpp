#include "TSArvoreRubroNegra.h"
#include <string>

using namespace std;

int main(){
    TSArvoreRubroNegra<string, int> dict = TSArvoreRubroNegra<string, int>();
    dict.add("a", 1);
    dict.add("aa", 1);
    dict.add("aaa", 1);
    dict.add("aa", 1);
    dict.add("aaa", 1);
    dict.add("aa", 1);
    dict.add("aa", 1);
    dict.add("aaaa", 1);
    dict.add("aa", 1);
    dict.add("a", 1);
    dict.add("bbb", 1);
    dict.add("b", 1);
    dict.add("bbbbbb", 1);
    dict.add("aaaa", 1);
    dict.add("a", 1);
    dict.add("a", 1);
    dict.add("a", 1);
    dict.add("a", 1);
    dict.add("a", 1);
    dict.add("a", 1);
    cout << dict.rank("b") << endl;
}
#include <iostream>
#include <string>
#include "TSArvoreRubroNegra.h"

using namespace std;

int main(){
    TSArvoreRubroNegra<string, int> dict = TSArvoreRubroNegra<string, int>();

    cout << "vamos adicionar a palavra: " << "Lorem" << endl;
    dict.add("Lorem", dict.value("Lorem") + 1);
    
    cout << "Nesse momento temos: " << endl;
    dict.mostraArvore(dict.raiz);
    cout << endl << "Aqui temos os sizes: " << endl;
    dict.mostraSize(dict.raiz);
    cout << "\n\n\n";
    
    cout << "vamos adicionar a palavra: " << "ipsum" << endl;
    dict.add("ipsum", dict.value("ipsum") + 1);
    cout << "Nesse momento temos: " << endl;
    dict.mostraArvore(dict.raiz);
    cout << endl << "Aqui temos os sizes: " << endl;
    dict.mostraSize(dict.raiz);
    cout << "\n\n\n";

    cout << "vamos adicionar a palavra: " << "dolor" << endl;
    dict.add("dolor", dict.value("dolor") + 1);
    cout << "Nesse momento temos: " << endl;
    dict.mostraArvore(dict.raiz);
    cout << endl << "Aqui temos os sizes: " << endl;
    dict.mostraSize(dict.raiz);
    cout << "\n\n\n";

    cout << "vamos adicionar a palavra: " << "sit" << endl;
    dict.add("sit", dict.value("sit") + 1);
    cout << "Nesse momento temos: " << endl;
    dict.mostraArvore(dict.raiz);
    cout << endl << "Aqui temos os sizes: " << endl;
    dict.mostraSize(dict.raiz);
    cout << "\n\n\n";

    cout << "vamos adicionar a palavra: " << "amet" << endl;
    dict.add("amet", dict.value("amet") + 1);
    cout << "Nesse momento temos: " << endl;
    dict.mostraArvore(dict.raiz);
    cout << endl << "Aqui temos os sizes: " << endl;
    dict.mostraSize(dict.raiz);
    cout << "\n\n\n";

    cout << "vamos adicionar a palavra: " << "consectur" << endl;
    dict.add("consectur", dict.value("consectur") + 1);
    cout << "Nesse momento temos: " << endl;
    dict.mostraArvore(dict.raiz);
    cout << endl << "Aqui temos os sizes: " << endl;
    dict.mostraSize(dict.raiz);
    cout << "\n\n\n";

    cout << "vamos adicionar a palavra: " << "adipiscing" << endl;
    dict.add("adipiscing", dict.value("adipiscing") + 1);
    cout << "Nesse momento temos: " << endl;
    dict.mostraArvore(dict.raiz);
    cout << endl << "Aqui temos os sizes: " << endl;
    dict.mostraSize(dict.raiz);
    cout << "\n\n\n";

    cout << "vamos adicionar a palavra: " << "elit" << endl;
    dict.add("elit", dict.value("elit") + 1);
    cout << "Nesse momento temos: " << endl;
    dict.mostraArvore(dict.raiz);
    cout << endl << "Aqui temos os sizes: " << endl;
    dict.mostraSize(dict.raiz);
    cout << "\n\n\n";
}

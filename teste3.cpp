#include <iostream>
#include <vector>
#include <string>
#include "TSVetorOrdenado.h"
#include "TSArvoreBuscaBinaria.h"
#include "TSArvore23.h"
#include "TSArvoreRubroNegra.h"
#include "TSTreap.h"
#include "TS.h"

using namespace std;


int main(){

    TS<string, int> * dict;
    string tipo;
    tipo = "ABB";
    /*cout << "Insira o tipo da TS: " << endl;
    cin >> tipo;*/
    cout << "tipo = " << tipo << endl;
    if(tipo == "VO"){
        TSVetorOrdenado<string, int> VO = TSVetorOrdenado<string, int>();
        cout << "criamos vetor ordenado!" << endl;
        dict = &VO;

    }    
    else if(tipo == "ABB"){
        TSArvoreBuscaBinaria<string, int> ABB = TSArvoreBuscaBinaria<string, int>();
        cout << "criamos abb" << endl;
        dict = &ABB;
    }
    else if(tipo == "TR"){
        TSTreap<string, int> TR = TSTreap<string, int>();
        dict = &TR;
    }
    else if(tipo == "A23"){
        TSArvore23<string, int> A23 = TSArvore23<string, int>();
        dict = &A23;
    }
    else{
        TSArvoreRubroNegra<string, int> RN = TSArvoreRubroNegra<string, int>();
        dict = &RN;
    }

 

    int N;
    //N = 2;
    cout << "Insira a quantidade de palavras: " << endl;
    cin >> N;
    cout << "n de palavras: " << N << endl;

    dict->add("oi", dict->value("oi") + 1);
    cout << dict->value("oi") << endl;





  
/*    int cont = 0;
    int i = 0;
    string palavra;
    string palavras[N];

    string delimiters = ",.;:";

    cout << "oi" << endl;



    cout << "opa" << endl;

    while(cont < N){
        cin >> palavra;
        
        int aux2 = 0;
        while(delimiters.find(palavra[palavra.length() - (++aux2)]) != string::npos){
            palavra.pop_back();
        }
        
        palavras[cont] = palavra;
        cont++;
    }



    int Q;
    cin >> Q;
    int atual = 0;
    cont = 0;
    int next = 0;
    int op;
    string aux;
    while(cont < Q){
        cin >> op;
        cin >> aux;
        if(op == 1){
            next += stoi(aux);
            for(int i = atual; i < next; i++){
                cout << "vamos adicionar a palavra: " << palavras[i] << endl;
                dict->add(palavras[i], dict->value(palavras[i]) + 1);
                //cout << "Nesse momento temos: " << endl;
                //dict->mostraArvore(dict->raiz);
                //cout << "\n\n\n";
            }
            atual = next;
        }
        else if(op == 2){
            cout << dict->value(aux) << endl;
        }
        else if(op == 3){
            cout << dict->rank(aux) << endl;
        }
        else if(op == 4){
            int k = stoi(aux);
            cout << dict->select(k) << endl;
        }
        cont++;
    }*/
}

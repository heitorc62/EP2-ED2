#include <iostream>
#include <vector>
#include <string>
#include "TSVetorOrdenado.h"
#include "TSArvoreBuscaBinaria.h"
#include "TSArvore23.h"
#include "TSArvoreRubroNegra.h"
#include "TSTreap.h"

using namespace std;


int main(){

    string tipo;
    cin >> tipo;
    if(tipo == "VO"){
        cout << "criamos vetor ordenado" << endl;
        int N;
        cin >> N;
    
        TSVetorOrdenado<string, int> dict = TSVetorOrdenado<string, int>();

    
        int cont = 0;
        int i = 0;
        string palavra;
        string palavras[N];
        cout << "N = " << N << endl;

        string delimiters = ")(-,.;:";

        while(cont < N){
            cin >> palavra;

            int aux2 = 0;
            while(delimiters.find(palavra[palavra.length() - (++aux2)]) != string::npos){
                palavra.pop_back();
            }
            palavras[cont] = palavra;
            cont++;
        }
        int total = sizeof(palavras)/sizeof(palavras[0]);
        cout << "A quantidade de palavras no texto é: " << total  << endl;
        cout << "A ultima palavra lida foi: " << palavras[total - 1] << endl;

        int Q;
        cin >> Q;
        cout << "Quantidade de instruções: " << Q << endl;
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
                    //cout << "vamos adicionar a palavra: " << palavras[i] << endl;
                    dict.add(palavras[i], dict.value(palavras[i]) + 1);
                    //cout << "Nesse momento temos: " << endl;
                    //dict.mostraArvore(dict.raiz);
                    //cout << "\n\n\n";
                }
                atual = next;
            }
            else if(op == 2){
                cout << dict.value(aux) << endl;
            }
            else if(op == 3){
                cout << dict.rank(aux) << endl;
            }
            else if(op == 4){
                int k = stoi(aux);
                cout << dict.select(k) << endl;
            }
            cont++;
        }
        cout << "finalizou" << endl;
    }
    else if(tipo == "ABB"){
        cout << "criamos arvore de busca binaria" << endl;


        int N;
        cin >> N;

        TSArvoreBuscaBinaria<string, int> dict = TSArvoreBuscaBinaria<string, int>();

    
        int cont = 0;
        int i = 0;
        string palavra;
        string palavras[N];

        string delimiters = ",.;:";

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
                    //cout << "vamos adicionar a palavra: " << palavras[i] << endl;
                    dict.add(palavras[i], dict.value(palavras[i]) + 1);
                    //cout << "Nesse momento temos: " << endl;
                    //dict.mostraArvore(dict.raiz);
                    //cout << "\n\n\n";
                }
                atual = next;
            }
            else if(op == 2){
                cout << dict.value(aux) << endl;
            }
            else if(op == 3){
                cout << dict.rank(aux) << endl;
            }
            else if(op == 4){
                int k = stoi(aux);
                cout << dict.select(k) << endl;
            }
            cont++;
        }
    }
    else if(tipo == "TR"){
        cout << "criamos treap" << endl;
        int N;
        cin >> N;
        TSTreap<string, int> dict = TSTreap<string, int>();

    
        int cont = 0;
        int i = 0;
        string palavra;
        string palavras[N];

        string delimiters = ",.;:";

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
                    //cout << "vamos adicionar a palavra: " << palavras[i] << endl;
                    dict.add(palavras[i], dict.value(palavras[i]) + 1);
                    //cout << "Nesse momento temos: " << endl;
                    //dict.mostraArvore(dict.raiz);
                    //cout << "\n\n\n";
                }
                atual = next;
            }
            else if(op == 2){
                cout << dict.value(aux) << endl;
            }
            else if(op == 3){
                cout << dict.rank(aux) << endl;
            }
            else if(op == 4){
                int k = stoi(aux);
                cout << dict.select(k) << endl;
            }
            cont++;
        }
    }
    else if(tipo == "A23"){
        cout << "criamos arvore23" << endl;
        int N;
        cin >> N;
    
        TSArvore23<string, int> dict = TSArvore23<string, int>();

    
        int cont = 0;
        int i = 0;
        string palavra;
        string palavras[N];

        string delimiters = ",.;:";

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
                    //cout << "vamos adicionar a palavra: " << palavras[i] << endl;
                    dict.add(palavras[i], dict.value(palavras[i]) + 1);
                    //cout << "Nesse momento temos: " << endl;
                    //dict.mostra(dict.raiz, true);
                    //cout << "\n\n\n";
                }
                atual = next;
            }
            else if(op == 2){
                cout << dict.value(aux) << endl;
            }
            else if(op == 3){
                cout << dict.rank(aux) << endl;
            }
            else if(op == 4){
                int k = stoi(aux);
                cout << dict.select(k) << endl;
            }
            cont++;
        }
    }
    else{
        cout << "criamos arvore rubro negra" << endl;
        int N;
        cin >> N;
        
        TSArvoreRubroNegra<string, int> dict = TSArvoreRubroNegra<string, int>();

    
        int cont = 0;
        int i = 0;
        string palavra;
        string palavras[N];

        string delimiters = ",.;:";

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
                    //cout << "vamos adicionar a palavra: " << palavras[i] << endl;
                    dict.add(palavras[i], dict.value(palavras[i]) + 1);
                    //cout << "Nesse momento temos: " << endl;
                    //dict.mostraArvore(dict.raiz);
                    //cout << "\n\n\n";
                }
                atual = next;
            }
            else if(op == 2){
                cout << dict.value(aux) << endl;
            }
            else if(op == 3){
                cout << dict.rank(aux) << endl;
            }
            else if(op == 4){
                int k = stoi(aux);
                cout << dict.select(k) << endl;
            }
            cont++;
        }
    }  
}

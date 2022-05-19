#ifndef ARVORERUBRONEGRA_H
#define ARVORERUBURONEGRA_H
#include "TS.h"

#include <iostream>
#include <string>

using namespace std;

template <class Key, class Item>
class NodeRN : public Node<Key, Item>{
    public:
    NodeRN(){};
    NodeRN(Key key, Item val, char cor, NodeRN * pai);
    NodeRN * pai;
    NodeRN * esq;
    NodeRN * dir;
    Key key;
    Item val;
    char cor;
    int N;  // número de nós da subárvore cuja raiz é este nó.
};



template <class Key, class Item>
NodeRN<Key, Item>::NodeRN(Key key, Item val, char cor, NodeRN<Key, Item> * pai){
    this->pai = pai;
    this->cor = cor;
    this->val = val;
    this->key = key;
}


template <class Key, class Item>
class TSArvoreRubroNegra : public TS<Key, Item>{
    private:
    NodeRN<Key, Item> * putRN(NodeRN<Key, Item> * raiz, Key key, Item val);
    NodeRN<Key, Item> * raiz;
    NodeRN<Key, Item> * rodaEsq(NodeRN<Key, Item> * raiz);
    NodeRN<Key, Item> * rodaDir(NodeRN<Key, Item> * raiz);
    Item get(NodeRN<Key, Item> * raiz, Key key);
    int size();
    int size(NodeRN<Key, Item> * raiz);
    Key select(NodeRN<Key, Item> * raiz, int k);
    int rank(NodeRN<Key, Item> * raiz, Key key);
    void mostraArvore(NodeRN<Key, Item> * raiz);

    
    public:
    void add(Key key, Item val);
    Item value(Key key);
    int rank(Key key);
    Key select(int k);

};

template <class Key, class Item>
void TSArvoreRubroNegra<Key, Item>::mostraArvore(NodeRN<Key, Item> * raiz){
    if(raiz == nullptr) return;
    if(raiz->pai == nullptr) cout << "raiz = " << raiz->key << endl;
    else cout << raiz->key << endl;
    if(raiz->esq != nullptr){
        cout << "filho esquerdo de " << raiz->key << " = ";
        mostraArvore(raiz->esq);
    } 
    if(raiz->dir != nullptr){
        cout << "filho direito de " << raiz->key << " = ";
        mostraArvore(raiz->dir);
    }
}

template <class Key, class Item>
int TSArvoreRubroNegra<Key, Item>::size(){
    return size(raiz);
}

template <class Key, class Item>
int TSArvoreRubroNegra<Key, Item>::size(NodeRN<Key, Item> * raiz){
    if(raiz == nullptr) return 0;
    return raiz->N;
}

template <class Key, class Item>
Key TSArvoreRubroNegra<Key, Item>::select(int k){
    return select(raiz, k);
}

template <class Key, class Item>
Key TSArvoreRubroNegra<Key, Item>::select(NodeRN<Key, Item> * raiz, int k){
    if(raiz == nullptr) return Key();
    int t = size(raiz->esq);
    //cout << "oi" << endl;
    if(k > t){
        return select(raiz->dir, k - t - 1);
    }
    else if(k < t){
        return select(raiz->esq, k);
    }
    else return raiz->key;
}

template <class Key, class Item>
int TSArvoreRubroNegra<Key, Item>::rank(Key key){
    return rank(raiz, key);
}

template <class Key, class Item>
int TSArvoreRubroNegra<Key, Item>::rank(NodeRN<Key, Item> * raiz, Key key){
    if(key < raiz->key) return rank(raiz->esq, key);
    else if(key > raiz->key) return 1 + size(raiz->esq) + rank(raiz->dir, key);
    else return size(raiz->esq);
}

template <class Key, class Item>
Item TSArvoreRubroNegra<Key, Item>::value(Key key){
    return get(raiz, key);
}

template <class Key, class Item>
Item TSArvoreRubroNegra<Key, Item>::get(NodeRN<Key, Item> * raiz, Key key){
    if(raiz == nullptr) return Item();
    if(raiz->key == key) return raiz->val;
    if(raiz->key > key) return get(raiz->esq, key);
    return get(raiz->dir, key);
}

template <class Key, class Item>
NodeRN<Key, Item> * TSArvoreRubroNegra<Key, Item>::rodaEsq(NodeRN<Key, Item> * r){
    NodeRN<Key, Item> * q = r->dir;
    if(q == nullptr) return r;
    if(r->pai != nullptr) r->pai->dir = q;
    q->pai = r->pai;
    r->dir = q->esq;
    r->pai = q;
    q->esq = r;
    r->N = size(r->esq) + size(r->dir) + 1;
    q->N = size(q->esq) + size(q->dir) + 1;
    if(r->dir != nullptr) r->dir->pai = r;
    return q;
}

template <class Key, class Item>
NodeRN<Key, Item> * TSArvoreRubroNegra<Key, Item>::rodaDir(NodeRN<Key, Item> * q){
    NodeRN<Key, Item> * r = q->esq;
    if(q->pai != nullptr) q->pai->esq = r;
    r->pai = q->pai;
    q->pai = r;
    q->esq = r->dir;
    r->dir = q;
    q->N = size(q->dir) + size(q->esq) + 1;
    r->N = size(r->esq) + size(r->dir) + 1;     
    if(q->esq != nullptr) q->esq->pai = q;
    return r;
}

template <class Key, class Item>
void TSArvoreRubroNegra<Key, Item>::add(Key key, Item val){
    raiz = putRN(raiz, key, val);
}

template <class Key, class Item>
NodeRN<Key, Item> *  TSArvoreRubroNegra<Key, Item>::putRN(NodeRN<Key, Item> * raiz, Key key, Item val){
    if(raiz == nullptr){
        raiz = new NodeRN<Key, Item>(key, val, 'r', nullptr);
        return raiz;
    }

    NodeRN<Key, Item> * p = raiz;
    bool achou = false;
    while(!achou){
        if(p->key == key){
            p->val = val;
            return raiz;
        }
        else if((p->key > key) && (p->esq != nullptr)){
            p = p->esq;
        }
        else if((p->key > key) && (p->esq == nullptr)){
            achou = true;
        }
        else if((p->key < key) && (p->dir != nullptr)){
            p = p->dir;
        }
        else if((p->key < key) && (p->dir == nullptr)){
            achou = true;
        }
    }
    NodeRN<Key, Item> * novo = new NodeRN<Key, Item>(key, val, 'r', p);
    NodeRN<Key, Item> * filho = novo;
    if(key < p->key) p->esq = filho;
    else p->dir = filho;
    while(true){
        if(p->cor == 'b') break;
        NodeRN<Key, Item> * avo = p->pai;
        if(avo == nullptr){
            p->cor = 'b';
            break;
        }
        // Avô é preto
        NodeRN<Key, Item> * tio = new NodeRN<Key, Item>();
        if(p == avo->esq) tio = avo->dir;
        else tio = avo->esq;
        if((tio != nullptr) && (tio->cor == 'r')){
            avo->cor = 'r';
            p->cor = tio->cor = 'b';
            filho = avo;
            p = avo->pai;
            if(p == nullptr) break;
        }
        // tio é nullptr ou tio é preto
        else{
            if(p == avo->esq && filho == p->esq){
                NodeRN<Key, Item> * q = rodaDir(avo);
                q->cor = 'b';
                avo->cor = 'r';
                if(raiz == avo) raiz = q;
                break;
            }
            else if(p == avo->esq && filho == p->dir){
                NodeRN<Key, Item> * q = rodaEsq(p);
                NodeRN<Key, Item> * r = rodaDir(avo);
                r->cor = 'b';
                avo->cor = 'r';
                if(raiz == avo) raiz = r;
                break;
            }
            else if(p == avo->dir && filho == p->dir){
                NodeRN<Key, Item> * q = rodaEsq(avo);
                q->cor = 'b';
                avo->cor = 'r';
                if(raiz == avo) raiz = q;
                break;
            }
            else{
                NodeRN<Key, Item> * q = rodaDir(p);
                NodeRN<Key, Item> * r = rodaEsq(avo);
                r->cor = 'b';
                avo->cor = 'r';
                if(raiz == avo) raiz = r;
                break;
            }
        }
    }
    raiz->N = size(raiz->esq) + size(raiz->dir) + 1;
    return raiz;
}







#endif
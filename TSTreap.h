#ifndef TSTREAP_H
#define TSTREAP_H

#include <cstdlib>
#include <iostream>
#include "TS.h"

using namespace std;

template<class Key, class Item>
class NodeTR : public Node<Key, Item>{
    public:
    NodeTR(){};
    NodeTR(Key key, Item val, int N, NodeTR * pai);
    Key key;
    Item val;
    NodeTR * pai;
    NodeTR * esq;
    NodeTR * dir;
    int priority;
    int N;
};
template <class Key, class Item>
NodeTR<Key, Item>::NodeTR(Key key, Item val, int N, NodeTR * pai){
    this->key = key;
    this->val = val;
    this->N = N;
    this->pai = pai;
    priority = rand()% 10;
}


template <class Key, class Item>
class TSTreap : public TS<Key, Item>{
    private:
    NodeTR<Key, Item> * put(NodeTR<Key, Item> * raiz, Key key, Item val, NodeTR<Key, Item> * pai);
    Item get(NodeTR<Key, Item> * no, Key key);
    int size(NodeTR<Key, Item> * raiz);
    int rankAux(NodeTR<Key, Item> * raiz, Key key);
    NodeTR<Key, Item> * selectAux(NodeTR<Key, Item> * raiz, int k);
    NodeTR<Key, Item> * ajustaPrioridade(NodeTR<Key, Item> * ultimo);
    NodeTR<Key, Item> * ultimo;
    NodeTR<Key, Item> * rodaDir(NodeTR<Key, Item> * q);
    NodeTR<Key, Item> * rodaEsq(NodeTR<Key, Item> * r);

    public:
    NodeTR<Key, Item> * raiz = nullptr;
    void mostraArvore(NodeTR<Key, Item> * raiz);
    void add(Key key, Item val);
    Item value(Key key);
    int rank(Key key);
    Key select(int k);
};

template<class Key, class Item>
Key TSTreap<Key, Item>::select(int k){
    return selectAux(raiz, k)->key;
}

template<class Key, class Item>
NodeTR<Key, Item> * TSTreap<Key, Item>::selectAux(NodeTR<Key, Item> * raiz, int k){
    if(raiz == nullptr) return nullptr;  // provavelmente vai dar pau.
    int t = size(raiz->esq);
    if(k == t) return raiz;
    else if(k > t) return selectAux(raiz->dir, k - t - 1);
    return selectAux(raiz->esq, k);
}


template<class Key, class Item>
int TSTreap<Key, Item>::rank(Key key){
    return rankAux(raiz, key);
}

template <class Key, class Item>
int TSTreap<Key, Item>::rankAux(NodeTR<Key, Item> * raiz, Key key){
    if(raiz == nullptr) return 0;
    if(raiz->key == key) return size(raiz->esq);
    if(raiz->key > key) return rankAux(raiz->esq, key);    
    return 1 + size(raiz->esq) + rankAux(raiz->dir, key);
}


template <class Key, class Item>
Item TSTreap<Key, Item>::value(Key key){
    return get(raiz, key);
}

template<class Key, class Item>
Item TSTreap<Key, Item>::get(NodeTR<Key, Item> * no, Key key){
    if(no == nullptr) return Item();
    if(no->key == key) return no->val;
    if(no->key > key) return get(no->esq, key);
    return get(no->dir, key);
}

template<class Key, class Item>
int TSTreap<Key, Item>::size(NodeTR<Key, Item> * raiz){
    if(raiz == nullptr) return 0;
    return raiz->N;
}

template <class Key, class Item>
NodeTR<Key, Item> * TSTreap<Key, Item>::rodaDir(NodeTR<Key, Item> * q){
    if(q == nullptr) return q;
    if(q->esq == nullptr) return q;
    NodeTR<Key, Item> * r = q->esq;
    if(q->pai != nullptr){
        if(q->pai->esq != nullptr && q->key == q->pai->esq->key) q->pai->esq = r;
        else q->pai->dir = r; 
    }
    r->pai = q->pai;
    q->pai = r;
    q->esq = r->dir;
    r->dir = q;
    q->N = size(q->dir) + size(q->esq) + 1;
    r->N = size(r->dir) + size(r->esq) + 1;
    if(q->esq != nullptr) q->esq->pai = q;
    return r;
}

template <class Key, class Item>
NodeTR<Key, Item> * TSTreap<Key, Item>::rodaEsq(NodeTR<Key, Item> * r){
    if(r == nullptr) return r;
    if(r->dir == nullptr) return r;
    NodeTR<Key, Item> * q = r->dir;
    if(r->pai != nullptr){
        if(r->pai->esq != nullptr && r->key == r->pai->esq->key) r->pai->esq = q;
        else r->pai->dir = q;
    }
    q->pai = r->pai;
    r->pai = q;
    r->dir = q->esq;
    q->esq = r;
    r->N = size(r->dir) + size(r->esq) + 1;
    q->N = size(q->dir) + size(q->esq) + 1;
    if(r->dir != nullptr) r->dir->pai = r;
    return q;
}


template <class Key, class Item>
NodeTR<Key, Item> * TSTreap<Key, Item>::ajustaPrioridade(NodeTR<Key, Item> * ultimo){
    //cout << "\n\n estamos ajustando " << ultimo->key << "\n\n" << endl;
    if(ultimo->pai == nullptr){
        // A raiz é o ultimo.  
        return ultimo;
    }
    if(ultimo->pai->esq != nullptr && ultimo->key == ultimo->pai->esq->key){
        if(ultimo->priority > ultimo->pai->priority){
            NodeTR<Key, Item> * novo = rodaDir(ultimo->pai);
            return ajustaPrioridade(novo);
        }
        //Não mudamos a árvore, a raiz é a mesma.
        else return raiz;
    }
    if(ultimo->pai->dir != nullptr && ultimo->key == ultimo->pai->dir->key){
        if(ultimo->priority > ultimo->pai->priority){
            NodeTR<Key, Item> * novo = rodaEsq(ultimo->pai);
            return ajustaPrioridade(novo);
        }
        // Não mudamos a árvore, a raiz é a mesma.
        else return raiz;
    }
    return raiz;
}

template <class Key, class Item>
void TSTreap<Key, Item>::mostraArvore(NodeTR<Key, Item> * raiz){
    if(raiz == nullptr) return;
    if(raiz->pai == nullptr) cout << "raiz = " << raiz->key << " p = " << raiz->priority << endl;
    else cout << raiz->key << " p = " << raiz->priority << endl;
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
void TSTreap<Key, Item>::add(Key key, Item val){
    raiz = put(raiz, key, val, nullptr);
    /*cout << "vamos ajustar " << ultimo->key << "; p = " << ultimo->priority << endl;
    /*cout << "antes de ajustar: " << endl;
    mostraArvore(raiz);
    cout << "\n\n\n";*/
    raiz = ajustaPrioridade(ultimo);
    /*cout << "depois de ajustar: " << endl;
    mostraArvore(raiz);
    cout << "\n\n\n";*/
}

template <class Key, class Item>
NodeTR<Key, Item> * TSTreap<Key, Item>::put(NodeTR<Key, Item> * raiz, Key key, Item val, NodeTR<Key, Item> * pai){
    if(raiz == nullptr){
        raiz = new NodeTR<Key, Item>(key, val, 1, pai);
        ultimo = raiz;
        return raiz;
    }
    if(raiz->key == key){
        raiz->val = val;
    }
    else if(raiz->key > key){
        raiz->esq = put(raiz->esq, key, val, raiz);
    }
    else{
        raiz->dir = put(raiz->dir, key, val, raiz);
    }
    raiz->N = size(raiz->esq) + size(raiz->dir) + 1;
    return raiz;
}



#endif
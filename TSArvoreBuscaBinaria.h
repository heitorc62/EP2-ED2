#include "TS.h"
#include <iostream>

using namespace std;

#ifndef TSARVOREBUSCABINARIA_H
#define TSARVOREBUSCABINARIA_H

using namespace std;

template<class Key, class Item>
class NodeABB : public Node<Key, Item>{
    public:
    NodeABB(){};
    NodeABB(Key key, Item val, int N);
    Key key;
    Item val;
    NodeABB * esq;
    NodeABB * dir;
    int N;
};
template <class Key, class Item>
NodeABB<Key, Item>::NodeABB(Key key, Item val, int N){
    this->key = key;
    this->val = val;
    this->N = N;
}


template <class Key, class Item>
class TSArvoreBuscaBinaria : public TS<Key, Item>{
    private:
    NodeABB<Key, Item> * raiz = nullptr;
    NodeABB<Key, Item> * put(NodeABB<Key, Item> * raiz, Key key, Item val);
    Item get(NodeABB<Key, Item> * no, Key key);
    int size(NodeABB<Key, Item> * raiz);
    int rankAux(NodeABB<Key, Item> * raiz, Key key);
    NodeABB<Key, Item> * selectAux(NodeABB<Key, Item> * raiz, int k);

    public:
    void add(Key key, Item val);
    Item value(Key key);
    int rank(Key key);
    Key select(int k);
};

template<class Key, class Item>
Key TSArvoreBuscaBinaria<Key, Item>::select(int k){
    return selectAux(raiz, k)->key;
}

template<class Key, class Item>
NodeABB<Key, Item> * TSArvoreBuscaBinaria<Key, Item>::selectAux(NodeABB<Key, Item> * raiz, int k){
    if(raiz == nullptr) return nullptr;  // provavelmente vai dar pau.
    int t = size(raiz->esq);
    if(k == t) return raiz;
    else if(k > t) return selectAux(raiz->dir, k - t - 1);
    return selectAux(raiz->esq, k);
}


template<class Key, class Item>
int TSArvoreBuscaBinaria<Key, Item>::rank(Key key){
    return rankAux(raiz, key);
}

template <class Key, class Item>
int TSArvoreBuscaBinaria<Key, Item>::rankAux(NodeABB<Key, Item> * raiz, Key key){
    if(raiz == nullptr) return 0;
    if(raiz->key == key) return size(raiz->esq);
    if(raiz->key > key) return rankAux(raiz->esq, key);    
    return 1 + size(raiz->esq) + rankAux(raiz->dir, key);
}


template <class Key, class Item>
Item TSArvoreBuscaBinaria<Key, Item>::value(Key key){
    return get(raiz, key);
}

template<class Key, class Item>
Item TSArvoreBuscaBinaria<Key, Item>::get(NodeABB<Key, Item> * no, Key key){
    if(no == nullptr) return Item();
    if(no->key == key) return no->val;
    if(no->key > key) return get(no->esq, key);
    return get(no->dir, key);
}

template<class Key, class Item>
int TSArvoreBuscaBinaria<Key, Item>::size(NodeABB<Key, Item> * raiz){
    if(raiz == nullptr) return 0;
    return raiz->N;
}


template <class Key, class Item>
void TSArvoreBuscaBinaria<Key, Item>::add(Key key, Item val){
    raiz = put(raiz, key, val);
}

template <class Key, class Item>
NodeABB<Key, Item> * TSArvoreBuscaBinaria<Key, Item>::put(NodeABB<Key, Item> * raiz, Key key, Item val){
    if(raiz == nullptr){
        raiz = new NodeABB<Key, Item>(key, val, 1);
        return raiz;
    }
    if(raiz->key == key){
        raiz->val = val;
    }
    else if(raiz->key > key){
        raiz->esq = put(raiz->esq, key, val);
    }
    else{
        raiz->dir = put(raiz->dir, key, val);
    }
    raiz->N = size(raiz->esq) + size(raiz->dir) + 1;
    return raiz;
}



#endif
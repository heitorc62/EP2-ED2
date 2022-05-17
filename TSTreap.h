#ifndef TSTREAP_H
#define TSTREAP_H

#include <cstdlib>

using namespace std;

template<class Key, class Item>
class NodeTR{
    public:
    NodeTR(){};
    NodeTR(Key key, Item val, int N);
    Key key;
    Item val;
    NodeTR * esq;
    NodeTR * dir;
    int priority;
    int N;
};
template <class Key, class Item>
NodeTR<Key, Item>::NodeTR(Key key, Item val, int N){
    this->key = key;
    this->val = val;
    this->N = N;
    priority = rand();
}


template <class Key, class Item>
class TSTreap{
    private:
    NodeTR<Key, Item> * raiz = nullptr;
    NodeTR<Key, Item> * put(NodeTR<Key, Item> * raiz, Key key, Item val);
    Item get(NodeTR<Key, Item> * no, Key key);
    int size(NodeTR<Key, Item> * raiz);
    int rankAux(NodeTR<Key, Item> * raiz, Key key);
    NodeTR<Key, Item> * selectAux(NodeTR<Key, Item> * raiz, int k);
    NodeTR<Key, Item> * ajustaPrioridade(NodeTR<Key, Item> * raiz);

    public:
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
void TSTreap<Key, Item>::add(Key key, Item val){
    raiz = put(raiz, key, val);
    ajustaPrioridade(raiz);
}

template <class Key, class Item>
NodeTR<Key, Item> * TSTreap<Key, Item>::put(NodeTR<Key, Item> * raiz, Key key, Item val){
    if(raiz == nullptr){
        raiz = new NodeTR<Key, Item>(key, val, 1);
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
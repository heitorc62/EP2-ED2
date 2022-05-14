#ifndef TSARVORE23_H
#define TSARVORE23_H
#include <iostream>

using namespace std;



template <class Key, class Item>
class Node23{
    public:
    Node23(){};
    Node23(Key key, Item val, bool ehDoisNo);

    Key key1;
    Item val1;
 
    Key key2;
    Item val2;

    Node23 * ap1;   // Aponta para os menores que key1
    Node23 * ap2;   // Aponta para os entre key1 e key2
    Node23 * ap3;   // Aponta para os maiores que key2

    bool ehDoisNo;

    bool ehFolha();

    int N;
};

template <class Key, class Item>
Node23<Key, Item>::Node23(Key key, Item val, bool ehDoisNo){
    key1 = key;
    val1 = val;
    this->ehDoisNo = ehDoisNo;
}

template <class Key, class Item>
bool Node23<Key, Item>::ehFolha(){
    return (ap1 == nullptr && ap2 == nullptr && ap3 == nullptr);
}


template <class Key, class Item>
class TSArvore23{
    private:
    Node23<Key, Item> * raiz;
    Node23<Key, Item> * put23(Node23<Key, Item> * raiz, Key key, Item val, bool &cresceu);
    bool cresceu;
    Item get(Node23<Key, Item> * raiz, Key key);
    
    public:
    void add(Key key, Item val);
    Item value(Key key);
    int rank(Key key);
    Key select(int k);
};

template <class Key, class Item>
Item TSArvore23<Key, Item>::value(Key key){
    return get(raiz, key);
}

template <class Key, class Item>
Item TSArvore23<Key, Item>::get(Node23<Key, Item> * raiz, Key key){
    if(raiz == nullptr) return Item();
    if(raiz->ehDoisNo){
        if(raiz->key1 == key) return raiz->val1;
        if(raiz->key1 > key) return get(raiz->ap1, key);
        if(raiz->key1 < key) return get(raiz->ap3, key);
    }
    else{
        if(raiz->key1 == key) return raiz->val1;
        if(raiz->key2 == key) return raiz->val2;
        if(raiz->key1 > key) return get(raiz->ap1, key);
        if(raiz->key2 > key && key > raiz->key1) return get(raiz->ap2, key);
        if(raiz->key2 < key) return get(raiz->ap3, key);
    }
}

template <class Key, class Item>
void TSArvore23<Key, Item>::add(Key key, Item val){
    raiz = put23(raiz, key, val, cresceu);
}

template <class Key, class Item>
Node23<Key, Item> * TSArvore23<Key, Item>::put23(Node23<Key, Item> * raiz, Key key, Item val, bool &cresceu){
    if(raiz == nullptr){
        raiz = new Node23<Key, Item>(key, val, true);
        return raiz;
    }
    if(raiz->ehFolha()){          // Caso base da recursão.
        if(raiz->ehDoisNo){      // Tem espaço pra colocar key no nó.
            if(raiz->key1 == key){
                raiz->val1 = val;
            }
            else if(raiz->key1 > key){
                raiz->key2 = raiz->key1;
                raiz->val2 = raiz->val1;
                raiz->key1 = key;
                raiz->val1 = val;
                raiz->ehDoisNo = false;
            }
            else{
                raiz->key2 = key;
                raiz->val2 = val;
                raiz->ehDoisNo = false;
            }
            cresceu = false;
            return raiz;
        }
        // A folha é 3Nó, então vai acontecer split.
        else{
            Node23<Key, Item> * novaRaiz = new Node23<Key, Item>();
            Node23<Key, Item> * novo = new Node23<Key, Item>();
            if(raiz->key2 == key){
                raiz->val2 = val;
                cresceu = false;
                return raiz;
            }
            else if(raiz->key1 == key){
                raiz->key1 = key;
                raiz->val1 = val;
                cresceu = false;
                return raiz;
            }
            else if(raiz->key1 > key){  // key é o menor dos três
                novaRaiz->key1 = raiz->key1;
                novaRaiz->val1 = raiz->val1;
                raiz->key1 = key;
                raiz->val1 = val;
                novo->key1 = raiz->key2;
                novo->val1 = raiz->val2;
            }
            else if(raiz->key2 > key && key > raiz->key1){  // key está no meio
                novo->key1 = raiz->key2;
                novo->val1 = raiz->val2;
                novaRaiz->key1 = key;
                novaRaiz->val1 = val;
            }
            else{  // key é o maior dos três
                novo->key1 = key;
                novo->val1 = val;
                novaRaiz->key1 = raiz->key2;
                novaRaiz->val1 = raiz->val2;
            }
            novo->ehDoisNo = novaRaiz->ehDoisNo = raiz->ehDoisNo = true;
            novaRaiz->ap1 = raiz;
            novaRaiz->ap3 = novo;
            cresceu = true;
            return novaRaiz;
        }
    }
    // Saímos do caso base
    if(raiz->key1 > key){
        Node23<Key, Item> * p = put23(raiz->ap1, key, val, cresceu);
        // Colocamos uma key na árvore.
        if(cresceu){
            // Agora, se a árvore cresceu, teremos que balancear.
            if(raiz->ehDoisNo){
                raiz->key2 = raiz->key1;
                raiz->val2 = raiz->val1;
                raiz->key1 = p->key1;
                raiz->val1 = p->val1;
                raiz->ap1 = p->ap1;
                raiz->ap2 = p->ap3;
                raiz->ehDoisNo = false;
                cresceu = false;
                delete p;
                return raiz;
            }
            else{
                Node23<Key, Item> * novaRaiz = new Node23<Key, Item>();
                novaRaiz->key1 = raiz->key1;
                novaRaiz->val1 = raiz->val1;
                novaRaiz->ap1 = p;
                novaRaiz->ap3 = raiz;

                raiz->key1 = raiz->key2;
                raiz->val1 = raiz->val2;
                raiz->ap1 = raiz->ap2;

                novaRaiz->ehDoisNo = raiz->ehDoisNo = p->ehDoisNo = true;
                cresceu = true;
                return novaRaiz;
            }        
        }
        else{
            // Se não cresceu, então a árvore já está balanceada.
            return raiz;
        }
    }
    if(key > raiz->key2){
        Node23<Key, Item> * p = put23(raiz->ap3, key, val, cresceu);
        if(cresceu){
            if(raiz->ehDoisNo){
                raiz->ehDoisNo = false;
                raiz->key2 = p->key1;
                raiz->val2 = p->val1;
                raiz->ap2 = p->ap1;
                raiz->ap3 = p->ap3;
                delete p;
                cresceu = false;
                return raiz;
            }
            else{
                Node23<Key, Item> * novaRaiz = new Node23<Key, Item>();
                novaRaiz->key1 = raiz->key2;
                novaRaiz->val1 = raiz->val2;
                
                raiz->ap3 = raiz->ap2;

                novaRaiz->ap1 = raiz;
                novaRaiz->ap3 = p;

                novaRaiz->ehDoisNo = p->ehDoisNo = raiz->ehDoisNo = true;
                cresceu = true;
                return novaRaiz;
            }
        }
        else{
            return raiz;
        }
    }
    if((!raiz->ehDoisNo) && (raiz->key2 > key) && (key > raiz->key1)){
        Node23<Key, Item> * p = put23(raiz->ap2, key, val, cresceu);
        if(cresceu){
            Node23<Key, Item> * novaRaiz = new Node23<Key, Item>();
            novaRaiz->key1 = p->key1;
            novaRaiz->val1 = p->val1;
            
            novaRaiz->ap2 = p->ap1;     // Usando como variável auxiliar
            
            p->key1 = raiz->key2;
            p->val1 = raiz->val2;
            p->ap1 = p->ap3;
            p->ap3 = raiz->ap3;

            raiz->ap3 = novaRaiz->ap2;  // Recuperando o valor armazenado na variável auxiliar
            
            novaRaiz->ap1 = raiz;
            novaRaiz->ap3 = p;

            novaRaiz->ehDoisNo = p->ehDoisNo = raiz->ehDoisNo = true;
            cresceu = true;
            return novaRaiz;
        }
        else{
            return raiz;
        }
    }
}





#endif
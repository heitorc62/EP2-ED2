#ifndef TSVETORORDENADO_H
#define TSVETORORDENADO_H

using namespace std;


template <class Key, class Item> 
class parChaveValor{
    public:
    parChaveValor(){};
    parChaveValor(Key key, Item val);
    Key key;
    Item val;
};
 
template <class Key, class Item>
parChaveValor<Key, Item>::parChaveValor(Key key, Item val){
    this->key = key;
    this->val = val;
}


template <class Key, class Item>
class TSVetorOrdenado{
    private:
    int tam;
    int n;
    parChaveValor<Key, Item> * v;

    public:
    TSVetorOrdenado();
    ~TSVetorOrdenado();
    void add(Key key, Item val);
    Item value(Key key);
    int rank(Key key);
    Key select(int k);
    void resize();
    void show(int n);

};

template <class Key, class Item>
TSVetorOrdenado<Key, Item>::TSVetorOrdenado(): v(new parChaveValor<Key, Item>[1]), n(0), tam(1) {};

template <class Key, class Item>
TSVetorOrdenado<Key, Item>::~TSVetorOrdenado() {
    if (v != nullptr) delete [] v;
}


template <class Key, class Item>
int TSVetorOrdenado<Key, Item>::rank(Key key){  // Busca binária para encontrar o rank
    int lo = 0, hi = n - 1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(v[mid].key == key)
            return mid;
        if(v[mid].key < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}


template <class Key, class Item>
void TSVetorOrdenado<Key, Item>::add(Key key, Item item){
    int r = rank(key);     // Número de elementos da TS menores que key
    if(r < n && v[r].key == key){   // Checa se o elemento já está na TS.
        v[r].val = item;
        return;
    }
    if(n == tam) resize();  // Se não está, vamos inserir.
    for(int j = n; j > r; j--){
        v[j] = v[j - 1];   // Libera o espaço no vetor.
    }
    v[r].key = key;
    v[r].val = item;
    n++;
    
}

template<class Key, class Item>
Item TSVetorOrdenado<Key, Item>::value(Key key){
    int r = rank(key);
    if(r < n && v[r].key == key)
        return v[r].val;
    return Item();
}

template <class Key, class Item>
Key TSVetorOrdenado<Key, Item>::select(int k){
    if(k >= 0 && k < n) return v[k].key;
    return Key();
}

template <class Key, class Item>
void TSVetorOrdenado<Key, Item>::resize(){
    parChaveValor<Key, Item> * newV = new parChaveValor<Key, Item>[2*tam];
    for (int i = 0; i < tam; i++)
        newV[i] = v[i];
    delete [] v;
    v = newV;
    tam = 2*tam;
}


template<class Key, class Item>
void TSVetorOrdenado<Key, Item>::show(int n){
    for(int i = 0; i < n; i++){
        cout << v[i].key << endl;
    }
}



#endif

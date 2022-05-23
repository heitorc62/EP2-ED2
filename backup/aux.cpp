#include <bits/stdc++.h>
#include "TSVetorOrdenado.h"
#include "TSArvoreBuscaBinaria.h"
#include "TSArvore23.h"
#include "TSArvoreRubroNegra.h"
#include "TSTreap.h"

using namespace std;


int main(){

    string tipo;
    cin >> tipo;
    cout << "tipo = " << tipo << endl;
    string opaopa = "VO";
    cout << tipo << " = " << opaopa << " " << (tipo.compare(opaopa)) << endl;
    cout << tipo << " = " << opaopa << " " << (tipo == opaopa) << endl;
}
#include <iostream>
#include "arvoreBinariaBusca.h"
using namespace std;

int main(){
    Arv_bin * arv = abb_cria();

    //------------Atividade 01------------
    abb_insere(arv, 50); abb_insere(arv, 30);
    abb_insere(arv, 70); abb_insere(arv, 20);
    abb_insere(arv, 40); abb_insere(arv, 60);
    abb_insere(arv, 80); abb_insere(arv, 15);
    abb_insere(arv, 25); abb_insere(arv, 35);
    abb_insere(arv, 45); abb_insere(arv, 36);

    arv_imprime(arv);
    abb_remove(arv, 30);
    arv_imprime(arv);

    //------------Atividade 02------------
    abb_insere(arv, 30);
    arv_imprime(arv);
    abb_remove_sucessor(arv, 30);
    arv_imprime(arv);

    //------------Atividade 03------------
    cout << "A arvore e binaria de busca? " << check_arvBusca(arv->raiz) << endl;

    //------------Atividade 04------------
    cout << "Maior valor: " << abb_maior_valor(arv) << endl;

    //------------Atividade 05------------
    cout << "Menor valor: " << abb_menor_valor(arv) << endl;

    //------------Atividade 06------------

    return 0;
}
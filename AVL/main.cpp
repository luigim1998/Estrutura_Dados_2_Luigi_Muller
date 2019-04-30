#include <iostream>
#include "AVL.h"
using namespace std;

int main(){
    Avl * arv = cria_arv();
    Nodo * aux;
    arv_inserir(arv,  50);
    arv_inserir(arv,  25);
    arv_inserir(arv,  75);
    arv_inserir(arv,  12);
    arv_inserir(arv,   6);
    arv_inserir(arv,  90);
    arv_inserir(arv, 100);
    arv_inserir(arv, 120);
    arv_inserir(arv, 110);
    arv_inserir(arv,   3);
    arv_inserir(arv,   5);

    arv_remover(arv, 50);

    cout << "Pre-ordem: ";
    arv_imprime_pre_ordem(arv->raiz);
    cout << "\nIn-ordem: ";
    arv_imprime_in_ordem(arv->raiz);
    cout << "\nPos-ordem: ";
    arv_imprime_pos_ordem(arv->raiz);
    cout << endl;

    aux = arv_busca(arv, 100);
    if(aux == NULL) cout << -1 << endl;
    else  cout << aux->info << endl;

    aux = arv_busca(arv, 20);
    if(aux == NULL) cout << -1 << endl;
    else  cout << aux->info << endl;

    aux = arv_busca(arv, 6);
    if(aux == NULL) cout << -1 << endl;
    else  cout << aux->info << endl;
    return 0;
}
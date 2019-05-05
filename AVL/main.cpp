#include <iostream>
#include "AVL.h"
using namespace std;

/*
 * Função de criar a árvore: cria_arv();
 * Função de inserção: Arv_inserir();
 * Função de remoção: Arv_remover();
 * Função de busca: Arv_busca();
 * Função de impressão em pre-ordem: Arv_imprime_pre_ordem();
 * Função de impressão em in-ordem: Arv_imprime_in_ordem();
 * Função de impressão em pos-ordem: Arv_imprime_pos_ordem();
 */
int main(){
    Avl * arv = cria_arv();
    Nodo * aux;

    Arv_inserir(arv, 100);
    Arv_inserir(arv,  50);
    Arv_inserir(arv,  35);
    Arv_inserir(arv,  25);
    Arv_inserir(arv,  30);
    Arv_inserir(arv, 150);
    Arv_inserir(arv, 200);
    Arv_inserir(arv, 250);
    Arv_inserir(arv, 220);
    Arv_inserir(arv, 270);

    Arv_remover(arv, 250);
    Arv_remover(arv, 270);

    cout << "Pre-ordem: ";
    Arv_imprime_pre_ordem(arv->raiz);
    cout << "\nIn-ordem: ";
    Arv_imprime_in_ordem(arv->raiz);
    cout << "\nPos-ordem: ";
    Arv_imprime_pos_ordem(arv->raiz);
    cout << endl;

    aux = Arv_busca(arv, 100);
    if(aux == NULL) cout << -1 << endl;
    else  cout << aux->info << endl;

    aux = Arv_busca(arv, 20);
    if(aux == NULL) cout << -1 << endl;
    else  cout << aux->info << endl;

    aux = Arv_busca(arv, 6);
    if(aux == NULL) cout << -1 << endl;
    else  cout << aux->info << endl;
    return 0;
}
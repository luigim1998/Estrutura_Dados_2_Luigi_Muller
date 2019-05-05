#include <iostream>
#include "arvore.h"
using namespace std;

/*
 * Função de criar a árvore: cria_arvore();
 * Função de inserção: Insert();
 * Função de remoção: Arv_remove();
 * Função de busca: Arv_busca();
 * Função de impressão em pre-ordem: Arv_imprime_pre_ordem();
 * Função de impressão em in-ordem: Arv_imprime_in_ordem();
 * Função de impressão em pos-ordem: Arv_imprime_pos_ordem();
 */
int main() {
    ArvRN * arv = cria_arvore();

    Insert(arv, cria_nodo(150));
    Insert(arv, cria_nodo(120));
    Insert(arv, cria_nodo(170));
    Insert(arv, cria_nodo(100));
    Insert(arv, cria_nodo(110));
    Insert(arv, cria_nodo(160));
    Insert(arv, cria_nodo(155));
    Insert(arv, cria_nodo(135));
    Insert(arv, cria_nodo(185));
    Insert(arv, cria_nodo(200));
    Insert(arv, cria_nodo(158));
    Insert(arv, cria_nodo(156));

    Arv_remove(arv, 200);

    cout << Arv_busca(arv, 158)->chave << endl;

    if(Arv_busca(arv, 158) != NULL) cout << -1 << endl;
    else cout << Arv_busca(arv, 158)->chave << endl;

    return 0;
}
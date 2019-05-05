#include <iostream>
#include "arvore.h"
using namespace std;

/*
 * Função de criar a árvore: Arv_cria();
 * Função de inserção: Arv_insere();
 * Função de remoção: Arv_remove();
 * Função de busca: Arv_busca();
 */

int Nodo_Busca(Nodo * r, int k){
    if(r == NULL)
        return -1;
    else {
        int i = 0;
        while(i < r->quant){
            if(r->chave[i] == k){
                return i;
            }
        }
        if(i == r->quant) return -1;

    }
}

int main() {
    ArvB * arv = Arv_cria();

    Arv_insere(arv, 100);
    Arv_insere(arv, 120);
    Arv_insere(arv, 80);
    Arv_insere(arv, 50);
    Arv_insere(arv, 140);
    Arv_insere(arv, 200);

    Nodo * aux = Arv_busca(arv->raiz, 120);

    if(aux != NULL) cout << aux->chave[Nodo_Busca(aux, 120)] << endl;
    else cout << -1 << endl;

    return 0;
}
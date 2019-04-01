#include "arvoreBinariaBusca.h"
#include <iostream>
using namespace std;

Arv_bin * abb_cria(){
    Arv_bin * arv = new Arv_bin;
    arv->raiz = NULL;
    return arv;
}

void arv_imprime(Arv_bin * arv){
    arv_imprime_no(arv->raiz);
}

void arv_imprime_no(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_no(raiz->esq);
        cout << raiz->info << endl;
        arv_imprime_no(raiz->dir);
    }
}

void arv_libera(Arv_bin * arv){
    arv_libera_no(arv->raiz);
    delete arv;
}
void arv_libera_no(Nodo * raiz){
    if(raiz!=NULL){
        arv_libera_no(raiz->esq);
        arv_libera_no(raiz->dir);
        delete raiz;
    }
}

Nodo * arv_busca_no(Nodo *raiz, int n){
    if(raiz==NULL || raiz->info == n)
        return raiz;
    if (n < raiz->info)
        return arv_busca_no(raiz->esq, n);
    else
        return arv_busca_no(raiz->dir, n);
}

Nodo * arv_busca_no_iter(Nodo * raiz, char c){
    while(raiz != NULL && raiz->info != c){
        if(c<raiz->info)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    }
    return raiz;
}

void abb_insere(Arv_bin *arv, int n){
    arv->raiz = insere_no(arv->raiz, n);
}

Nodo * insere_no(Nodo *raiz, int n){
    if(raiz == NULL){
        raiz = new Nodo;
        raiz->info = n;
        raiz->esq = raiz->dir = NULL;
    } else if (n < raiz->info)
        raiz->esq = insere_no(raiz->esq, n);
    else
        raiz->dir = insere_no(raiz->dir, n);
    return raiz;
}

void abb_remove(Arv_bin *arv, int n){
    arv->raiz = remove_no(arv->raiz, n);
}

Nodo * remove_no(Nodo *raiz, int n){
    if(raiz == NULL)
        return NULL;
    else if(n < raiz->info)
        raiz->esq = remove_no(raiz->esq, n);
    else if(n > raiz->info)
        raiz->dir = remove_no(raiz->dir, n);
    else{
        //nodo não tem filhos
        if(raiz->esq == NULL && raiz->dir == NULL) {
            delete raiz;
            raiz = NULL;
        }
        //só tem o filho à direita
        else if(raiz->esq == NULL){
            Nodo * aux = raiz;
            raiz = raiz->dir;
            delete aux;
        }
        //só tem o filho à direita
        else if(raiz->dir == NULL) {
            Nodo *aux = raiz;
            raiz = raiz->esq;
            delete aux;
        }
        //tem dois filhos
        else {
            Nodo * aux = raiz->esq;
            while(aux->dir != NULL){
                aux = aux->dir;
            }
            /*troca as informações da raiz com
             * o nodo mais à direita da sae*/
            raiz->info = aux->info;
            aux->info = n;
            raiz->esq = remove_no(raiz->esq, n);
        }
    }
}
/**
 * Ela escolhe o sucessor de n para substituir seu local
 * @param arv Ponteiro da Arvore
 * @param n valor de Busca
 */
void abb_remove_sucessor(Arv_bin *arv, int n){
    arv->raiz = remove_no(arv->raiz, n);
}

Nodo * remove_no_sucessor(Nodo *raiz, int n){
    if(raiz == NULL)
        return NULL;
    else if(n < raiz->info)
        raiz->esq = remove_no_sucessor(raiz->esq, n);
    else if(n > raiz->info)
        raiz->dir = remove_no_sucessor(raiz->dir, n);
    else{
        //nodo não tem filhos
        if(raiz->esq == NULL && raiz->dir == NULL) {
            delete raiz;
            raiz = NULL;
        }
        //só tem o filho à direita
        else if(raiz->esq == NULL){
            Nodo * aux = raiz;
            raiz = raiz->dir;
            delete aux;
        }
        //só tem o filho à esquerda
        else if(raiz->dir == NULL) {
            Nodo *aux = raiz;
            raiz = raiz->esq;
            delete aux;
        }
        //tem dois filhos
        else {
            Nodo * aux = raiz->dir;
            while(aux->esq != NULL){
                aux = aux->esq;
            }
            /*troca as informações da raiz com
             * o nodo mais à direita da sae*/
            raiz->info = aux->info;
            aux->info = n;
            raiz->dir = remove_no_sucessor(raiz->dir, n);
        }
    }
    return raiz;
}

bool check_arvBusca(Nodo *raiz){
    if (raiz == NULL){
        return true;
    }
    if (raiz->dir == NULL){
        return check_arvBusca(raiz->esq);
    }
    if (raiz->esq == NULL){
        return check_arvBusca(raiz->dir);
    }
    if (raiz->info > raiz->dir->info){
        return false;
    }
    if (raiz->info < raiz->esq->info){
        return false;
    }
    else{
        return check_arvBusca(raiz->esq) && check_arvBusca(raiz->dir);
    }
}

int abb_maior_valor(Arv_bin * arv){
    return abb_maior_valor_no(arv->raiz);
}

int abb_maior_valor_no(Nodo * raiz){
    if(raiz->dir != NULL) return abb_maior_valor_no(raiz->dir);
    else return raiz->info;
}

int abb_menor_valor(Arv_bin * arv){
    Nodo * aux = new Nodo;
    if(arv == NULL) return 0;
    aux = arv->raiz;
    if(aux == NULL) return 0;

    while(aux->esq != NULL){
        aux = aux->esq;
    }
    return aux->info;
}
/**
 * Retorna a quantidade de nodos incluindo o que está no parâmetro.
 * @param raiz
 * @return Quantidade de nodos.
 */
int quant_nos(Nodo * raiz){
    if(raiz == NULL){
        return 0;
    } else {
        return 1 + quant_nos(raiz->esq) + quant_nos(raiz->dir);
    }
}

int arv_busca_k_valor(Arv_bin * arv, int k){
    return arv_busca_k_valor_no(arv->raiz, k);
}

int arv_busca_k_valor_no(Nodo * raiz, int k){
    int esquerda = quant_nos(raiz->esq);
    int direita = quant_nos(raiz->dir);
    if(esquerda <= k) //ele está na sae
        return arv_busca_k_valor_no(raiz->esq, k);
    else if(esquerda + 1 == k)
        return raiz->info; //é a raiz
    else if(esquerda + direita + 1 <= k) //ele está na sad
        return arv_busca_k_valor_no(raiz->dir, k - esquerda - 1);
}
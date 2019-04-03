#include "arvoreBinariaBusca.h"
#include <iostream>
#include <stdlib.h>
#include <queue>
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
    return raiz;
}
/**
 * Ela escolhe o sucessor de n para substituir seu local
 * @param arv Ponteiro da Arvore
 * @param n valor de Busca
 */
void abb_remove_sucessor(Arv_bin *arv, int n){
    arv->raiz = remove_no_sucessor(arv->raiz, n);
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

Nodo * arv_busca_k_valor_no(Nodo * raiz, int * k){
    Nodo * retorno = NULL, *entrada = NULL;

    if(raiz->esq != NULL){
        entrada = arv_busca_k_valor_no(raiz->esq, k);
        if (entrada != NULL){
            retorno = entrada;
        }
    }
    --(*k);
    if((*k) == 0){
       retorno = raiz;
    }
    if(raiz->dir != NULL){
        entrada = arv_busca_k_valor_no(raiz->dir, k);
        if (entrada != NULL){
            retorno = entrada;
        }
    }
    return retorno;

    /*int esquerda = quant_nos(raiz->esq);
    int direita = quant_nos(raiz->dir);
    if(esquerda <= k) //ele está na sae
        return arv_busca_k_valor_no(raiz->esq, k);
    else if(esquerda + 1 == k)
        return raiz->info; //é a raiz
    else if(esquerda + direita + 1 <= k) //ele está na sad
        return arv_busca_k_valor_no(raiz->dir, k - esquerda - 1);
        */
}

/**
 * Busca o k-ésimo menor valor da árvore.
 * @param arv Árvore binária;
 * @param k Valor k para a busca;
 * @return Resultado da busca ou 0 caso não esteja.
 */
Nodo * arv_busca_k_valor(Arv_bin * arv, int k){
    return arv_busca_k_valor_no(arv->raiz, &k);
}

bool arv_iguais(Arv_bin * arv1, Arv_bin * arv2){
    return arv_iguais_no(arv1->raiz, arv2->raiz);
}

bool arv_iguais_no(Nodo * raiz1, Nodo * raiz2){
    if(raiz1 == NULL){
        if(raiz2 == NULL){
            return true;
        } else { //raiz2 != NULL, uma raiz é nula e a outra não
            return false;
        }
    } else { //raiz1 != NULL
        if(raiz2 == NULL){ //uma raiz é nula e a outra não
            return false;
        } else { //raiz2 != NULL, ambas as raízes tem conteúdo
            if(raiz1->info == raiz2->info){
                return arv_iguais_no(raiz1->esq, raiz2->esq) &&
                       arv_iguais_no(raiz1->dir, raiz2->dir);
            } else { //não é igual
                return false;
            }
        }
    }
}

int quant_um_filho(Arv_bin * arv){
    return quant_um_filho_no(arv->raiz);
}

int quant_um_filho_no(Nodo * raiz){
    if(raiz->esq == NULL){
        if(raiz->dir == NULL){ //ambos são nulos
            return 0;
        } else { //raiz->dir != NULL, uma raiz é nula e a outra não
            return 1 + quant_um_filho_no(raiz->dir);
        }
    } else { //raiz->esq != NULL
        if(raiz->dir == NULL){ //uma raiz é nula e a outra não
            return 1 + quant_um_filho_no(raiz->esq);
        } else { //raiz->dir != NULL, ambas as raízes tem conteúdo
            return 0 + quant_um_filho_no(raiz->esq) + quant_um_filho_no(raiz->dir);
        }
    }
}

Arv_bin * constroi_arv(queue<int> * entrada){
    int cont, aux = 0;
    Arv_bin * arv = abb_cria();
    while(!(entrada->empty())){
        abb_insere(arv, entrada->front());
        entrada->pop();
    }
    return arv;
}

/**
 * Essa função retorna true caso essa subsequencia exista na árvore. Aviso: ele ignora quaisquer valores que possam estar entre essa subsequencia.
 * @param arv
 * @param fila
 * @param tamanho
 * @return
 */
bool arv_subsequencia(Arv_bin * arv, queue<int> * fila, int tamanho){
    queue<Nodo *> aux;
    while(!fila->empty()){
        aux.push(arv_busca_no(arv->raiz, fila->front()) );
        fila->pop();
    }
    while(!aux.empty()){
        if(aux.front() == NULL) return false;
        aux.pop();
    }
    return true;
}
#include "AVL.h"
#include <stdlib.h>

Nodo * inserir(Nodo * raiz, int k){
    if(raiz == NULL)
        return novo_nodo(k);

    if(k < raiz->info)
        raiz->esq = inserir(raiz->esq, k);
    else if(k > raiz->info)
        raiz->dir = inserir(raiz->dir, k);
    else
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
    int fator_balanceamento = calcular_fator_balanceamento(raiz);
    //LLC
    if(fator_balanceamento < -1 && k < raiz->esq->info)
        return dirRotate(raiz);
    //RRC
    if(fator_balanceamento > 1 && k > raiz->dir->info)
        return esqRotate(raiz);
    //LRC
    if(fator_balanceamento < -1 && k > raiz->esq->info){
        raiz->esq = esqRotate(raiz->esq);
        return dirRotate(raiz);
    }
    //RLC
    if(fator_balanceamento > 1 && k < raiz->dir->info){
        raiz->dir = dirRotate(raiz->dir);
        return esqRotate(raiz);
    }
    return raiz; //não precisa rotacionar
}

int altura(Nodo * p){
    if(p == NULL) return -1;
    return p->altura;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

Nodo * novo_nodo(int info){
    Nodo * novo = new Nodo;
    novo->info = info;
    novo->esq = NULL;
    novo ->dir = NULL;
    novo->altura = 0;
    return novo;
}

Nodo * dirRotate(Nodo * y) {
    Nodo *x = y->esq;
    Nodo *T2 = x->dir;

    x->dir = y;
    x->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

Nodo * esqRotate(Nodo * x){
    Nodo * y = x->dir;
    Nodo * T2 = y->dir;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

int calcular_fator_balanceamento(Nodo * r){
    if(r == NULL)
        return 0;
    return altura(r->dir) - altura(r->esq);
}

Nodo * remover(Nodo * raiz, int k){
    if(raiz == NULL)
        return NULL;
    else if(k < raiz->info)
        raiz->esq = remover(raiz->esq, k);
    else if(k > raiz->info)
        raiz->dir = remover(raiz->dir, k);
    else{
        //nodo não tem filho
        if(raiz->esq == NULL && raiz->dir == NULL){
            delete raiz;
            raiz = NULL;
        }//só tem o filho à direita
        else if(raiz->esq == NULL){
            Nodo * aux = raiz;
            raiz = raiz->dir;
            delete aux;
        }//só tem o filho à esquerda
        else if(raiz->dir == NULL){
            Nodo * aux = raiz;
            raiz = raiz->esq;
            delete aux;
        }//só tem o filho à direita
        else {
            Nodo *aux = raiz->esq;
            while (aux->dir != NULL) {
                aux = aux->dir;
            }//troca as informações da raiz com o nodo mais à direita da sae
            raiz->info = aux->info;
            aux->info = k;
            raiz->esq = remover(raiz->esq, k);
        }
    }
    if(raiz == NULL)
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int fator_balanceamento = calcular_fator_balanceamento(raiz);

    if(fator_balanceamento < -1 && calcular_fator_balanceamento(raiz->esq) <= 0)
        return dirRotate(raiz);
    if(fator_balanceamento < -1 && calcular_fator_balanceamento(raiz->esq) > 0){
        raiz->esq = esqRotate(raiz->esq);
        return dirRotate(raiz);
    }
    if(fator_balanceamento > 1 && calcular_fator_balanceamento(raiz->dir) >= 0)
        return dirRotate(raiz);
    if(fator_balanceamento > 1 && calcular_fator_balanceamento(raiz->dir) < 0){
        raiz->dir = dirRotate(raiz->dir);
        return esqRotate(raiz);
    }
    return raiz;
}
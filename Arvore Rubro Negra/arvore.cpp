#include "arvore.h"
#include <iostream>
using namespace std;

ArvRN * cria_arvore(){
    ArvRN * arv = new ArvRN;
    arv->nil = new Nodo;
    arv->nil->color = NEGRO;
    arv->raiz = arv->nil;
}

Nodo * cria_nodo(int v){
    Nodo * aux = new Nodo;
    aux->chave = v;
    aux->color = VERMELHO;
    aux->esq = aux->dir = aux->pai = NULL;
    return aux;
}

void Insert(ArvRN * T, Nodo * z){
    Nodo * y = T->nil;
    Nodo * x = T->raiz;
    while(x != T->nil) {
        y = x;
        if (z->chave < x->chave) {
            x = x->esq;
        } else {
            x = x->dir;
        }
    }
    z->pai = y;
    if(y == T->nil){ //ele eh a raiz
        T->raiz = z;
    } else if(z->chave < y->chave){ //z eh menor que a chave y
        y->esq = z;
    } else {
        y->dir = z;
    }
    z->esq = T->nil;
    z->dir = T->nil;
    z->color = VERMELHO;
    Insert_Fixup(T, z);
}

void Insert_Fixup(ArvRN * T, Nodo * z){
    Nodo * y;//recebe  o tio
    while(z->pai->color == VERMELHO){
        if(z->pai == z->pai->pai->esq){//pai esta a esquerda do avo
            y = z->pai->pai->dir;
            if(y->color == VERMELHO){//caso 1: pai e tio eh vermelho
                z->pai->color = NEGRO;
                y->color = NEGRO;
                z->pai->pai->color = VERMELHO;
                z = z->pai->pai;
            } else {//tio é preto
                if (z == z->pai->dir) {//caso 2: tio preto e z filho direito
                    z = z->pai;
                    LeftRot(T, z);
                }
                z->pai->color = NEGRO;//caso 3: tio preto e z filho esquerdo
                z->pai->pai->color = VERMELHO;
                RightRot(T, z->pai->pai);
            }
        } else {//pai esta a direita do avo
            y = z->pai->pai->esq;
            if(y->color == VERMELHO){//caso 1: pai e tio eh vermelho
                z->pai->color = NEGRO;
                y->color = NEGRO;
                z->pai->pai->color = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->esq) {//caso 2: tio preto e z filho direito
                    z = z->pai;
                    RightRot(T, z);
                }
                z->pai->color = NEGRO;//caso 3: tio preto e z filho esquerdo
                z->pai->pai->color = VERMELHO;
                LeftRot(T, z->pai->pai);
            }
        }
    }
    T->raiz->color = NEGRO;
}

void LeftRot(ArvRN * T, Nodo * x){
    Nodo * y = x->dir;
    x->dir = y->esq;//sad de x recebe sae de y
    if(y->esq != T->nil)//se y->esq nao for nil, seu  pai e o x
        y->esq->pai = x;//o pai de y->esq e o x
    y->pai = x->pai;//o pai de y recebe o pai de x, ja que ele vira a raiz
    if(x->pai == T->nil)//então ele é a raiz
        T->raiz = y;
    else if(x == x->pai->esq)//se x estiver na esquerda do seu pai
        x->pai->esq = y;
    else//se x estiver na direita do seu pai
        x->pai->dir = y;
    y->esq = x;
    x->pai = y;
}

void RightRot(ArvRN * T, Nodo * x){
    Nodo * y = x->esq;
    x->esq = y->dir;//sae de x recebe sad de y
    if(y->dir != T->nil)//se y->dir nao for nil, seu  pai e o x
        y->dir->pai = x;//o pai de y->dir e o x
    y->pai = x->pai;//o pai de y recebe o pai de x, ja que ele vira a raiz
    if(x->pai == T->nil)//então ele é a raiz
        T->raiz = y;
    else if(x == x->pai->dir)//se x estiver na direita do seu pai
        x->pai->dir = y;
    else//se x estiver na esquerda do seu pai
        x->pai->esq = y;
    y->dir = x;
    x->pai = y;
}

void Transplante(ArvRN *T, Nodo *u, Nodo *v){
    if(u->pai == T->nil)//ele é raiz
        T->raiz = v;
    else if (u == u->pai->esq)//se ele for o filho a esquerda do pai
        u->pai->esq = v;
    else//se ele for o filho a direita do pai
        u->pai->dir = v;
    v->pai = u->pai;//ele recebe o pai
}

Nodo * Arv_busca(ArvRN * T, int k){
    if(T->raiz == T->nil){
        return T->nil;
    } else {
        return busca(T, T->raiz, k);
    }
}

Nodo * busca(ArvRN *T, Nodo *raiz, int k){
    if(raiz == T->nil){//ele não achou o valor pois chegou no nil
        return T->nil;
    } else {
        if(k < raiz->chave){
            return busca(T, raiz->esq, k);
        } else if(k > raiz->chave){
            return busca(T, raiz->dir, k);
        } else {
            return raiz;
        }
    }
}

void Arv_remove(ArvRN * T, int k){
    Nodo * aux = Arv_busca(T, k);
    if(aux != T->nil && T->raiz != T->nil){//remove caso o k exista e a arvore não seja vazia
        Remove(T, aux);
    }
}

void Remove(ArvRN *T, Nodo *z){
    Nodo * y = z;
    Nodo * x;
    Cor y_original_color = y->color;
    if(z->esq == T->nil){//pega o nodo da direita
        x = z->dir;
        Transplante(T, z, z->dir);
    } else if(z->dir == T->nil){//pega o nodo da esquerda
        x = z->esq;
        Transplante(T, z, z->esq);
    } else {//ele tem dois filhos
        y = Arv_minimo(T, z->dir);//recebe o sucessor
        y_original_color = y->color;//recebe a cor
        x = y->dir;//recebe o nodo a direita, não há nodo a esquerda
        if(y->pai == z) {//se z for pai de y
            x->pai = y;
        } else {//se z não for pai de y
            Transplante(T, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        Transplante(T, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->color = z->color;
    }
    if (y_original_color == NEGRO)
        Remove_fixup(T, x);
}

void Remove_fixup(ArvRN * T, Nodo * x){
    Nodo * w;
    while(x != T->raiz && x->color == NEGRO){
        if(x == x->pai->esq) {//está a esquerda do pai
            w = x->pai->dir;//recebe o irmão
            if (w->color == VERMELHO) {//irmão é vermelho
                w->color = NEGRO;
                x->pai->color = VERMELHO;
                LeftRot(T, x->pai);
                w = x->pai->dir;
            }
            if (w->esq->color == NEGRO && w->dir->color == NEGRO) {
                w->color = VERMELHO;
                x = x->pai;
            } else {
                if (w->dir->color == NEGRO) {
                    w->esq->color = NEGRO;
                    w->color = VERMELHO;
                    RightRot(T, w);
                    w = x->pai->dir;
                }
                w->color = x->pai->color;
                x->pai->color = NEGRO;
                w->dir->color = NEGRO;
                LeftRot(T, x->pai);
                x = T->raiz;
            }
        } else {
            w = x->pai->esq;
            if (w->color == VERMELHO) {
                w->color = NEGRO;
                x->pai->color = VERMELHO;
                RightRot(T, x->pai);
                w = x->pai->esq;
            }
            if (w->dir->color == NEGRO && w->esq->color == NEGRO) {
                w->color = VERMELHO;
                x = x->pai;
            } else {
                if (w->esq->color == NEGRO) {
                    w->dir->color = NEGRO;
                    w->color = VERMELHO;
                    LeftRot(T, w);
                    w = x->pai->esq;
                }
                w->color = x->pai->color;
                x->pai->color = NEGRO;
                w->esq->color = NEGRO;
                RightRot(T, x->pai);
                x = T->raiz;
            }
        }
    }
    x->color = NEGRO;
}

Nodo * Arv_minimo(ArvRN * T, Nodo * raiz){
    while(raiz->esq != T->nil){
        raiz = raiz->esq;
    }
    return raiz;
}

void Arv_imprime_pre_ordem(ArvRN *T, Nodo *raiz) {
    if(raiz != T->nil){
        cout << raiz->chave << " ";
        Arv_imprime_pre_ordem(T, raiz->esq);
        Arv_imprime_pre_ordem(T, raiz->dir);
    }
}

void Arv_imprime_in_ordem(Nodo *raiz){
    if(raiz != NULL){
        Arv_imprime_in_ordem(raiz->esq);
        cout << raiz->chave << " ";
        Arv_imprime_in_ordem(raiz->dir);
    }
}

void Arv_imprime_pos_ordem(Nodo *raiz){
    if(raiz != NULL){
        Arv_imprime_pos_ordem(raiz->esq);
        Arv_imprime_pos_ordem(raiz->dir);
        cout << raiz->chave << " ";
    }
}
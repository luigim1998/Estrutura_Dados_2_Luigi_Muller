#include "arvore.h"

ArvRN * cria_arvore(){
    ArvRN * arv = new ArvRN;
    arv->nil = new Nodo;
    arv->nil->color = NEGRO;
    arv->raiz = arv->nil;
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
    Nodo * y;
    while(z->pai->color == VERMELHO){
        if(z->pai == z->pai->pai->esq){//pai esta a esquerda do avo
            y = z->pai->pai->dir;
            if(y->color == VERMELHO){//tio eh vermelho
                z->pai->color = NEGRO;
                y->color = NEGRO;
                z->pai->pai->color = VERMELHO;
                z = z->pai->pai;
            } else if (z == z->pai->dir){//tio preto e z filho direito
                z = z->pai;
                LeftRot(T, z);
                z->pai->color = NEGRO;//tio preto e z filho esquerdo
                z->pai->pai->color = VERMELHO;
                RightRot(T, z->pai->pai);
            } else{//tio preto e z filho esquerdo
                z->pai->color = NEGRO;
                z->pai->pai->color = VERMELHO;
                RightRot(T, z->pai->pai);
            }
        } else {//pai esta a direita do avo
            y = z->pai->pai->esq;
            if(y->color == VERMELHO){//tio eh vermelho
                z->pai->color = NEGRO;
                y->color = NEGRO;
                z->pai->pai->color = VERMELHO;
                z = z->pai->pai;
            } else if (z == z->pai->esq){//tio preto e z filho direito
                z = z->pai;
                RightRot(T,z);
                z->pai->color = NEGRO;//tio preto e z filho esquerdo
                z->pai->pai->color = VERMELHO;
                LeftRot(T, z->pai->pai);
            } else {//tio preto e z filho esquerdo
                z->pai->color = NEGRO;
                z->pai->pai->color = VERMELHO;
                LeftRot(T, z->pai->pai);
            }
        }
    }
    T->raiz->color = NEGRO;
}

void LeftRot(ArvRN * T, Nodo * x){
    Nodo * y = x->dir;
    x->dir = y->esq;
    if(y->esq != T->nil)
        y->esq->pai = x;
    y->pai = x->pai;
    if(x->pai == T->nil)
        T->raiz = y;
    else if(x == x->pai->esq)
        x->pai->esq = y;
    else
        x->pai->dir = y;
    y->esq = x;
    x->pai = y;
}

void RightRot(ArvRN * T, Nodo * x){
    Nodo * y = x->esq;
    x->esq = y->dir;
    if(y->dir != T->nil)
        y->dir->pai = x;
    y->pai = x->pai;
    if(x->pai == T->nil)
        T->raiz = y;
    else if(x == x->pai->dir)
        x->pai->dir = y;
    else
        x->pai->esq = y;
    y->dir = x;
    x->pai = y;
}
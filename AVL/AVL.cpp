#include "AVL.h"

int altura(Node * r){
    if(r == NULL)
        return -1;
    return r->alt;
}

Node * new_node(int k){
    Node * p = new Node;
    p->info = k;
    p->alt = 0;
    p->esq = p->dir = NULL;
    return p;
}

int fb_node(Node * r){
    if(r == NULL)
        return 0;
    return altura(r->dir) - altura(r->esq);
}

int max(int a, int b){
    return a > b ? a : b;
}

Node * insere(Node * r, int k){
    if(r == NULL)
        return new_code(k);
    else if(k < r->info)
        r->esq = insere(r->esq, k);
    else if(k > r->info)
        r->dir = insere(r->dir, k);
    else
        return r;
    r->alt = 1 + max(altura(r->esq), altura(r->dir));
    int fb = fb_node(r);
    //LLC
    if(fb < -1 && k < r->esq->info)
        return rightRot(r);
    //LRC
    if(fb < -1 && k > r->esq->info) {
        r->esq = leftRot(r->esq);
        return rightRot(r);
    }
    //RRC
    if(fb > 1 && k > r->dir->info)
        return leftRot(r);
    //RLC
    if(fb > 1 && k < r->dir->info){
        r->dir = rightRot(r->dir);
        return leftRot(r);
    }
    return r; //não precisa rotacionar
}
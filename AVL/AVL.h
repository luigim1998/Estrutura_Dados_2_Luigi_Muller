#ifndef AVL_H
#define AVL_H

typedef struct nodo{
    int info;
    nodo * esq;
    nodo * dir;
    int altura;
}Nodo;

typedef struct arv_avl{
    Nodo * raiz;
}Avl;

Avl *  cria_arv();
void   Arv_inserir(Avl *arv, int k);
Nodo * inserir(Nodo * raiz, int k);
int    altura(Nodo * p);
int    max(int a, int b);
Nodo * novo_nodo(int info);
Nodo * dirRotate(Nodo * x);
Nodo * esqRotate(Nodo * x);
int    calcular_fator_balanceamento(Nodo * r);
void   Arv_remover(Avl *arv, int k);
Nodo * remover(Nodo * raiz, int k);
Nodo * Arv_busca(Avl *arv, int k);
Nodo * busca(Nodo *raiz, int k);
void   Arv_imprime_pre_ordem(Nodo *raiz);
void   Arv_imprime_in_ordem(Nodo *raiz);
void   Arv_imprime_pos_ordem(Nodo *raiz);

#endif //AVL_AVL_H

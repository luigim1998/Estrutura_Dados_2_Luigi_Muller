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

Avl * cria_arv();
void arv_inserir(Avl * arv, int k);
Nodo * inserir(Nodo * raiz, int k);
int altura(Nodo * p);
int max(int a, int b);
Nodo * novo_nodo(int info);
Nodo * dirRotate(Nodo * x);
Nodo * esqRotate(Nodo * x);
int calcular_fator_balanceamento(Nodo * r);
void arv_remover(Avl * arv, int k);
Nodo * remover(Nodo * raiz, int k);

#endif //AVL_AVL_H

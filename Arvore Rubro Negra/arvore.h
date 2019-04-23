#ifndef ARVORE_H
#define ARVORE_H

typedef enum {VERMELHO, NEGRO}Cor;

typedef struct node{
    Cor color;
    int chave;
    node * esq;
    node * dir;
    node * pai;
}Nodo;

typedef struct ArvRubNeg{
    node * raiz;
    node * nil;
}ArvRN;

ArvRN * cria_arvore();
Nodo * cria_nodo(int v);
void Insert(ArvRN * T, Nodo * z);
void Insert_Fixup(ArvRN * T, Nodo * z);
void RightRot(ArvRN * T, Nodo * x);
void LeftRot(ArvRN * T, Nodo * x);

#endif //ARVORE_RUBRO_NEGRA_ARVORE_H

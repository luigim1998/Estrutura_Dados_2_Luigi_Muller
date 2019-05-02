#ifndef ARVORE_H
#define ARVORE_H

#define ORDEM 4

typedef struct no{
    int quant;
    int chave[ORDEM-1];
    bool folha;
    no * filho[ORDEM];
}Nodo;

typedef struct arvore{
    Nodo * raiz;
    //Nodo * nil;
}ArvB;

Nodo * Arv_busca(Nodo * x, int k);

#endif //ARVORE_H

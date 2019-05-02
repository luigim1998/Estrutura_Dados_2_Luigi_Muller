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
    //Nodo * nil; caso ele volte, mudar o Arv_cria()
}ArvB;

int teto(int n);
ArvB * Arv_cria();
Nodo * Nodo_cria();
Nodo * Arv_busca(Nodo * x, int k);
Nodo * Arv_split_child(Nodo * x, int i);

#endif //ARVORE_H

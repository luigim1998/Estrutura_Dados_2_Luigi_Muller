#ifndef ARVORE_H
#define ARVORE_H

#define GRAU_MINIMO 3

typedef struct no{
    int quant;
    bool folha;
    int * chave;
    no ** filho;
}Nodo;

typedef struct arvore{
    Nodo * raiz;
    //Nodo * nil; caso ele volte, mudar o Arv_cria()
}ArvB;

ArvB * Arv_cria();
Nodo * Nodo_cria();
Nodo * Arv_busca(Nodo * x, int k);
Nodo * Arv_split_child(Nodo * x, int i);
void Arv_insere(ArvB * T, int k);
void Arv_insere_nao_cheia(Nodo *x, int k);
void Arv_remove(Nodo * raiz, int k);

#endif //ARVORE_H

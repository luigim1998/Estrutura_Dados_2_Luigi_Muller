#ifndef ARVOREBINARIABUSCA_H
#define ARVOREBINARIABUSCA_H

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct Arv_bin{
    Nodo* raiz;
};

Arv_bin * abb_cria();
void arv_imprime(Arv_bin * arv);
void arv_imprime_no(Nodo * raiz);
void arv_libera(Arv_bin * arv);
void arv_libera_no(Nodo * raiz);
Nodo * arv_busca_no(Nodo *raiz, int n);
void abb_insere(Arv_bin *arv, int n);
Nodo * insere_no(Nodo *raiz, int n);
void abb_remove(Arv_bin *arv, int n);
Nodo * remove_no(Nodo *raiz, int n);
void abb_remove_sucessor(Arv_bin *arv, int n);
Nodo * remove_no_sucessor(Nodo *raiz, int n);
bool check_arvBusca(Nodo *raiz);
int abb_maior_valor(Arv_bin * arv);
int abb_maior_valor_no(Nodo * raiz);
int abb_menor_valor(Arv_bin * arv);
int abb_menor_valor_no(Nodo * raiz);
int quant_nos(Nodo * raiz);
int arv_busca_k_valor(Arv_bin * arv, int k);
int arv_busca_k_valor_no(Nodo * raiz, int k);
int quant_nos(Nodo * raiz);
#endif //ARVOREBINARIABUSCA_H

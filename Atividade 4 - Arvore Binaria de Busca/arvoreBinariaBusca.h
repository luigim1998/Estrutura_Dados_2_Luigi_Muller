#ifndef ARVOREBINARIABUSCA_H
#define ARVOREBINARIABUSCA_H

#include <queue>
using namespace std;

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo* raiz;
}Arv_bin;

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
Nodo * arv_busca_k_valor(Arv_bin * arv, int k);
Nodo * arv_busca_k_valor_no(Nodo * raiz, int * k);
int quant_nos(Nodo * raiz);
bool arv_iguais(Arv_bin * arv1, Arv_bin * arv2);
bool arv_iguais_no(Nodo * raiz1, Nodo * raiz2);
int quant_um_filho(Arv_bin * arv);
int quant_um_filho_no(Nodo * raiz);
Arv_bin * constroi_arv(queue<int> * entrada);
bool arv_subsequencia(Arv_bin * arv, queue<int> * fila, int tamanho);

#endif //ARVOREBINARIABUSCA_H

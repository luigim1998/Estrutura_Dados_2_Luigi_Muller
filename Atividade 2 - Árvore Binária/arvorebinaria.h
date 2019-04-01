#ifndef ARVOREBINARIA_H_
#define ARVOREBINARIA_H_

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;

void arv_imprime_formatado(Arv_bin * arv);
void arv_imprime_formatado_no(Nodo * nozinho);
Nodo * arv_cria_no(char c, Nodo* esq, Nodo* dir);
Arv_bin * arv_cria(Nodo * raiz);
void arv_imprime_escolhendo_ordem(Arv_bin * arv, int ordem);
void arv_imprime_pre_ordem(Nodo * raiz);
void arv_imprime_infixa(Nodo * raiz);
void arv_imprime_pos_ordem(Nodo * raiz);
void arv_imprime_infixa_iter(Nodo * raiz);
void arv_imprime_pos_ordem_iter(Nodo * raiz);
void limpa_arvore(Arv_bin * arvore);
void limpa_nodo(Nodo * nozinho);
int arv_pertence(Arv_bin * arv, char c); //retorna 1 se o caractere estiver na árvore e 0 caso contrário
int arv_pertence_no(Nodo * raiz, char c);
Nodo* arv_busca(Arv_bin * arv, char c); //retorna o ponteiro do caractere se estiver na árvore ou NULL caso contrário
Nodo* arv_busca_no(Nodo * raiz, char c);
int maximo(int alt_sae, int alt_sad); //retorna o valor máximo dos dois
int arv_altura(Arv_bin * arv); //retorna a altura da árvore
int arv_altura_no(Nodo * raiz);
void arv_largura(Arv_bin * a); //imprime o percurso em largura da árvore
int tamanho(Arv_bin * arv); //retorna o número de nós
Arv_bin * espelho(Arv_bin * p); //retorna o ponteiro da árvore espelhada
Nodo * espelho_nodo(Nodo * raiz);
int arv_folhas(Nodo * raiz); //retorna o número de folhas
int arv_estrita(Nodo * raiz); //retorna 1 se a árvore  for estrita ou 0 caso contrário
int arv_completa(Arv_bin * arv); //retorna 1 se a árvore  for coompleta ou 0 caso contrário

#endif // ARVORE_H_

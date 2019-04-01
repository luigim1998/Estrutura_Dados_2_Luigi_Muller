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
int arv_pertence(Arv_bin * arv, char c); //retorna 1 se o caractere estiver na �rvore e 0 caso contr�rio
int arv_pertence_no(Nodo * raiz, char c);
Nodo* arv_busca(Arv_bin * arv, char c); //retorna o ponteiro do caractere se estiver na �rvore ou NULL caso contr�rio
Nodo* arv_busca_no(Nodo * raiz, char c);
int maximo(int alt_sae, int alt_sad); //retorna o valor m�ximo dos dois
int arv_altura(Arv_bin * arv); //retorna a altura da �rvore
int arv_altura_no(Nodo * raiz);
void arv_largura(Arv_bin * a); //imprime o percurso em largura da �rvore
int tamanho(Arv_bin * arv); //retorna o n�mero de n�s
Arv_bin * espelho(Arv_bin * p); //retorna o ponteiro da �rvore espelhada
Nodo * espelho_nodo(Nodo * raiz);
int arv_folhas(Nodo * raiz); //retorna o n�mero de folhas
int arv_estrita(Nodo * raiz); //retorna 1 se a �rvore  for estrita ou 0 caso contr�rio
int arv_completa(Arv_bin * arv); //retorna 1 se a �rvore  for coompleta ou 0 caso contr�rio

#endif // ARVORE_H_

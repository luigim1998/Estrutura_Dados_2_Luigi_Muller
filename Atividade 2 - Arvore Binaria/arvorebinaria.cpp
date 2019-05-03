#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "arvorebinaria.h"
#include <queue>
#include <stack>
using namespace std;

Arv_bin * arv_cria(Nodo * raiz){
    Arv_bin * arv = (Arv_bin *) malloc(sizeof(Arv_bin));
    arv->raiz = raiz;
    return arv;
}

Nodo * arv_cria_no(char c, Nodo* esq, Nodo* dir){
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->info = c;
    return nodo;
}

void arv_imprime_pre_ordem(Nodo * raiz){
    if(raiz != NULL){
        printf("%c", raiz->info);
        arv_imprime_pre_ordem(raiz->esq);
        arv_imprime_pre_ordem(raiz->dir);
    }
}

void arv_imprime_infixa(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_infixa(raiz->esq);
        printf("%c", raiz->info);
        arv_imprime_infixa(raiz->dir);
    }
}

void arv_imprime_pos_ordem(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_pos_ordem(raiz->esq);
        arv_imprime_pos_ordem(raiz->dir);
        printf("%c", raiz->info);
    }
}

void arv_imprime_infixa_iter(Nodo * raiz){
    stack<Nodo*> pilha;
    Nodo * aux = NULL;
    pilha.push(raiz);

    while(pilha.empty() != true){
        aux = pilha.top();
        while(aux->esq != NULL){
            pilha.push(aux->esq);
            aux = pilha.top();
        }
        printf("%c", aux->info);
        pilha.pop();
        while(aux->dir == NULL && !pilha.empty()){
            aux = pilha.top();
            printf("%c", aux->info);
            pilha.pop();
        }
        if(aux->dir != NULL){
            pilha.push(aux->dir);
        }
    }
}

void arv_imprime_pos_ordem_iter(Nodo * raiz){
    stack<Nodo*> sae;
    stack<Nodo*> sad;
    Nodo * aux;
    if(raiz == NULL){
        return;
    } else {
        aux = raiz;
        sae.push(NULL);
        sad.push(aux);
    }
    while(!sae.empty() || !sad.empty()){

        while((aux->esq != NULL) || (aux->dir != NULL)){
            sae.push(aux->esq);
            sad.push(aux->dir);
            if(aux->esq != NULL){
                aux = aux->esq;
            } else {
                aux = aux->dir;
            }
        }
        while(!((sae.top() != NULL) && (sad.top() != NULL))){
            if(sae.top()!= NULL){
                printf("%c", sae.top()->info);
            } else {
                printf("%c", sad.top()->info);
            }
            sae.pop();
            sad.pop();
            if(sae.empty()) break;
        }
        if(!sae.empty()){
            if(sae.top() != NULL){
                printf("%c\n", sae.top()->info);
                aux = sad.top();
                sae.pop();
                sae.push(NULL);
            } else {
                printf("%c\n", sad.top()->info);
                sae.pop();
                sad.pop();
                aux = sad.top();
            }
        }
    }
}

void arv_imprime_escolhendo_ordem(Arv_bin * arv, int ordem){
    switch(ordem){
        case 0:
            arv_imprime_pre_ordem(arv->raiz);
            break;
        case 1:
            arv_imprime_infixa(arv->raiz);
            break;
        case 2:
            arv_imprime_pos_ordem(arv->raiz);
            break;
        case 3:
            arv_imprime_infixa_iter(arv->raiz);
            break;
        case 4:
            arv_imprime_pos_ordem_iter(arv->raiz);
            break;
        default:
            arv_imprime_pre_ordem(arv->raiz);
    }
}

void arv_imprime_formatado(Arv_bin * arv){
    if(arv != NULL){
        arv_imprime_formatado_no(arv->raiz);
    }
}

void arv_imprime_formatado_no(Nodo * nozinho){
    printf("<");
    if(nozinho != NULL){
        printf("%c", nozinho->info);
        arv_imprime_formatado_no(nozinho->esq);
        arv_imprime_formatado_no(nozinho->dir);
    }
    printf(">");
}

void limpa_arvore(Arv_bin * arvore){
    if(arvore != NULL){
        limpa_nodo(arvore->raiz);
        free(arvore);
    }
}

void limpa_nodo(Nodo * nozinho){
    if(nozinho != NULL){
        limpa_nodo(nozinho->esq);
        limpa_nodo(nozinho->dir);
        free(nozinho);
    }
}

int arv_pertence(Arv_bin * arv, char c){
    return arv_pertence_no(arv->raiz, c);
}

int arv_pertence_no(Nodo * raiz, char c){
    if(raiz == NULL)
        return 0;
    if(raiz->info == c)
        return 1;
    if(arv_pertence_no(raiz->esq, c))
        return 1;
    return arv_pertence_no(raiz->dir, c);
}

Nodo* arv_busca(Arv_bin * arv, char c){
    return arv_busca_no(arv->raiz, c);
}

Nodo* arv_busca_no(Nodo * raiz, char c){
    if(raiz == NULL)
        return NULL;
    if(raiz->info == c)
        return raiz;
    if(arv_busca_no(raiz->esq, c))
        return raiz->esq;
    return arv_busca_no(raiz->dir, c);
}

int maximo(int alt_sae, int alt_sad){
    if(alt_sae > alt_sad){
            return alt_sae;
        } else {
            return alt_sad;
        }
}

int arv_altura(Arv_bin * arv){
    if(arv == NULL){
        return -1;
    } else {
        return arv_altura_no(arv->raiz) - 1;
    }
}

int arv_altura_no(Nodo * raiz){
    if(raiz == NULL){
        return 0;
    } else {
        int esquerda = arv_altura_no(raiz->esq);
        int direita  = arv_altura_no(raiz->dir);
        return 1 + maximo(esquerda, direita);
    }
}

void arv_largura(Arv_bin * a){
    queue <Nodo*> nozinho;
    nozinho.push(a->raiz);
    while(nozinho.empty() != true){
        Nodo * p = nozinho.front();
        nozinho.pop();
        if(p != NULL){
            printf("%c", p->info);
            nozinho.push(p->esq);
            nozinho.push(p->dir);
        }
    }
}

int tamanho(Arv_bin * arv){
    queue <Nodo*> raiz;
    int i = 0;
    if(arv->raiz == NULL){
        return 0;
    } else {
        i++;
    }

    raiz.push(arv->raiz);
    while(raiz.empty() != true){
        Nodo * p = raiz.front();
        raiz.pop();
        if(p->esq != NULL){
            raiz.push(p->esq);
            i++;
        }
        if(p->dir != NULL){
            raiz.push(p->dir);
            i++;
        }
    }
    return i;
}

Arv_bin * espelho(Arv_bin * p){
    if(p != NULL){

    }
    return arv_cria(arv_cria_no(p->raiz->info, espelho_nodo(p->raiz->dir), espelho_nodo(p->raiz->esq)));
}

Nodo * espelho_nodo(Nodo * raiz){
    if(raiz != NULL){
        return arv_cria_no(raiz->info, espelho_nodo(raiz->dir), espelho_nodo(raiz->esq));
    } else {
        return NULL;
    }
}

int arv_folhas(Nodo * raiz){
    if(raiz == NULL){
        return 0;
    }
    if (raiz->esq == NULL && raiz->dir == NULL){
        return 1;
    } else {
        return arv_folhas(raiz->esq) + arv_folhas(raiz->dir);
    }
}

int arv_estrita(Nodo * raiz){
    if(raiz == NULL){
        return 1;
    }
    if(raiz->esq == NULL){
        if(raiz->dir == NULL){
            return 1;
        } else {
            return 0;
        }
    } else {
        if(raiz->dir == NULL){
            return 0;
        } else {
            return arv_estrita(raiz->esq) && arv_estrita(raiz->dir);
        }
    }
}

int arv_completa(Arv_bin * arv){
    if(arv->raiz == NULL){
        return 0;
    }
    printf("%lf %lf", (double) tamanho(arv), (pow(2,arv_altura(arv)+1)-1));
    if ((double) tamanho(arv) == (pow(2,arv_altura(arv)+1)-1)){
        return 1;
    } else {
        return 0;
    }
}


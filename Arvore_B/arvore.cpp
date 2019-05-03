#include "arvore.h"
#include <stdlib.h>

int teto(double n){
    if((n - (int)n) > 0){
        return (int)(n) + 1;
    } else {
        return (int)(n);
    }
}

ArvB * Arv_cria(){
    ArvB * arv = new ArvB;
    Nodo * raiz = Nodo_cria();
    arv->raiz = raiz;
}

Nodo * Nodo_cria(){
    Nodo * raiz = new Nodo;
    raiz->folha = true;
    raiz->quant = 0;
    raiz->chave = new int[2*GRAU_MINIMO - 1];
    raiz->filho = new Nodo*[2*GRAU_MINIMO];
}

Nodo * Arv_busca(Nodo * x, int k){
    int i = 0;

    /* os operadores relacionais estão separados pois
     * o i pode ser maior que o tamanho do vetor e
     * dar 'segmentation fault'
    */
    while(i < x->quant){
        if(k > x->chave[i])
            i = i + 1;
    }

    /* os operadores relacionais estão separados pois
     * o i pode ser maior que o tamanho do vetor e
     * dar 'segmentation fault'
    */
    if(i < x->quant){
        if(k == x->chave[i])//é a chave
            return x;
    } else if(x->folha){//não existe
        return NULL;
    } else {//busca no filho
        return Arv_busca(x->filho[i], k);
    }
}

Nodo * Arv_split_child(Nodo * x, int i){
    Nodo * z = Nodo_cria();
    Nodo * y = x->filho[i];
    int j;
    z->folha = y->folha;//se o filho for uma folha, ele também é
    z->quant = GRAU_MINIMO - 1;//a nova quantidade do novo nodo
    for(j = 0; j < GRAU_MINIMO - 1; j++){//as chaves são passadas para o novo nodo
        z->chave[j] = y->chave[j+GRAU_MINIMO];
    }
    if(!y->folha){//coloca os filhos no novo nodo
        for(j = 0; j < GRAU_MINIMO; j++){
            z->filho[j] = y->filho[j+GRAU_MINIMO];
        }
    }
    y->quant = GRAU_MINIMO - 1;//atualiza a quantidade
    for(j = x->quant; j > i; j--){
        x->filho[j+1] = x->filho[j];
    }
    x->filho[i+1] = z;//recebe o novo nodo
    for(j = x->quant-1; j >= i; j--){//passa os valores depois de i para a frente para colocar o novo valor
        x->chave[j+1] = x->chave[j];
    }
    x->chave[i] = y->chave[GRAU_MINIMO];
    x->quant = x->quant + 1;
}

void Arv_insere(ArvB * T, int k){//TODO: analisar função
    Nodo * r = T->raiz;
    if(r->quant == 2*GRAU_MINIMO -1){
        Nodo * s = Nodo_cria();
        T->raiz = s;
        s->folha = false;
        s->quant = 0;
        s->filho[0] = r;
        Arv_split_child(s, 0);
        Arv_insere_nao_vazio(s, k);
    } else {
        Arv_insere_nao_vazio(r, k);
    }
}
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

Nodo * Arv_split_child(Nodo * x, int i){//TODO: analisar o código
    Nodo * z = Nodo_cria();
    Nodo * y = x->filho[i];
    int j;
    z->folha = y->folha;
    z->quant = teto(ORDEM/2.0) - 1;
    for(j = 0; j < teto(ORDEM/2.0) - 1; j++){
        z->chave[i] = y->chave[j+teto(ORDEM/2.0)];
    }
    if(!y->folha){
        for(j = 0; j < teto(ORDEM/2.0); j++){
            z->filho[j] = y->filho[j+teto(ORDEM/2.0)];
        }
    }
    y->quant = teto(ORDEM/2.0) - 1;
    for(j = x->quant - 1; j > i+1; j--){
        x->filho[j+1] = x->filho[j];
    }
    x->filho[i+1] = z;
    for(j = x->quant; j > i; j--){
        x->chave[j+1] = x->chave[j];
    }
    x->chave[i] = y->chave[i];
    x->quant = x->quant + 1;
}
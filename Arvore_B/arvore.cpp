#include "arvore.h"
#include <stdlib.h>

Nodo * Arv_busca(Nodo * x, int k){
    int i = 0;
    //acho que tá errado
    /*while(i < x->quant && k > x->chave[i]){
        i = i + 1;
    }*/
    while(i < x->quant){
        if(k > x->chave[i])
            i = i + 1;
    }
    if(i <= x->quant && k == x->chave[i]){//é a chave
        return x;
    } else if(x->folha){//não existe
        return NULL;
    } else {//busca no filho
        return Arv_busca(x->filho[i], k);
    }
}
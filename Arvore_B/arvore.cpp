#include "arvore.h"
#include <stdlib.h>

/**
 * Cria uma árvore.
 * @return ponteiro da nova árvore.
 */
ArvB * Arv_cria(){
    ArvB * arv = new ArvB;
    Nodo * raiz = Nodo_cria();
    arv->raiz = raiz;
}

/**
 * Cria um nodo.
 * @return ponteiro do novo nodo.
 */
Nodo * Nodo_cria(){
    Nodo * raiz = new Nodo;
    raiz->folha = true;
    raiz->quant = 0;
    raiz->chave = new int[2*GRAU_MINIMO - 1];
    raiz->filho = new Nodo*[2*GRAU_MINIMO];
}

/**
 *
 * @param x
 * @param k
 * @return
 */
Nodo * Arv_busca(Nodo * x, int k){
    int i = 0;

    /* os operadores relacionais estão separados pois
     * o i pode ser maior que o tamanho do vetor e
     * dar 'segmentation fault'
    */
    while(i < x->quant){
        if(k > x->chave[i])
            i = i + 1;
        else
            break;
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

void Arv_insere(ArvB * T, int k){
    Nodo * r = T->raiz;
    if(r->quant == 2*GRAU_MINIMO -1){//está cheia
        Nodo * s = Nodo_cria();
        T->raiz = s;
        s->folha = false;
        s->quant = 0;
        s->filho[0] = r;
        Arv_split_child(s, 0);
        Arv_insere_nao_cheia(s, k);
    } else {
        Arv_insere_nao_cheia(r, k);
    }
}

void Arv_insere_nao_cheia(Nodo *x, int k) {
    int i = x->quant-1;
    if(x->folha){
        while(i>=0){
            if(k < x->chave[i]) {
                x->chave[i + 1] = x->chave[i];//o valor é jogado para a frente
                i--;
            } else {
                break;
            }
        }
        x->chave[i+1] = k;//recebe o novo valor
        (x->quant)++;
    } else {
        while(i>=0){//aponta para o indice do vetor que será inserido k
            if(k < x->chave[i]) {
                i--;
            } else {
                break;
            }
        }
        i++;
        //se o filho que receberá k está cheio então separa
        if(x->filho[i]->quant == 2*GRAU_MINIMO - 1){
            Arv_split_child(x, i);
            if(k > x->chave[i]){//ele incrementa se a chave for maior
                i++;
            }
        }
        Arv_insere_nao_cheia(x->filho[i], k);
    }
}

void Arv_remove(Nodo * raiz, int k){
    Nodo * pai = NULL;
    Nodo * filho = raiz;
    int i = 0;

    while(filho->chave[i] != k){
        //seleciona o indice que raiz->chave[i-1] < k <= raiz->chave[i]
        while(i < filho->quant){
            if(k > filho->chave[i])
                i = i + 1;
            else
                break;
        }
        if(k == filho->chave[i]){//se for igual é esse o nodo e sai do loop
            break;
        } else {//atualiza o pai e o filho
            pai = filho;
            filho = filho->filho[i];
        }
        i = 0;
    }

    if(!filho->folha){//caso 2: não está na folha
        Nodo * aux_pai = filho;
        Nodo * aux_filho = filho->filho[i];
        //busca o antecedente
        while(!aux_filho->folha){
            aux_pai = aux_filho;
            aux_filho = aux_filho->filho[aux_filho->quant - 1];//recebe o ultimo filho
        }
        filho->chave[i] = aux_filho->chave[aux_filho->quant-1];//troca o valor
        aux_filho->quant = aux_filho->quant - 1;//remover valor
        pai = aux_pai;
        filho = aux_filho;
    } else {
        //caso 1: é uma folha e tem o suficiente para retirar
        if (filho->quant > GRAU_MINIMO - 1) {
            while (i < filho->quant - 1) {//apaga os valores
                filho->chave[i] = filho->chave[i + 1];
                i++;
            }
        } else {//não tem o suficiente
            if(i > 0){//pode pegar do nodo anterior
                if(pai->filho[i-1]->quant > GRAU_MINIMO - 1){//caso 3: pode dar uma chave
                    int cont = filho->quant - 1;
                    while(cont >= 0){
                        filho->chave[cont+1] = filho->chave[cont];
                        cont--;
                    }
                    filho->chave[0] = pai->chave[i-1];//passa o valor do pai para o filho
                    filho->quant = filho->quant + 1;
                    pai->chave[i-1] = pai->filho[i-1]->chave[pai->filho[i-1]->quant - 1];//a chave recebe o antecessor
                    pai->filho[i-1]->quant = pai->filho[i-1]->quant - 1;
                } else {//caso 4: dá merge
                    int cont = 0;
                    pai->filho[i-1]->chave[pai->filho[i-1]->quant] = pai->chave[i-1];//o nodo recebe a chave do pai
                    pai->filho[i-1]->quant = pai->filho[i-1]->quant + 1;//imcrementa
                    while(cont < filho->quant){//faz o merge
                        pai->filho[i-1]->chave[pai->filho[i-1]->quant] = filho->chave[cont];
                        pai->filho[i-1]->quant = pai->filho[i-1]->quant + 1;
                    }
                    cont = i+1;
                    while(cont < pai->quant){
                        pai->chave[cont - 1] = pai->chave[cont];
                        pai->filho[cont] = pai->filho[cont+1];
                    }
                    pai->quant = pai->quant - 1;
                }
            } else {//pega o nodo da frente
                if(pai->filho[i+1]->quant > GRAU_MINIMO - 1){//caso 3: pode dar uma chave
                    filho->chave[filho->quant] = pai->chave[0];//passa o valor do pai para o filho
                    filho->quant = filho->quant + 1;
                    pai->chave[i] = pai->filho[i+1]->chave[0];//a chave recebe o sucessor
                    int cont = 1;
                    while(cont < pai->filho[i+1]->quant){
                        pai->filho[i+1]->chave[cont-1] = pai->filho[i+1]->chave[cont];
                        cont++;
                    }
                    pai->filho[i+1]->quant = pai->filho[i+1]->quant - 1;
                } else {//caso 4: dá merge
                    int cont = 0;
                    filho->chave[filho->quant] = pai->chave[i];//o nodo recebe a chave do pai
                    filho->quant = filho->quant + 1;//imcrementa
                    while(cont < pai->filho[i+1]->quant){//faz o merge
                        filho->chave[filho->quant] = pai->filho[i+1]->chave[cont];
                        filho->quant = filho->quant + 1;
                    }
                    cont = i+1;
                    while(cont < pai->quant){
                        pai->chave[cont - 1] = pai->chave[cont];
                        pai->filho[cont] = pai->filho[cont+1];
                    }
                    pai->quant = pai->quant - 1;
                }
            }
        }
    }
}
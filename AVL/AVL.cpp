#include "AVL.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * Cria a arvore e retorna o nodo.
 * @return o nodo.
 */
Avl * cria_arv(){
    Avl * aux = new Avl;
    aux->raiz = NULL;
    return aux;
}

/**
 * Insere o valor na arvore.
 * @param arv ponteiro da arvore.
 * @param k valor a ser inserido.
 */
void arv_inserir(Avl * arv, int k){
    arv->raiz = inserir(arv->raiz, k);
}

/**
 * Insere o valor no nodo passado.
 * @param raiz nodo da arvore;
 * @param k valor a ser inserido;
 * @return nodo da arvore balanceado;
 */
Nodo * inserir(Nodo * raiz, int k){
    //Realiza a inserção
    if(raiz == NULL)
        return novo_nodo(k);

    if(k < raiz->info)
        raiz->esq = inserir(raiz->esq, k);
    else if(k > raiz->info)
        raiz->dir = inserir(raiz->dir, k);
    //Retorna o nodo caso seja igual
    else
        return raiz;

    //atualiza a altura
    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int fator_balanceamento = calcular_fator_balanceamento(raiz);

    /*Left Left Case - nodo está desbalanceado e seu filho
     * estiver no mesmo sentido da inclinação*/
    if(fator_balanceamento < -1 && k < raiz->esq->info)
        return dirRotate(raiz);
    /*Right Right Case - nodo está desbalanceado e seu filho
     * estiver no mesmo sentido da inclinação*/
    if(fator_balanceamento > 1 && k > raiz->dir->info)
        return esqRotate(raiz);
    /*Left Right Case - nodo está desbalanceado e seu filho está
     * inclinado no sentido inverso ao pai, formando um "joelho"*/
    if(fator_balanceamento < -1 && k > raiz->esq->info){
        raiz->esq = esqRotate(raiz->esq);
        return dirRotate(raiz);
    }
    /*Right Left Case - nodo está desbalanceado e seu filho está
     * inclinado no sentido inverso ao pai, formando um "joelho"*/
    if(fator_balanceamento > 1 && k < raiz->dir->info){
        //precisamos fazer o nodo filho rotacionar para depois o nodo
        raiz->dir = dirRotate(raiz->dir);
        return esqRotate(raiz);
    }
    return raiz; //não precisa rotacionar
}

/**
 * Retorna a altura do nodo.
 * @param p nodo para calcular a altura.
 * @return altura do nodo.
 */
int altura(Nodo * p){
    if(p == NULL) return -1;
    return p->altura;
}

/**
 * Retorna o maior valor.
 * @param a primeiro valor.
 * @param b segundo valor.
 * @return maior valor entre os dois valores passados.
 */
int max(int a, int b){
    return (a > b) ? a : b;
}

/**
 * Cria um novo nodo com o valor passado para a funcao.
 * @param info valor do nodo a criar.
 * @return novo nodo.
 */
Nodo * novo_nodo(int info){
    Nodo * novo = new Nodo;
    novo->info = info;
    novo->esq = NULL;
    novo ->dir = NULL;
    novo->altura = 0;
    return novo;
}

/**
 * Faz a rotação do nodo para a direita.
 * @param x nodo para rotacionar.
 * @return nodo rotacionado.
 */
Nodo * dirRotate(Nodo * x) {
    Nodo *y = x->esq;
    Nodo *T2 = y->dir;

    y->dir = x;
    x->esq = T2;

    /*como somente x e y são alterados então
     * precisamos calcular os tamanhos*/
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

/**
 * Faz a rotação do nodo para a esquerda.
 * @param x nodo para rotacionar.
 * @return nodo rotacionado.
 */
Nodo * esqRotate(Nodo * x){
    Nodo * y = x->dir;
    Nodo * T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    //como somente x e y são alterados então precisamos calcular os tamanhos
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

/**
 * Calcular o fator de balanceamento.
 * @param r nodo para calcular.
 * @return fator de balanceamento.
 */
int calcular_fator_balanceamento(Nodo * r){
    if(r == NULL)
        return 0;
    return altura(r->dir) - altura(r->esq);
}

/**
 * Remove o valor na arvore.
 * @param arv ponteiro da arvore.
 * @param k valor a ser removido.
 */
void arv_remover(Avl * arv, int k){
    arv->raiz = remover(arv->raiz, k);
}

/**
 * Remover o nodo que tem o passado para a funcao.
 * @param raiz nodo para fazer a remocao.
 * @param k valor a ser excluido.
 * @return nodo com o valor removido.
 */
Nodo * remover(Nodo * raiz, int k){
    if(raiz == NULL)
        return NULL;
    else if(k < raiz->info)
        raiz->esq = remover(raiz->esq, k);
    else if(k > raiz->info)
        raiz->dir = remover(raiz->dir, k);
    else{
        //nodo não tem filho
        if(raiz->esq == NULL && raiz->dir == NULL){
            delete raiz;
            raiz = NULL;
        }//só tem o filho à direita
        else if(raiz->esq == NULL){
            Nodo * aux = raiz;
            raiz = raiz->dir;
            delete aux;
        }//só tem o filho à esquerda
        else if(raiz->dir == NULL){
            Nodo * aux = raiz;
            raiz = raiz->esq;
            delete aux;
        }//tem dois filhos
        else {
            Nodo *aux = raiz->esq;
            while (aux->dir != NULL) {
                aux = aux->dir;
            }/*troca as informações da raiz
              * com o nodo mais à direita da sae*/
            raiz->info = aux->info;
            aux->info = k;
            raiz->esq = remover(raiz->esq, k);
        }
    }
    //se a arvore só tinha um nodo, então retorna NULL
    if(raiz == NULL)
        return raiz;

    //Atualiza o tamanho da raiz
    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int fator_balanceamento = calcular_fator_balanceamento(raiz);

    /*se ambos os fatores de balanceamento tiverem o mesmo sinal faz
     * rotação simples, senão faz rotação dupla*/
    //Left Left Case
    if(fator_balanceamento < -1 && calcular_fator_balanceamento(raiz->esq) <= 0)
        return dirRotate(raiz);
    //Left Right Case
    if(fator_balanceamento < -1 && calcular_fator_balanceamento(raiz->esq) > 0){
        raiz->esq = esqRotate(raiz->esq);
        return dirRotate(raiz);
    }
    //Right Right Case
    if(fator_balanceamento > 1 && calcular_fator_balanceamento(raiz->dir) >= 0)
        return dirRotate(raiz);
    //Right Left Case
    if(fator_balanceamento > 1 && calcular_fator_balanceamento(raiz->dir) < 0){
        raiz->dir = dirRotate(raiz->dir);
        return esqRotate(raiz);
    }
    return raiz;
}

Nodo *arv_busca(Avl *arv, int k) {
    if(arv == NULL){
        return NULL;
    } else {
        return busca(arv->raiz, k);
    }
}

Nodo *busca(Nodo *raiz, int k) {
    if(raiz == NULL){
        return NULL;
    } else {
        if(k < raiz->info){
            return busca(raiz->esq, k);
        } else if(k > raiz->info){
            return busca(raiz->dir, k);
        } else {
            return raiz;
        }
    }
}

void arv_imprime_pre_ordem(Nodo *raiz){
    if(raiz != NULL){
        cout << raiz->info << " ";
        arv_imprime_pre_ordem(raiz->esq);
        arv_imprime_pre_ordem(raiz->dir);
    }
}

void arv_imprime_in_ordem(Nodo *raiz){
    if(raiz != NULL){
        arv_imprime_in_ordem(raiz->esq);
        cout << raiz->info << " ";
        arv_imprime_in_ordem(raiz->dir);
    }
}

void arv_imprime_pos_ordem(Nodo *raiz){
    if(raiz != NULL){
        arv_imprime_pos_ordem(raiz->esq);
        arv_imprime_pos_ordem(raiz->dir);
        cout << raiz->info << " ";
    }
}
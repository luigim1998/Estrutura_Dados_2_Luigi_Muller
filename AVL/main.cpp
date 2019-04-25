#include <iostream>
#include "AVL.h"

int main(){
    Avl * arv = cria_arv();
    arv_inserir(arv,  50);
    arv_inserir(arv,  25);
    arv_inserir(arv,  75);
    arv_inserir(arv,  12);
    arv_inserir(arv,   6);
    arv_inserir(arv,  90);
    arv_inserir(arv, 100);
    arv_inserir(arv, 120);
    arv_inserir(arv, 110);
    arv_inserir(arv,   3);
    arv_inserir(arv,   5);

    arv_remover(arv, 50);
    return 0;
}
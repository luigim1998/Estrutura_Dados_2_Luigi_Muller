#include <iostream>
#include "arvore.h"

int main() {
    ArvRN * arv = cria_arvore();

    Insert(arv, cria_nodo(1));
    Insert(arv, cria_nodo(2));
    Insert(arv, cria_nodo(3));
    Insert(arv, cria_nodo(4));
    Insert(arv, cria_nodo(5));
    Insert(arv, cria_nodo(6));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"
#include <queue>
using namespace std;

int main(){
    Arv_bin * arv = arv_cria(
                        arv_cria_no('a',
                            arv_cria_no('b',
                                    NULL,
                                    arv_cria_no('d', NULL, NULL) ),
                            arv_cria_no('c',
                                    arv_cria_no('e', NULL, NULL),
                                    arv_cria_no('f', NULL, NULL))
                        )
                    );
    Arv_bin * arv2 = arv_cria(
                        arv_cria_no('a',
                            arv_cria_no('b',
                                    arv_cria_no('d', NULL, NULL),
                                    arv_cria_no('e', NULL, NULL) ),
                            arv_cria_no('c',
                                    arv_cria_no('f', NULL, NULL),
                                    arv_cria_no('g', NULL, NULL))
                        )
                    );
    printf("Pre-ordem: ");
    arv_imprime_escolhendo_ordem(arv, 0);
    printf("\nInfixa:");
    arv_imprime_escolhendo_ordem(arv, 1);
    printf("\nInfixa iter: ");
    arv_imprime_escolhendo_ordem(arv, 3);
    printf("\nPos-ordem: ");
    arv_imprime_escolhendo_ordem(arv, 2);
    printf("\nPos-ordem iter: ");
    arv_imprime_escolhendo_ordem(arv, 4);
    printf("\nPre-ordem: ");
    arv_imprime_escolhendo_ordem(arv, 6);
    printf("\n");

    arv_imprime_formatado(arv);
    printf("\n");

    printf("Pertence 'e'; %d\n", arv_pertence(arv, 'e'));
    printf("Pertence 'c'; %d\n", arv_pertence(arv, 'c'));
    printf("Pertence 't'; %d\n", arv_pertence(arv, 't'));

    printf("%c\n", arv_busca(arv, 'a')->info);
    printf("%c\n", arv_busca(arv, 'b')->info);
    printf("%c\n", arv_busca(arv, 'c')->info);

    printf("%Busca 't': %p\n", arv_busca(arv, 't'));

    printf("Altura: %d\n", arv_altura(arv));

    printf("Largura: "); arv_largura(arv);
    printf("\n");

    printf("Tamanho: %d\n", tamanho(arv));

    arv_imprime_formatado(espelho(arv));
    printf("\n");

    printf("Folhas: %d\n", arv_folhas(arv->raiz));

    printf("Estrita: %d\n", arv_estrita(arv->raiz));

    printf("Completa: %d\n", arv_completa(arv));

    limpa_arvore(arv);

    return 0;
}

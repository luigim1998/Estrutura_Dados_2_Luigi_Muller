#include <iostream>
#include <queue>
#include "arvoreBinariaBusca.h"
using namespace std;

int main(){
    Arv_bin * arv = abb_cria();
    Arv_bin * arv2 = abb_cria();
    queue<int> fila;
    int tamanho, aux;

    //------------Atividade 01------------
    abb_insere(arv, 50); abb_insere(arv, 30);
    abb_insere(arv, 70); abb_insere(arv, 20);
    abb_insere(arv, 40); abb_insere(arv, 60);
    abb_insere(arv, 80); abb_insere(arv, 15);
    abb_insere(arv, 25); abb_insere(arv, 35);
    abb_insere(arv, 45); abb_insere(arv, 36);

    arv_imprime(arv);
    abb_remove(arv, 30);
    arv_imprime(arv);

    //------------Atividade 02------------
    abb_insere(arv, 30);
    arv_imprime(arv);
    abb_remove_sucessor(arv, 40);
    arv_imprime(arv);

    //------------Atividade 03------------
    cout << "A arvore e binaria de busca? " << check_arvBusca(arv->raiz) << endl;

    //------------Atividade 04------------
    cout << "Maior valor: " << abb_maior_valor(arv) << endl;

    //------------Atividade 05------------
    cout << "Menor valor: " << abb_menor_valor(arv) << endl;

    //------------Atividade 06------------
    cout << 7 << "o valor: " << arv_busca_k_valor(arv, 7)->info << endl;

    //------------Atividade 07------------
    abb_insere(arv2, 60); abb_insere(arv2, 80);
    abb_insere(arv2, 30); abb_insere(arv2, 10);
    abb_insere(arv2, 50);
    cout << "Arvores iguais? " << arv_iguais(arv, arv2) << endl;

    //------------Atividade 08------------
    cout << "Quantiade de nós com uma folha: " << quant_um_filho(arv) << endl;

    //------------Atividade 09------------
    for(int cont = 0; cont < 10; cont++){
        cin >> aux;
        fila.push(aux);
    }
    arv2 = constroi_arv(&fila);

    //------------Atividade 10------------
    cout << "Insira o tamanho: ";
    cin >> tamanho;
    for (int cont = 0; cont < tamanho; cont++){
        cin >> aux;
        fila.push(aux);
    }
    cout << "Eh subsequencia? " << arv_subsequencia(arv, &fila, tamanho);
    return 0;
}
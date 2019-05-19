#include <iostream>
#include "arvore.h"
using namespace std;

/*
 * Eu testei com inserindo inicialmente os valores 7 9 4 2 11 5
 * */

ArvHeap * initialize_heap(){
    ArvHeap * arv = new ArvHeap;
    int quant;
    cout << "Insira a quantidade: ";
    cin >> quant;
    arv->vector    = new int[quant+10];
    arv->lenght    = quant;
    arv->heap_size = 0;
    for(int cont = 0; cont < quant; cont++){
        cin >> arv->vector[cont];
    }
    print_heap(arv);
    return arv;
}

int main() {
    ArvHeap * arv = initialize_heap();
    build_max_heap(arv);
    heapsort(arv);
    build_max_heap(arv);
    maximum(arv);
    cout << heap_extract_max(arv) << endl;
    heap_increase_key(arv, 1, 12);
    heap_increase_key(arv, 4, 10);
    max_heap_insert(arv, 11);
    minimum(arv);
    cout << heap_extract_min(arv) << endl;
    heap_decrease_key(arv, 3, 6);
    min_heap_insert(arv, 2);
    return 0;
}
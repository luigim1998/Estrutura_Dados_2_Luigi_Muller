#include "arvore.h"
#include <limits.h>
#include <iostream>
using namespace std;

/**
 * Deixa o vetor seguindo a propriedade da Heap Sort.
 * @param A - Ponteiro da árvore.
 */
void build_max_heap(ArvHeap * A){
    A->heap_size = A->lenght;
    int aux;
    for(aux = A->lenght/2; aux >= 0; aux--){
        max_heapify(A, aux);
    }
}

/**
 * Função para manter a propriedade da heap.
 * @param A - Ponteiro da árvore;
 * @param indice - índice para atualizar.
 */
void max_heapify(ArvHeap * A, int indice){
    int l = LEFT(indice);
    int r = RIGHT(indice);
    int largest = indice;

    //se o filho a esquerda for maior que o pai
    if(l < A->heap_size){
        if(A->vector[l] > A->vector[indice]){
            largest = l;
        }
    }
    //se o filho a esquerda for maior que o maior
    if(r < A->heap_size){
        if(A->vector[r] > A->vector[largest]){
            largest = r;
        }
    }
    if(largest != indice){
        //troca o maior
        int aux = A->vector[indice];
        A->vector[indice] = A->vector[largest];
        A->vector[largest] = aux;
        max_heapify(A, largest);
    }
}

/**
 * Organiza o vetor utilizando o heapsort.
 * @param A - ponteiro da árvore.
 */
void heapsort(ArvHeap * A){
    build_max_heap(A);
    int i, aux;
    for(i = A->lenght - 1; i > 0; i--){
        //troca o maior que está em A[0] pelo último
        aux = A->vector[0];
        A->vector[0] = A->vector[i];
        A->vector[i] = aux;
        //diminui o tamanho da heap já que os pultimos estão organizados
        A->heap_size = A->heap_size - 1;
        //ele mantém a propriedade da heap
        max_heapify(A, 0);
    }
}

/**
 * Retorna o maior valor.
 * @param A - ponteiro da árvore.
 * @return maior valor.
 */
int maximum(ArvHeap * A){
    return A->vector[0];
}

/**
 * Retorna o maior valor e remove o valor.
 * @param A - ponteiro da árvore.
 * @return maior valor.
 */
int heap_extract_max(ArvHeap * A){
    //se não tiver mais de um elemento então não é possível a remoção
    if(A->heap_size < 1){
        cout << "heap underflow" << endl;
        return 0;
    }
    int max = A->vector[0];
    A->vector[0] = A->vector[A->heap_size-1];
    A->heap_size = A->heap_size - 1;
    max_heapify(A, 0);
    return max;
}

void heap_increase_key(ArvHeap * A, int i, int key){
    if(key < A->vector[i]){
        cout << "new key is smaller than current key" << endl;
        return;
    }
    A->vector[i] = key;
    while(i > 0){
        if(A->vector[PARENT(i)] < A->vector[i]){
            int aux = A->vector[i];
            A->vector[i] = A->vector[PARENT(i)];
            A->vector[PARENT(i)] = aux;
            i = PARENT(i);
        } else {
            break;
        }
    }
}

void max_heap_insert(ArvHeap * A, int key){
    A->heap_size = A->heap_size + 1;
    A->vector[A->heap_size] = INT_MIN;
    heap_increase_key(A, A->heap_size, key);
}
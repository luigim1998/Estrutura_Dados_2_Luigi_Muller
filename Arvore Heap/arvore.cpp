#include "arvore.h"
#include <limits.h>
#include <iostream>
using namespace std;

/**
 * Imprime o vetor com o caractere '|'.
 * @param A - ponteiro da árvore.
 */
void print_heap(ArvHeap * A){
    for(int cont = 0; cont < A->heap_size; cont++){
        cout << A->vector[cont] << " ";
    }
    cout << "|";
    for(int cont = A->heap_size; cont < A->lenght; cont++){
        cout << A->vector[cont] << " ";
    }
    cout << endl;
}

/**
 * Deixa o vetor seguindo a propriedade da Heap Sort.
 * @param A - Ponteiro da árvore.
 */
void build_max_heap(ArvHeap * A){
    A->heap_size = A->lenght;
    int aux;
    for(aux = A->lenght/2 - 1; aux >= 0; aux--){
        max_heapify(A, aux);
        print_heap(A);
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
    print_heap(A);
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
        //diminui o tamanho da heap já que os últimos estão organizados
        A->heap_size = A->heap_size - 1;
        //ele mantém a propriedade da heap
        max_heapify(A, 0);
    }
}

/**
 * Retorna o maior valor da heapsort.
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
    int max_num = A->vector[0];
    A->vector[0] = A->vector[A->heap_size-1];
    A->heap_size = A->heap_size - 1;
    max_heapify(A, 0);
    print_heap(A);
    return max_num;
}

/**
 * Aumenta o valor da chave i caso o key seja maior.
 * @param A - ponteiro da árvore;
 * @param i - índice do vetor a ser promovido;
 * @param key - novo valor da chave.
 */
void heap_increase_key(ArvHeap * A, int i, int key){
    //caso key não seja maior
    if(key < A->vector[i]){
        cout << "new key is smaller than current key" << endl;
        return;
    }
    A->vector[i] = key;
    //promove o valor enquanto o pai for menor que ele
    while(i > 0){
        if(A->vector[PARENT(i)] < A->vector[i]){
            int aux = A->vector[i];
            A->vector[i] = A->vector[PARENT(i)];
            A->vector[PARENT(i)] = aux;
            i = PARENT(i);
        } else {
            break;
        }
        print_heap(A);
    }
}

/**
 * Insere o novo valor na heap.
 * @param A - ponteiro da árvore;
 * @param key - valor a ser inserido.
 */
void max_heap_insert(ArvHeap * A, int key){
    A->vector[A->heap_size] = INT_MIN;
    heap_increase_key(A, A->heap_size, key);
    A->heap_size = A->heap_size + 1;
    print_heap(A);
}

/**
 * Retorna o menor valor da heapsort.
 * @param A - ponteiro da árvore.
 * @return menor valor.
 */
int minimum(ArvHeap * A){
    //executa o heapsort para organizar o vetor
    heapsort(A);
    int aux = A->vector[0];
    build_max_heap(A);
    return aux;
}

/**
 * Remove e retorna o menor inteiro.
 * @param A - ponteiro da árvore.
 * @return menor inteiro.
 */
int heap_extract_min(ArvHeap * A){
    //se não tiver mais de um elemento então não é possível a remoção
    if(A->heap_size < 1){
        cout << "heap underflow" << endl;
        return 0;
    }
    //executa o heapsort para pegar o menor número
    heapsort(A);
    int min_num = A->vector[0];
    A->vector[0] = A->vector[A->heap_size-1];
    A->heap_size = A->heap_size - 1;
    //reconstrói a árvore
    build_max_heap(A);
    print_heap(A);
    return min_num;
}

/**
 * Diminui o valor da chave i caso o key seja menor.
 * @param A - ponteiro da árvore;
 * @param i - índice do vetor a ser rebaixado;
 * @param key - novo valor da chave.
 */
void heap_decrease_key(ArvHeap * A, int i, int key){
    //caso key não seja menor
    if(key > A->vector[i]){
        cout << "new key is smaller than current key" << endl;
        return;
    }
    A->vector[i] = key;
    //rebaixa o valor enquanto o pai for menor que ele
    print_heap(A);
    max_heapify(A, PARENT(i));
}

/**
 * Insere o novo valor na heap.
 * @param A - ponteiro da árvore;
 * @param key - valor a ser inserido.
 */
void min_heap_insert(ArvHeap * A, int key){
    A->heap_size = A->heap_size + 1;
    A->vector[A->heap_size-1] = INT_MAX;
    heap_decrease_key(A, A->heap_size-1, key);
    print_heap(A);
}
#ifndef ARVORE_H
#define ARVORE_H

//eles estão diferentes do Cormen já que o arranjo começa do zero
inline int LEFT(int i){ return 2*(i+1) - 1; }
inline int RIGHT(int i){ return 2*(i+1); }
inline int PARENT(int i){ return (i+1)/2 - 1; }

typedef struct arvore{
    int lenght; //número de elementos no arranjo;
    int heap_size;//número de elemento do heap que estão no arranjo;
    int * vector;//vetor de valores;
}ArvHeap;

void print_heap(ArvHeap * A);

void build_max_heap(ArvHeap * A);
void max_heapify(ArvHeap * A, int indice);
void heapsort(ArvHeap * A);

int  maximum(ArvHeap * A);
int  heap_extract_max(ArvHeap * A);
void heap_increase_key(ArvHeap * A, int i, int key);
void max_heap_insert(ArvHeap * A, int key);

int  minimum(ArvHeap * A);
int  heap_extract_min(ArvHeap * A);
void heap_decrease_key(ArvHeap * A, int i, int key);
void min_heap_insert(ArvHeap * A, int key);

#endif

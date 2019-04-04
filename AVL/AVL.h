#ifndef AVL_H
#define AVL_H

typedef struct node{
    int info;
    int alt;
    node * esq;
    node * dir;
}Node;

int altura(Node * r);
Node * new_node(int k);
int fb_node(Node * r);
int max(int a, int b);
Node * insere(Node * r, int k);

#endif //AVL_AVL_H

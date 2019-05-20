#ifndef _ARVORE_H
#define _ARVORE_H

inline int min(int a, int b) { return a < b ? a : b;}

void build(int *input, int *segtree, int low, int high, int pos);
int search(int *segtree, int qlow, int qhigh, int low, int high, int pos);

#endif //_ARVORE_H

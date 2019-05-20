#include <limits.h>
#include "arvore.h"

void build(int *input, int *segtree, int low, int high, int pos){
    if(low == high){
        segtree[pos] = input[low];
        return;
    }
    int mid = (low + high)/2;
    build(input, segtree, low, mid, 2 * pos + 1);
    build(input, segtree, mid + 1, high, 2 * pos + 2);
    segtree[pos] = min(segtree[2*pos + 1], segtree[2*pos + 2]);
}

int search(int *segtree, int qlow, int qhigh, int low, int high, int pos){
    if(qlow <= low && high <= qhigh){
        return segtree[pos];
    }
    if(qlow > high || qhigh < low){
        return INT_MAX;
    }
    int mid = (low+high)/2;
    return min(search(segtree, qlow, qhigh, low, mid, 2*pos + 1),
               search(segtree, qlow, qhigh, mid+1, high, 2*pos + 2));
}
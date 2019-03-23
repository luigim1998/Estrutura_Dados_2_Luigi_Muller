#include <stdio.h>

int somatorio(int entrada){
    if (entrada == 1){
        return (1);
    } else {
        return entrada + somatorio(entrada - 1);
    }
}

int main(){
    int entrada;
    scanf("%d", &entrada);
    printf("Somatorio: %d", somatorio(entrada) );
}

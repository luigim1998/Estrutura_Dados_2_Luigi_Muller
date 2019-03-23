#include <stdio.h>

void imprimirCres(int entrada){
    if(entrada>=0){
        imprimirCres(entrada-1);
        printf("%d ", entrada);
    }
}

void imprimirDecres(int entrada){
    if(entrada>=0){
        printf("%d ", entrada);
        imprimirDecres(entrada-1);
    }
}

int main(){
    int entrada;
    scanf("%d", &entrada);
    imprimirCres(entrada);
    printf("\n");
    imprimirDecres(entrada);
}

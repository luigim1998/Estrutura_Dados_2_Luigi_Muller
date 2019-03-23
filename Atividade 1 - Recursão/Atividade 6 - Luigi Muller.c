#include <stdio.h>

int binario(int entrada){
    if(entrada > 1){
        return binario(entrada%2) + binario(entrada/2)*10;
    } else if (entrada == 1){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    int entrada;
    printf("Insira o valor: "); scanf("%d", &entrada);
    printf("Resultado: %d", binario(entrada) );
}

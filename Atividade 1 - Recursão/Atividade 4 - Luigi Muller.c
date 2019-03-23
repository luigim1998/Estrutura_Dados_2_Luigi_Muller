#include <stdio.h>

double potencia(int base, int expoente){
    if(expoente < 0){
        return (1.0/base)*potencia(base, expoente+1);
    } else if (expoente > 0){
        return  base*potencia(base, expoente-1);
    } else {
        return 1;
    }
}

int main(){
    int entrada1, entrada2;
    double resultado;
    printf("Insira a base: ");     scanf("%d", &entrada1);
    printf("Insira o expoente: "); scanf("%d", &entrada2);
    resultado = potencia(entrada1, entrada2);
    printf("Resultado: %lf", resultado);
}

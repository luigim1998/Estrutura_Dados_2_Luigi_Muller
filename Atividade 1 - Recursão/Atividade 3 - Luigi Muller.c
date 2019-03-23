#include <stdio.h>

int multiplicacao(int multiplicando, int multiplicador){
    if(multiplicador < 0){
        return -multiplicando + multiplicacao(multiplicando, multiplicador+1);
    } else if (multiplicador > 0){
        return  multiplicando + multiplicacao(multiplicando, multiplicador-1);
    } else {
        return 0;
    }
}

int main(){
    int entrada1, entrada2, resultado;
    scanf("%d %d", &entrada1, &entrada2);
    resultado = multiplicacao(entrada1, entrada2);
    printf("Multiplicaca2o: %d", resultado);
}

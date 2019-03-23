#include <stdio.h>
#include <stdlib.h>

int soma(int * entrada, int tamanho){
    if(tamanho > 1){
        return entrada[0] + soma(entrada+1, tamanho-1);
    } else {
        return entrada[0];
    }
}

int maximo(int * entrada, int tamanho){
    int aux;
    if(tamanho > 1){
        aux = maximo(entrada+1, tamanho-1);
        if (entrada[0] < aux){
            return aux;
        } else {
            return entrada[0];
        }
    } else {
        return entrada[0];
    }
}

int minimo(int * entrada, int tamanho){
    int aux;
    if(tamanho > 1){
        aux = minimo(entrada+1, tamanho-1);
        if (entrada[0] > aux){
            return aux;
        } else {
            return entrada[0];
        }
    } else {
        return entrada[0];
    }
}

int multiplicacao(int * entrada, int tamanho){
    if(tamanho > 1){
        return entrada[0]*soma(entrada+1, tamanho-1);
    } else {
        return entrada[0];
    }
}

double media(int * entrada, int tamanho){
    if(tamanho > 1){
        return ( entrada[0] + (tamanho-1)*media(entrada + 1, tamanho - 1) )/tamanho;
    } else {
        return entrada[0];
    }
}

int main(){
    int tamanho, cont;
    int * vet;
    printf("Insira o tamanho: "); scanf("%d", &tamanho);
    vet = (int *) malloc(sizeof(int)*tamanho);
    for(cont = 0; cont < tamanho; cont++){
        printf("Insira o valor:"); scanf("%d", vet + cont);
    }
    printf("Soma: %d\n", soma(vet, tamanho) );
    printf("Maximo: %d\n", maximo(vet, tamanho) );
    printf("Minimo: %d\n", minimo(vet, tamanho) );
    printf("Multiplicacao: %d\n", multiplicacao(vet, tamanho) );
    printf("Media: %lf\n", media(vet, tamanho) );
}

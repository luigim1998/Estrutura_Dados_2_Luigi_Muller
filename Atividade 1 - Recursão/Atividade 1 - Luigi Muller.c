#include <stdio.h>

int inverter(int entrada){
    if(entrada > 0){
        printf("%d", entrada%10);
        inverter(entrada/10);
    }
}

int main(){
    int entrada;
    scanf("%d", &entrada);
    inverter(entrada);
}

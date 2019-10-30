

#include <stdio.h>


int main (void){
    int valor;// declaração de variavel
    scanf("%d", &valor);
    int i;
    int rest = 1; // ponto de acumulo do valor
    for (i=1;i<=valor;i++){
        rest *= valor;//repetição por exaustao
    }
    return 0;

}



#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	 setlocale(LC_ALL, "Portuguese");
     system ("color 0a");
	int ntermos, cont, soma;
	int tn, tn1=1, tn2=1;
	printf ("Este programa calcula a série de Fibonacci e a soma do número de termos em questão\n");
	printf ("Insira o número de termos:");
	scanf ("%d", &ntermos);
	if (ntermos==1){
		printf ("1");
	} else {
		if (ntermos==2){
			printf ("1\n 1");
		}
	}
	if (ntermos>=3){
		printf ("1\n1\n");
		for (soma=0, cont=1; cont <= ntermos; cont++){
		tn = tn1 + tn2;
		soma = soma + tn;
		printf ("%d\n", tn);
		tn2 = tn1;
		tn1 = tn;
	}
	printf ("A soma dos termos é de: %d\n", 2 + soma);
	}
	system ("pause");
	return 0;
}

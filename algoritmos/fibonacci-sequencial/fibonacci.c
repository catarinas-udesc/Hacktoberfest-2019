#include <stdio.h>

int main()
  {
    int n,i,fn,fant,fprox;

    printf("\nDigite o valor de n: ");
    scanf("%d", &n);

    i = 0;
    fant = 0;
    fn = 1;

    while (i < n)
      {
        fprox = fant + fn;
        fant = fn;
        fn = fprox;
        i = i + 1;
      }

    printf ("O %d número da sequência de Fibonacci é: %d\n", n, fn);

    return 0;
  }

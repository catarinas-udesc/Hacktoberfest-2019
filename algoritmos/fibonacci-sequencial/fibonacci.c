#include <stdio.h>

int main()
  {
    long long int n,i,fn,fant,fprox;

    printf("\nDigite o valor de n: ");
    scanf("%lld", &n);

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

    printf ("O %lld número da sequência de Fibonacci é: %lld\n", n, fn);

    return 0;
  }

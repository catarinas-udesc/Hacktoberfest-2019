#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int cont;
    struct nodo *prox;
};
typedef struct nodo nodo;

void insere (nodo *nova, nodo *anterior)
{
    nova->prox = anterior->prox;
    anterior->prox = nova;
}

int insere_ordenado(nodo *novo, nodo *raiz)
{
    int x = novo->cont;
    nodo *p;
    p = raiz;
    while (p != NULL && p->cont>x){
        p = p->prox; 
    } 
    insere(novo, p);
}

void imprima (nodo *le) {
    nodo *p;
    for (p = le->prox; p != NULL; p = p->prox)
        printf ("%d\n", p->cont);
}

#include <bits/stdc++.h>
using namespace std;

//estrutura da arvore
typedef struct no{
    int num;
    struct no *esq;
    struct no *dir;
}no;

// função adiciona coloca no nó esquerdo do nodo o menor valor
// e coloca o maior valor no nó direito do nodo
// mantem o valor da raiz original
no* add(no *nodo, no *new_nodo){
    if (nodo == NULL) return new_nodo;
    if(new_nodo->num < nodo->num){
        nodo->esq = add(nodo->esq, new_nodo);
    }
    else {
        nodo->dir = add(nodo->dir, new_nodo);
    }
    return nodo;
}
// print do percurso prefixo
void print_pre(no *nodo){
    if(nodo == NULL) return;
    printf(" %d", nodo->num);
    if(nodo->esq != NULL) print_pre(nodo->esq);
    if(nodo->dir != NULL) print_pre(nodo->dir);
}
// print do percurso infixo
void print_in(no *nodo){
    if(nodo == NULL) return;
    if(nodo->esq != NULL) print_in(nodo->esq);
    printf(" %d", nodo->num);
    if(nodo->dir != NULL) print_in(nodo->dir);
}
// print do percurso posfixo
void print_post(no *nodo){
    if(nodo == NULL) return;
    if(nodo->esq != NULL) print_post(nodo->esq);
    if(nodo->dir != NULL) print_post(nodo->dir);
    printf(" %d", nodo->num);

}

int main(){
    int n;
    no *raiz = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        // aloca espaço na memoria para o novo nodo criado
        no *novo = new no;
        scanf("%d", &novo->num);
        raiz = add(raiz, novo);
    }
    printf("Pre.:");
    print_pre(raiz);
    printf("\n");
    printf("In..:");
    print_in(raiz);
    printf("\n");
    printf("Post:");
    print_post(raiz);
    printf("\n\n");

}

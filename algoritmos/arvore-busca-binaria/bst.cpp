#include <bits/stdc++.h>
using namespace std;

typedef vector <int> Vi;

typedef struct no {
    int v;
    struct no *esq, *dir;
} no;

no* adiciona(no *nodo, no *novo) {
    if (nodo == NULL) return novo;
    if (novo->v < nodo->v) nodo->esq = adiciona(nodo->esq, novo);
    if (novo->v > nodo->v) nodo->dir = adiciona(nodo->dir, novo);
    return nodo;
}

void infixo(no *nodo, Vi &vetor) {
    if (nodo == NULL) return;
    infixo(nodo->esq, vetor);
    vetor.push_back(nodo->v);
    infixo(nodo->dir, vetor);
}
void prefixo(no *nodo, Vi &vetor) {
    if (nodo == NULL) return;
    vetor.push_back(nodo->v);
    prefixo(nodo->esq, vetor);
    prefixo(nodo->dir, vetor);
}
void postefixo(no *nodo, Vi &vetor) {
    if (nodo == NULL) return;
    postefixo(nodo->esq, vetor);
    postefixo(nodo->dir, vetor);
    vetor.push_back(nodo->v);
}

bool procura(no *nodo, int v) {
    if (nodo == NULL) return false;
    if (nodo->v > v && procura(nodo->esq, v)) return true;
    if (nodo->v < v && procura(nodo->dir, v)) return true;
    if (nodo->v == v) return true;
    return false;
}

no* findMax(no *nodo) {
    if (nodo->dir != NULL) return findMax(nodo->dir);
    else return nodo;
}

no* remover(no *nodo, int valor) {
    if (nodo == NULL) return nodo;
    else if (nodo->v > valor) nodo->esq = remover(nodo->esq, valor);
    else if (nodo->v < valor) nodo->dir = remover(nodo->dir, valor);
    else {
        if (nodo->esq == NULL && nodo->dir == NULL) {
            delete nodo;
            nodo = NULL;
        } else if (nodo->esq == NULL) {
            no *aux = nodo;
            nodo = nodo->dir;
            delete aux;
        } else if (nodo->dir == NULL) {
            no *aux = nodo;
            nodo = nodo->esq;
            delete aux;
        } else {
            no *ma = findMax(nodo->esq);
            nodo->v = ma->v;
            nodo->esq = remover(nodo->esq, ma->v);
        }
    }
    return nodo;
}

int main() {
    string input_string;
    no *raiz = NULL;
    while (cin >> input_string) {
        if (input_string == "I") {
            //Inserte operation
            int valor; cin >> valor;

            no *novo = new no;
            novo->v = valor;
            novo->esq = NULL;
            novo->dir = NULL;

            raiz = adiciona(raiz, novo);
        } else if (input_string == "S") {
            //Search operation
            int v; cin >> v;
            if (procura(raiz, v)) printf("%d existe\n", v);
            else printf("%d nao existe\n", v);

        } else if (input_string == "R") {
            //Remove operation
            int v; cin >> v;
            raiz = remover(raiz, v);

        } else if (input_string == "INFIXA") {
            Vi v(0);
            infixo(raiz, v);

            printf("%d", v[0]);
            for (int i = 1; i < v.size(); i++) printf(" %d", v[i]);
            cout << endl;
        } else if (input_string == "PREFIXA") {
            Vi v(0);
            prefixo(raiz, v);

            printf("%d", v[0]);
            for (int i = 1; i < v.size(); i++) printf(" %d", v[i]);
            cout << endl;
        } else if (input_string == "POSFIXA") {
            Vi v(0);
            postefixo(raiz, v);
            
            printf("%d", v[0]);
            for (int i = 1; i < v.size(); i++) printf(" %d", v[i]);
            cout << endl;
        }
    }
}

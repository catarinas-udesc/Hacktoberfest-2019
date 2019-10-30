int busca_sequencial(int chave, int v[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(v[i] == chave){
            return i;
        }
    }
    return -1;
}
#include<stdio.h>

int main(){
  int i,n;
  printf("Qual fatorial deseja calcular?\n");
  scanf("%d",&n);
  int fat=1;
  for(i=1;i<=n;i++){
    fat*=i;
  }
  printf("%d\n",fat);
  return 0;
}

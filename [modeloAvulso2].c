#include <stdio.h>
#include <stdlib.h>

int main(){

// alocacao estatica, para testes 
char vetor_estatico[5];

  printf("preenchendo vetor estatico...\n");
  for(int i = 0; i < 5; i++)
{
  scanf("%d", &vetor_estatico[i]);
}


// alocacao dinamica
int* vetor_dinamico;
vetor_dinamico = (int*) malloc(5*sizeof(int)); // 5 x tamanho de cada item (4 bytes)

printf("preenchendo vetor dinamico...\n");
for(int i = 0; i < 5; i++)
{
    scanf("%d", &vetor_dinamico[i]);
}

for(int i = 0; i < 5; i++);
{
    printf("vetor_estatico[%d] = %d\n", i, vetor_dinamico[i]);
    printf("vetor_dinamico[%d] = %d\n", i, vetor_dinamico[i]);
}
  return 0;
}

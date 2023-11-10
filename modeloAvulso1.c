#include <stdio.h>
#include <stdlib.h>

int main(){

// alocacao estatica
char string[20] = "hello ran";

  printf("insira uma string: ");
  scanf("%s", string);
  printf("%s\n", string);

// alocacao dinamica
char* string_dinamica;
string_dinamica =  (char*) malloc();

  printf("insira outra string: ");
  scanf("%s", string_dinamica);
  printf("%s\n", string_dinamica);

  return 0;
}

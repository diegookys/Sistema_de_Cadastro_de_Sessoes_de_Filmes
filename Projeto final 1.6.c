#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMES 20
#define MAX_SESSOES 40

// ISSO AQ REPRESENTA UMA SESSAO DO FILME
typedef struct{
    char filme[50];
    char horario[10];
    int totalDeCadeiras;
    int cadeirasLivres;
} 

sessaoDeFilme;

// PARTE PARA INSERIR UMA NOVA SESSAO DE FILMES

void inserirSessao(sessaoDeFilme **sessoes, int *numeroDeSessoes){
    sessaoDeFilme novaSessao;

    printf("Nome do filme: ");
    scanf("%s", novaSessao.filme);
    
    printf("Horario da sessao: ");
    scanf("%s", novaSessao.horario);
    
// VERIFICA O LIMITE DE 120 CADEIRAS POR SESSAO
    
    do{
        printf("Quantidade de cadeiras totais(1-120): ");
        scanf("%d", &novaSessao.totalDeCadeiras);

        if(novaSessao.totalDeCadeiras > 120 || novaSessao.totalDeCadeiras <= 0){
            printf("Limite excedido ou valor invalido. Por favor, escolha um valor entre 1 e 120.\n");
        }
    } while(novaSessao.totalDeCadeiras > 120 || novaSessao.totalDeCadeiras <= 0);
    
    novaSessao.cadeirasLivres = novaSessao.totalDeCadeiras;

    (*numeroDeSessoes)++;
    *sessoes = (sessaoDeFilme *)realloc(*sessoes, (*numeroDeSessoes) * sizeof(sessaoDeFilme));
    (*sessoes)[(*numeroDeSessoes) - 1] = novaSessao;

    printf("Sessao cadastrada com sucesso!\n");
}

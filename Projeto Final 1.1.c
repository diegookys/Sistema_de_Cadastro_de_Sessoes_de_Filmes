#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ISSO AQ REPRESENTA UMA SESSAO DO FILME
typedef struct{
    char filme[50];
    char horario[10];
    int totalDeCadeiras;
    int cadeirasLivres;
} SessaoFilme;

// PARTE PARA INSERIR UMA NOVA SESSAO DE FILMES

void inserirSessao(SessaoFilme **sessoes, int *numSessoes) {
    SessaoFilme novaSessao;

    printf("Nome do filme: ");
    scanf("%s", novaSessao.filme);
    printf("Horario da sessao: ");
    scanf("%s", novaSessao.horario);
    printf("Quantidade de cadeiras totais: ");
    scanf("%d", &novaSessao.totalDeCadeiras);
    novaSessao.cadeirasLivres = novaSessao.totalDeCadeiras;

    (*numSessoes)++;
    *sessoes = (SessaoFilme *)realloc(*sessoes, (*numSessoes) * sizeof(SessaoFilme));
    (*sessoes)[(*numSessoes) - 1] = novaSessao;

    printf("Sessao cadastrada com sucesso!\n");

    return 0;
}

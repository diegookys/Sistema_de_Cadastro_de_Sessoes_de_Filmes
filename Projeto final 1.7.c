#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILMES 16
#define MAX_SESSOES 30
#define LIMITE_SESSOES_POR_FILME 6

typedef struct{
    char filme[50];
    char horario[10];
    int totalDeCadeiras;
    int cadeirasLivres;
} sessaoDeFilme;

// VALIDAR SE O FORMATO DO HORARIO ESTA CORRETO (HH:MM)

int validarHorario(const char *horario){
    int horas, minutos;
    if(sscanf(horario, "%d:%d", &horas, &minutos) == 2){
        if(horas >= 0 && horas <= 23 && minutos >= 0 && minutos <= 59){
            return 1;
        }
    }
    return 0;  // Formato inválido ou valores fora do intervalo
}

// CONTA QUANTAS SESSOES TEM PARA O MESMO FILME

int contarSessoesPorFilme(sessaoDeFilme *sessoes, int numeroDeSessoes, const char *filme){
    int contagemSessoes = 0;
    for(int i = 0; i < numeroDeSessoes; i++){
        if(strcmp(sessoes[i].filme, filme) == 0){
            contagemSessoes++;
        }
    }
    return contagemSessoes;
}

// CADASTRA UMA NOVA SESSAO

void inserirSessao(sessaoDeFilme **sessoes, int *numeroDeSessoes){
    sessaoDeFilme novaSessao;

    printf("Nome do filme: ");
    scanf("%s", novaSessao.filme);

    // VERIFICA SE O LIMITE DE SESSOES PARA O MESMO FILME FOI ATINGIDO (LIMITE DE 6)
    
    int contagemSessoes = contarSessoesPorFilme(*sessoes, *numeroDeSessoes, novaSessao.filme);
    if(contagemSessoes >= LIMITE_SESSOES_POR_FILME){
        printf("Limite de sessoes para o filme '%s' atingido.\n", novaSessao.filme);
        return;
    }

    // CODIGO PARA GARANTIR QUE HAJA O FORMATO DO HORARIO CORRETO EM LOOP
    
    do{
        printf("Horario da sessao (HH:MM): ");
        scanf("%s", novaSessao.horario);

        // VERIFICA SE O HORARIO E VALIDO 
        
        if(!validarHorario(novaSessao.horario)){
            printf("ATENCAO! O horario deve seguir o formato HH:MM. Tente novamente.\n");
        }
    } while(!validarHorario(novaSessao.horario));

    // VERIFICA O LIMITE DE 120 CADEIRAS POR SESSAO
    do{
        printf("Quantidade de cadeiras totais (1-120): ");
        scanf("%d", &novaSessao.totalDeCadeiras);

        if(novaSessao.totalDeCadeiras > 120 || novaSessao.totalDeCadeiras <= 0) {
            printf("Limite excedido ou valor invalido! Por favor, escolha um valor entre 1 e 120.\n");
        }
    } while(novaSessao.totalDeCadeiras > 120 || novaSessao.totalDeCadeiras <= 0);

    novaSessao.cadeirasLivres = novaSessao.totalDeCadeiras;

    (*numeroDeSessoes)++;
    *sessoes = (sessaoDeFilme *)realloc(*sessoes, (*numeroDeSessoes) * sizeof(sessaoDeFilme));
    (*sessoes)[(*numeroDeSessoes) - 1] = novaSessao;

    printf("Sessao cadastrada com sucesso!:D\n");
}

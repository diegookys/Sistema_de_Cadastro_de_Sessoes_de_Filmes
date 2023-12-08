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
    int numeroDaSessao;
} sessaoDeFilme;

// VALIDAR SE O FORMATO DO HORARIO ESTA CORRETO (HH:MM)

int validarHorario(const char *horario){
    int horas, minutos;
    if(sscanf(horario, "%d:%d", &horas, &minutos) == 2){
        if(horas >= 0 && horas <= 23 && minutos >= 0 && minutos <= 59){
            return 1;
        }
    }
    return 0;  // FORMATO VALIDO OU VALORES FORA DO INTERVALO (H = 0-23, M = 0-59)
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

    // LIMPAR O BUFFER DA ENTRADA ANTES DE LER O NOME DO FILME
    while(getchar() != '\n');

    printf("Nome do filme: ");
    // USEI FGETS PARA LER A LINHA COMPLETA
    fgets(novaSessao.filme, sizeof(novaSessao.filme), stdin);
    novaSessao.filme[strcspn(novaSessao.filme, "\n")] = '\0'; // REMOVE UM CARACTERE PARA UMA NOVA LINHA

    printf("Digite o numero da sessao (1-30): ");
    while(1){
    
    // VERIFICA SE SAO NUMEROS INTEIROS COM 1 OU 2 DIGITOS NO MAXIMO
    
    if(scanf("%d", &novaSessao.numeroDaSessao) == 1 &&
        novaSessao.numeroDaSessao >= 1 &&
        novaSessao.numeroDaSessao <= MAX_SESSOES &&
        getchar() == '\n'){
        break;
    }else{
        printf("Entrada invalida. Por favor, insira um numero entre 1 e 30: ");
        // LIMPA O BUFFER DA ENTRADA
        
        while(getchar() != '\n');
        }
    }

    // VERIFICA SE O LIMITE DE SESSOES PARA O MESMO FILME FOI ATINGIDO (LIMITE DE 6)
    
    int contagemSessoes = contarSessoesPorFilme(*sessoes, *numeroDeSessoes, novaSessao.filme);
    if(contagemSessoes >= LIMITE_SESSOES_POR_FILME){
        printf("Limite de sessoes para o filme '%s' atingido.\n", novaSessao.filme);
        return;
    }

    // CODIGO PARA GARANTIR QUE HAJA O FORMATO DO HORARIO CORRETO EM LOOP
    
    int formatoHorarioValido;
    do{
        printf("Horario da sessao (HH:MM): ");
        scanf("%s", novaSessao.horario);

        // VERIFICA SE O HORARIO E VALIDO 
        
        if(!validarHorario(novaSessao.horario)){
            printf("ATENCAO! O horario deve seguir o formato HH:MM. Tente novamente.\n");
            formatoHorarioValido = 0;
        }else{
            formatoHorarioValido = 1;
        }
    } while(!formatoHorarioValido);

    // VERIFICA O LIMITE DE 120 CADEIRAS POR SESSAO
    
    do{
        printf("Quantidade de cadeiras totais (1-120): ");

        // VERIFICA SE A ENTRADA E UM NUMERO

        while(scanf("%d", &novaSessao.totalDeCadeiras) != 1){
        printf("Entrada invalida. Por favor, insira um numero entre 1 e 120: ");
        
        while(getchar() != '\n'); // LIMPAR O BUFFER DA ENTRADA
        }

    // VERIFICA SE A ENTRADA E VALIDA OU SE EXCEDEU O LIMITE

    if(novaSessao.totalDeCadeiras > 120 || novaSessao.totalDeCadeiras <= 0){
        printf("Entrada invalida ou excedida. Por favor, insira um numero entre 1 e 120.\n");
        }
    } while(novaSessao.totalDeCadeiras > 120 || novaSessao.totalDeCadeiras <= 0);

    novaSessao.cadeirasLivres = novaSessao.totalDeCadeiras;

    (*numeroDeSessoes)++;
    *sessoes = (sessaoDeFilme *)realloc(*sessoes, (*numeroDeSessoes) * sizeof(sessaoDeFilme));

    
    (*sessoes)[(*numeroDeSessoes) - 1] = novaSessao;
    novaSessao.numeroDaSessao = *numeroDeSessoes;  // ADICIONA O NUMERO DA SESSAO CORRETO

    printf("Sessao cadastrada com sucesso!:D\n");
}

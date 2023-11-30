#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verificacaoDiaSemana(char* diaSemana){

    int respostaDiaSemana;

    if(strcmp(diaSemana,"SEGUNDA-FEIRA") == 0){
        respostaDiaSemana = 0;
    } else if(strcmp(diaSemana,"TERCA-FEIRA") == 0){
        respostaDiaSemana = 0;
    } else if(strcmp(diaSemana,"QUARTA-FEIRA") == 0){
        respostaDiaSemana = 0;
    } else if(strcmp(diaSemana,"QUINTA-FEIRA") == 0){
        respostaDiaSemana = 0;
    } else if(strcmp(diaSemana,"SEXTA-FEIRA") == 0){
        respostaDiaSemana = 0;
    } else if(strcmp(diaSemana,"SABADO") == 0){
        respostaDiaSemana = 0;
    } else if(strcmp(diaSemana,"DOMINGO") == 0){
        respostaDiaSemana = 0;
    } else {
        respostaDiaSemana = 1;
    }

    return respostaDiaSemana;
}

int verificacaoPlacaCarro(char* placaCarro){
    int limitePlaca = strlen(placaCarro);
    int respostaPlaca;

    if((limitePlaca == 7 || limitePlaca == 8)){
        respostaPlaca = 0;
    } else if((limitePlaca != 7 || limitePlaca != 8)){
        respostaPlaca = 1;
    }

    return respostaPlaca;

}

void analisaDasPlacas(char* placaCarro, char* diaSemana){
    int limitePlacaCarro = strlen(placaCarro);
    int limiteDiaSemana =  strlen(diaSemana);

    if(isalpha(placaCarro[0]) && isalpha(placaCarro[1]) && isalpha(placaCarro[2]) && placaCarro[3]=='-' && isdigit(placaCarro[4]) && isdigit(placaCarro[5]) && isdigit(placaCarro[6]) && isdigit(placaCarro[7])){

        if((strcmp(diaSemana,"SABADO")==0) || (strcmp(diaSemana,"DOMINGO")==0)){
            printf("Nao ha proibicao no fim de semana\n");
        } else if((strcmp(diaSemana, "SEGUNDA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '0' || placaCarro[limitePlacaCarro - 1] == '1')){
            printf("%s nao pode circular segunda-feira\n", placaCarro);
        } else if((strcmp(diaSemana, "TERCA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '2' || placaCarro[limitePlacaCarro - 1] == '3')){
            printf("%s nao pode circular terca-feira\n", placaCarro);
        } else if((strcmp(diaSemana, "QUARTA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '4' || placaCarro[limitePlacaCarro - 1] == '5')){
            printf("%s nao pode circular quarta-feira\n", placaCarro);
        } else if((strcmp(diaSemana, "QUINTA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '6' || placaCarro[limitePlacaCarro - 1] == '7')){
            printf("%s nao pode circular quinta-feira\n", placaCarro);
        } else if((strcmp(diaSemana, "SEXTA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '8' || placaCarro[limitePlacaCarro - 1] == '9')){
            printf("%s nao pode circular sexta-feira\n", placaCarro);
        } else {
            for (int i=0;i < limiteDiaSemana;i++){
                    diaSemana[i] = tolower(diaSemana[i]);
                }
                printf("%s pode circular %s\n",placaCarro,diaSemana);
        }

    } else if(isalpha(placaCarro[0]) && isalpha(placaCarro[1]) && isalpha(placaCarro[2]) && isdigit(placaCarro[3]) && isalpha(placaCarro[4]) && isdigit(placaCarro[5]) && isdigit(placaCarro[6])){

        if((strcmp(diaSemana,"SABADO")==0) || (strcmp(diaSemana,"DOMINGO")==0)){
            printf("Nao ha proibicao no fim de semana\n");
        } else if((strcmp(diaSemana, "SEGUNDA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '0' || placaCarro[limitePlacaCarro - 1] == '1')){
            printf("%s nao pode circular segunda-feira\n", placaCarro);
        } else if((strcmp(diaSemana, "TERCA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '2' || placaCarro[limitePlacaCarro - 1] == '3')){
            printf("%s nao pode circular terca-feira\n", placaCarro);
        } else if((strcmp(diaSemana, "QUARTA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '4' || placaCarro[limitePlacaCarro - 1] == '5')){
            printf("%s nao pode circular quarta-feira\n", placaCarro);
        } else if((strcmp(diaSemana, "QUINTA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '6' || placaCarro[limitePlacaCarro - 1] == '7')){
            printf("%s nao pode circular quinta-feira\n", placaCarro);
        } else if((strcmp(diaSemana, "SEXTA-FEIRA") == 0) && (placaCarro[limitePlacaCarro - 1] == '8' || placaCarro[limitePlacaCarro - 1] == '9')){
            printf("%s nao pode circular sexta-feira\n", placaCarro);
        } else {
            for (int i=0;i < limiteDiaSemana;i++){
                    diaSemana[i] = tolower(diaSemana[i]);
                }
                printf("%s pode circular %s\n",placaCarro,diaSemana);
        }

    }else{
        printf("Placa invalida\n");
    }
}

int main(){
    char diaSemana[15];
    char placaCarro[9];

    scanf("%s",placaCarro);
    scanf("%s",diaSemana);

    // Remova o caractere de nova linha da string lida
    if (diaSemana[strlen(diaSemana) - 1] == '\n') {
        diaSemana[strlen(diaSemana) - 1] = '\0';
    }

    if (placaCarro[strlen(placaCarro) - 1] == '\n') {
        placaCarro[strlen(placaCarro) - 1] = '\0';
    }

    int resultadoDiaSemana = verificacaoDiaSemana(diaSemana);
    int resultadoPlacaCarro = verificacaoPlacaCarro(placaCarro);

    if(resultadoPlacaCarro == 0 && resultadoDiaSemana == 0){
        analisaDasPlacas(placaCarro,diaSemana);
    } else if(resultadoPlacaCarro == 0 && resultadoDiaSemana == 1){
        printf("Dia da semana invalido\n");
    } else if(resultadoPlacaCarro == 1 && resultadoDiaSemana == 0){
        printf("Placa invalida\n");
    }else if(resultadoPlacaCarro == 1 && resultadoDiaSemana == 1){
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");
    }

    return 0;
}
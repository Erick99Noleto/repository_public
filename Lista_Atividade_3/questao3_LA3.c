#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char placa_carro[9];
    char diaSemana[15];
    int verificacaoMaiuscula = 1;
    int temHifen = 0;
    scanf("%s",placa_carro);
    scanf("%s",diaSemana);

    int limite_placa = strlen(placa_carro);
    int limite_diaSemana = strlen(diaSemana);

    for (int i = 0; i < limite_diaSemana; i++) {
        if (diaSemana[i] == '-') {
            temHifen = 1;
        }
        if (!isalpha(diaSemana[i]) && diaSemana[i] != '-') {
            verificacaoMaiuscula = 0;
            break;
        }
    }
    /*for (int i = 0; i < limite_diaSemana; i++) {
        if(diaSemana[i] == '-'){
            temHifen = 1;
        }
        if ( !(isupper(diaSemana[i]) && isalpha(diaSemana[i]))  && diaSemana[i] != '-') {
            verificacaoMaiuscula = 0;
            break;
        }
    }*/



    if((limite_placa == 7 || limite_placa == 8) && verificacaoMaiuscula == 1){

        if(isalpha(placa_carro[0]) && isalpha(placa_carro[1]) && isalpha(placa_carro[2]) && placa_carro[3]=='-' && isdigit(placa_carro[4]) && isdigit(placa_carro[5]) && isdigit(placa_carro[6]) && isdigit(placa_carro[7])){

            if ((strcmp(diaSemana, "SABADO") == 0) || (strcmp(diaSemana, "DOMINGO") == 0)) {
                printf("Nao ha proibicao no fim de semana\n");
            } else if ((strcmp(diaSemana, "SEGUNDA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '0' || placa_carro[limite_placa - 1] == '1')) {
                printf("%s nao pode circular segunda-feira\n", placa_carro);
            } else if ((strcmp(diaSemana, "TERCA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '2' || placa_carro[limite_placa - 1] == '3')) {
                printf("%s nao pode circular terca-feira\n", placa_carro);
            } else if ((strcmp(diaSemana, "QUARTA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '4' || placa_carro[limite_placa - 1] == '5')) {
                printf("%s nao pode circular quarta-feira\n", placa_carro);
            } else if ((strcmp(diaSemana, "QUINTA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '6' || placa_carro[limite_placa - 1] == '7')) {
                printf("%s nao pode circular quinta-feira\n", placa_carro);
            } else if ((strcmp(diaSemana, "SEXTA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '8' || placa_carro[limite_placa - 1] == '9')) {
                printf("%s nao pode circular sexta-feira\n", placa_carro);
            } else{
                for (int i=0;i < limite_diaSemana;i++){
                    diaSemana[i] = tolower(diaSemana[i]);
                }

                printf("%s pode circular %s\n",placa_carro,diaSemana);
            }

        }else if (isalpha(placa_carro[0]) && isalpha(placa_carro[1]) && isalpha(placa_carro[2]) && isdigit(placa_carro[3]) && isalpha(placa_carro[4]) && isdigit(placa_carro[5]) && isdigit(placa_carro[6])) {

            if ((strcmp(diaSemana, "SABADO") == 0) || (strcmp(diaSemana, "DOMINGO") == 0)) {
                printf("Nao ha proibicao no fim de semana\n");
            } else if ((strcmp(diaSemana, "SEGUNDA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '0' || placa_carro[limite_placa - 1] == '1')) {
                printf("%s nao pode circular segunda-feira\n", placa_carro);
            } else if ((strcmp(diaSemana, "TERCA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '2' || placa_carro[limite_placa - 1] == '3')) {
                printf("%s nao pode circular terca-feira\n", placa_carro);
            } else if ((strcmp(diaSemana, "QUARTA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '4' || placa_carro[limite_placa - 1] == '5')) {
                printf("%s nao pode circular quarta-feira\n", placa_carro);
            } else if ((strcmp(diaSemana, "QUINTA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '6' || placa_carro[limite_placa - 1] == '7')) {
                printf("%s nao pode circular quinta-feira\n", placa_carro);
            } else if ((strcmp(diaSemana, "SEXTA-FEIRA") == 0) && (placa_carro[limite_placa - 1] == '8' || placa_carro[limite_placa - 1] == '9')) {
                printf("%s nao pode circular sexta-feira\n", placa_carro);
            } else{
                for (int i=0;i < limite_diaSemana;i++){
                    diaSemana[i] = tolower(diaSemana[i]);
                }
                printf("%s pode circular %s\n",placa_carro,diaSemana);
            }

        }

    }else if((limite_placa != 7 || limite_placa != 8) && verificacaoMaiuscula == 1){
        printf("Placa invalida\n");
    }else if((limite_placa == 7 || limite_placa == 8) && verificacaoMaiuscula == 0){
        printf("Dia da semana invalido\n");
    }else if((limite_placa != 7 || limite_placa != 8) && verificacaoMaiuscula == 0){
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

int main(){
    char stringExemplo[20];
    int quantDeCaracteres;

    printf("Insira uma string: ");
    scanf("%s",stringExemplo);

    quantDeCaracteres = fgets(stringExemplo,20,stdin);

    printf("A quantidade eh %d\n",quantDeCaracteres);
    return 0;
}
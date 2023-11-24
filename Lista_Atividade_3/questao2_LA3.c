#include <stdio.h>
#include <string.h>


//Esta função define quais são os valores dos algorismos romanos em decimal

int valoresRomanosEmDecimal(char valores){
    int equivalente;

    if(valores == 'I'){
        equivalente = 1;
    }else if(valores == 'V'){
        equivalente = 5;
    }else if(valores == 'X'){
        equivalente = 10;
    }else if(valores == 'L'){
        equivalente = 50;
    }else if(valores == 'C'){
        equivalente = 100;
    }else if(valores == 'D'){
        equivalente = 500;
    }else if(valores =='M'){
        equivalente = 1000;
    }

    return equivalente;
}

//Esta função converterá o número romano em decimal

int convercaoDeRomanoParaDecimal(char* pRomano){

    int limiteNumRomano = strlen(pRomano);
    /*declarando a variável LimiteNumRomano como int(inteiro), quando o computador utlizar o strlen para ler 
    o pRomano (ponteiro == string [string essa que vai ser o número romano digitado]) ela irá ler até o '\0'
    e mostrar em números, a quantidade de caracteres usados até chegar no \0*/

    int resultadoEmDecimal=0;

    for(int i=0; i < limiteNumRomano; i++){
        /*Neste if o computador irá comparar cada caracter dentro da string. Caso o caracter A (anterior) 
        seja maior ou igual ao caracter B (posterior), então irá somar o caracter A com o resultadoEmDecimal*/
        if(valoresRomanosEmDecimal(pRomano[i]) >= valoresRomanosEmDecimal(pRomano[i+1])){
            resultadoEmDecimal += valoresRomanosEmDecimal(pRomano[i]);
        }else{//Caso o anterior não seja verdeiro, entõ irá subtrair o caracter A com o resultadoEmDecimal
            resultadoEmDecimal -= valoresRomanosEmDecimal(pRomano[i]);
        }
    }

    return resultadoEmDecimal;
}

int main(){
    char numeroRomano[20];
    scanf("%s",numeroRomano);

    printf("O numero em decimal eh: %d",convercaoDeRomanoParaDecimal(numeroRomano));

    return 0;
}
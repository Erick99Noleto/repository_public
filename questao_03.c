#include<stdio.h>
#include<stdlib.h>
int main(){

    
    int senha, confirmarSenha;

    scanf("%d",&senha);
    printf("Senha confirmada: %d\n",senha);

    do{
        scanf("%d",&confirmarSenha);

        if(confirmarSenha == senha){
            printf("senha valida!\n");
            break;
        }else{
            printf("senha invalida!\n");
        }
    }while(1);
    return 0;
}
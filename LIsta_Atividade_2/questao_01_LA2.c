#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int numeros[10];

    for(int n=0; n < 10; n++){
        scanf("%d",&numeros[n]);
    }

    for(int n=0; n < 10; n++){
        if(n == 9){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        } 
    }

    for(int n=0; n < 9; n++){
        numeros[n] = numeros[n+0] + numeros[n+1];
        if(n == 8){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        }
    }

    for(int n=0; n < 8; n++){
        numeros[n] = numeros[n+0] + numeros[n+1];
        if(n == 7){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        }
    }

    for(int n=0; n < 7; n++){
        numeros[n] = numeros[n+0] + numeros[n+1];
        if(n == 6){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        }
    }

    for(int n=0; n < 6; n++){
        numeros[n] = numeros[n+0] + numeros[n+1];
        if(n == 5){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        }
    }

    for(int n=0; n < 5; n++){
        numeros[n] = numeros[n+0] + numeros[n+1];
        if(n == 4){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        }
    }

    for(int n=0; n < 4; n++){
        numeros[n] = numeros[n+0] + numeros[n+1];
        if(n == 3){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        }
    }

    for(int n=0; n < 3; n++){
        numeros[n] = numeros[n+0] + numeros[n+1];
        if(n == 2){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        }
    }

    for(int n=0; n < 2; n++){
        numeros[n] = numeros[n+0] + numeros[n+1];
        if(n == 1){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        }
    }

    for(int n=0; n < 1; n++){
        numeros[n] = numeros[n+0] + numeros[n+1];
        if(n == 0){
            printf("%d\n",numeros[n]);
        }else{
            printf("%d ",numeros[n]);
        }
    }

    return 0;
}
#include <stdio.h>
#include <math.h>

int main(){
    int mes;
    double aporteMensal;
    double taxaJuros;
    double montante[204];

    scanf("%d",&mes);
    scanf("%lf",&aporteMensal);
    scanf("%lf",&taxaJuros);

    for(int n = 1; n <= mes; n++){
        double base = (1 + taxaJuros);
        montante[n] = aporteMensal * (1 + taxaJuros) * ((pow(base,n) - 1) /taxaJuros);
        printf("Montante ao fim do mes %d: R$ %.2lf\n",n,montante[n]);
    }
    
    return 0;
}
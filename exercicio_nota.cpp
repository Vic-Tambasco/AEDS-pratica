#include <stdio.h>

int main(){

    float idade, renda, patraso, patraso2;
    int hcredit;

    printf("\n\tescreva sua idade: ");
    scanf("%f", &idade);
    
    printf("\n\tqual sua renda mensal?: ");
    scanf("%f", &renda);
   
    printf("\n\tVoce tem nome negativado? 1 para sim 0 para nao: ");
    scanf("%d", &hcredit);

    printf("\n\tnumero de parcelas atrasadas atualmente: ");
    scanf("%f", &patraso);

    printf("\n\tnumero de parcelas atrasadas em 2 anos?: ");
    scanf("%f",&patraso2);
   

    if(idade < 0){
        printf("\n\tErro");
    }else{
        if(renda < 0){
            printf("\n\tErro");
        }else{
            if(patraso < 0){
                printf("\n\tErro");
            }else{
                if(patraso2 < 0){
                    printf("\n\tErro");
                }else{
                     if(renda < 2000.0 || hcredit == 1 || 70 < idade || idade < 18){
                      printf("\n\tEmprestimo negado");
                     }else{
                        if( 2000.00  < renda && renda < 4999.99 && patraso <2 && patraso2 <2 ){
                         printf("\n\tEmprestimo de baixo valor(ate 5000.0 reais)");
                        }else{
                            if( 5000.00 < renda && renda < 9999.99 && patraso == 0 && patraso2 <= 4 ){
                             printf("\n\tEmprestimo de medio valor (ate 20000.00 reais)");
                            }else{
                                 if(renda > 10000.00 && patraso == 0 && patraso2 == 0){
                                 printf("\n\tEmprestimo de alto valor(acima de 20000.00 reais)");
                                 }       
               
     }
            }
            }
        }
    }  }
            }

    return 0;
}
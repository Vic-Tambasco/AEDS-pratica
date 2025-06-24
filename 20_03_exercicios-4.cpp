#include <stdio.h>

int main(){
 
 int ano;

 printf("\n\tEscolha um ano: ");
 scanf("%d", &ano);
 
 if((ano)%(4) == 0 || (ano)%(400) == 0){
    printf("\n\tEsse ano e bissexto");
 }else{
    if((ano) % (100) > 0){
        printf("\n\tEsse ano nao e bissexto");
        }
     }

    return 0;
}
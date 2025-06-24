#include <iostream>
#include <stdio.h>

int main(){
float nota;

printf("\n\tEscreva uma nota:");
scanf("%f", &nota);

if(nota>=0.0 && nota<=2.9){
    printf("\n\tF");
}else{
   if(nota>=3.0 && nota<=4.9){
      printf("\n\tD");
   }else{
       if(nota>=5.0 && nota<=6.9){
        printf("\n\tC");
       }else{
         if(nota>=7.0 && nota<=8.9){
            printf("\n\tB");
         }else{
            if(nota>=9 && nota<=10.0){
                printf("\n\tA");
            }else{
                if(nota<0){
                printf("\n\tErro");
                }else{
                   if(nota>10){
                    printf("\n\tErro");
                }
            }
            }
            }
        }
        }
       }
    
return 0;

}


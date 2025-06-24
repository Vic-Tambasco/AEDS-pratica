
#include <stdio.h>

int main (){
float celsius, fahrenheit;

celsius = 0;
fahrenheit = 0;

printf("\n\tCovertor de Celsius para Fahrenheit");
printf("\n\t-----------------------------------------");
printf("\n\t    celsius       fahrenheit    ");
printf("\n\t-----------------------------------------");


while(celsius <= 100){
    fahrenheit = (celsius * 1.8) + 32;
    printf("\n           %6.2f C        %6.2f F ", celsius, fahrenheit);
    celsius = celsius + 5;
    
}

printf("\n\t------------------------------------------\n");

    return 0;
}

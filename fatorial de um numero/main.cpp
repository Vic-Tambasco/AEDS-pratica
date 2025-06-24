/* 
 * File:   main.cpp
 * Author: victoria
 *
 * Created on April 24, 2025, 7:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int fatorial, numero, operacao;
    cout << "escolha um numero para que seja calculado o seu fatorial: "<< endl;
    cin >> numero;
    
    if(numero < 0 ){
        cout << "nao e possivel calcular o fatorial de um numero negativo" << endl;
    }else{
    
    fatorial = 1;
    
    while(numero > 0){
    cout << numero << "*";
    
    fatorial = fatorial * numero;
    numero = numero -1;
         
    }
    cout << endl;
    cout << "o fatorial e:" << fatorial << endl;
    }
    return 0;
}


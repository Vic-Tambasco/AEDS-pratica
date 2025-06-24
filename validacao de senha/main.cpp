/* 
 * File:   main.cpp
 * Author: victoria
 *
 * Created on April 24, 2025, 6:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/*
 * Esse codigo tem o intuito de validar uma senha, que apos 3 tentativas para de aceitar as tentativas de senha e caso a senha estiver certa ele gera uma mensagem de parabens
 */
int main(int argc, char** argv) {
    int i;
    string senha;

    i = 1;

    cout << "digite qual a senha correta, voce tem 3 tentativas" << endl;
    cin >> senha;

    while (senha != "algoritmo123" && i <= 3) {
        cout << "a senha " << senha << " esta incorreta, tente novamente" << endl;

        if (i < 3) {
            cin >> senha;
        }
        i = i + 1;
    }

    if (senha == "algoritmo123") {
        cout << "parabens a senha esta correta!!" << endl;
    } else {
        cout << "voce excedeu o numero de tentativas maximas" << endl;
    }



    return 0;
}


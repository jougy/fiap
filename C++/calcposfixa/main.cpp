/*
################################################
#                 Trabalho 01                  #
#   Turma: 2ECR                                #
#   Nomes:                      RM:            #
#   André Giovannettti          83939          #
#   João Paulo T. do Val        83615          #
#   Luiz Silva                  82164          #
#   Matheus Candido             81117          #
################################################
*/

//Bibliotecas
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include<locale>
#include <string>
#include <vector>
using namespace std;

//Declaração de variaveis
string input;
int topo = 0;

int main(){
    setlocale(LC_ALL, "");

//Inicio
    cout << "calculadora posfixa\ndigite a expressao: ";

//Leia String
    cin >> input;

//Declarando vetor com o tamanho igual ao tamanho da string
    vector <float> pilha(input.size());

//Analisando todos os caracteres da expressao
    for (int i = 0; i < input.size(); i++){

//O Caracter é digito?
    //Se sim:
        if (isdigit(input[i])){
            float digito = (int)input[i] - 48;
            pilha[topo] = digito;
            topo++;
        }

    //Se nao:
        else{
            topo--;
            float dado1 = pilha[topo];
            topo--;
            float dado2 = pilha[topo];
            float resultado;

        //Realisa uma das 4 operações

            if (input[i] == '+'){
                resultado = dado1 + dado2;
            }
            else if(input[i] == '-'){
                resultado = dado2 - dado1;
                }
            else if(input[i] == '*'){
                resultado = dado2 * dado1;
            }
            else if(input[i] == '/'){
                resultado = dado2 / dado1;
            }
        //Empilhando o resultado
            pilha[topo] = resultado;
            topo++;
        }
    }
// Mostrando o resultado na tela
    cout << "resultado: ";
    topo--;
    float resultado = pilha[topo];
    cout << resultado;
    return 0;
//FIM
}

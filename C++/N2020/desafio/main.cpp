#include <iostream>
#include<locale>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include <array>
#include <chrono>
#include <string>

using namespace std;

#define N_PAC 100
#define N_MED 1440
#define NC 20
#define NC_LINHA 80

struct medida{
    char hora[NC];
    int sistole, diastole, frequencia,oxigenacao;
};

void BubbleSort(medida medidas[], int num){
    int i,j;
    medida aux;
    bool troca=true; /* supõe realizar troca */
    for (i=0;i<num-1 && troca==true; i++){
        troca=false; /* supõe não realizar troca */
        for (j=0; j < (num-i-1);j++){
            if (medidas[j].frequencia < medidas[j+1].frequencia){
                aux=medidas[j];
                medidas[j]=medidas[j+1];
                medidas[j+1]=aux;
                troca=true; /*registra que houve troca na iteração*/
            }
        }
    }
}


void InsertionSort(medida medidas[], int num){
    int j,i;
    medida eleito;
    for(i = 1; i < num; i++) {
        eleito = medidas[i];
        j = i-1;
        while (j >= 0 && medidas[j].frequencia < eleito.frequencia) {
            medidas[j+1] = medidas[j];
            j = j-1;
        }
        medidas[j+1] =  eleito;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    FILE *arq;
    int i,np,nm,n,resp,maior,cont;
    char auxS[NC], auxD[NC],auxF[NC], auxO[NC], aux[NC_LINHA];

    int num_medidas[9] = {1440, 8640, 16000, 32000, 48000, 64000, 80000, 96000, 128000};
    for(int i = 0; i < 9; i++){
        int tamanho = num_medidas[i];
        medida *medidas;
        medidas = (medida*)malloc(sizeof(medida)*200000);
        string nomeArquivo = to_string(tamanho) + ".txt";
        char nomeArquivoChar[1024];
        strcpy(nomeArquivoChar, nomeArquivo.c_str());
        arq = fopen(nomeArquivoChar, "rt");
        if (arq == NULL)  {
            printf("Problemas na abertura do arquivo\n");
            return -1;
            }
        nm= 0;
        fscanf(arq, "%s%s%s%s%s", medidas[nm].hora, auxS,auxD,auxF,auxO);
        while (nm<tamanho) {
           // cout << "entrando no while(nm<tamanho)\n";
            fscanf(arq, "%s%s%s%s%s", medidas[nm].hora, auxS,auxD,auxF,auxO);
            medidas[nm].sistole= atoi(auxS);
            medidas[nm].diastole= atoi(auxD);
            medidas[nm].frequencia= atoi(auxF);
            medidas[nm].oxigenacao= atoi(auxO);
            nm++;
        //    cout << "fim do while\n";
        }
        auto start = chrono::steady_clock::now();
        cout << "ordenando...\n";
        //BubbleSort(medidas, tamanho);
        InsertionSort(medidas, tamanho);
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    }
        system("pause");
     return 0;
    }



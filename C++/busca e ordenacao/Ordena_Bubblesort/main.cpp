#include <iostream>
#include<locale>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define TRUE 1
#define FALSE 0

#define TAMANHO 8


void bubblesort(int vetor[],int n)
{
int aux,i,j;
int troca=TRUE; /* supõe realizar troca */
for (i=0;i<n-1 && troca==TRUE; i++){
    troca=FALSE; /* supõe não realizar troca */
    for (j=0;j<n-i-1;j++){
        if (vetor[j]>vetor[j+1]){
            aux=vetor[j];
            vetor[j]=vetor[j+1];
            vetor[j+1]=aux;
            troca=TRUE; /*registra que houve troca na iteração*/
            }
        }
    }
}

int main(){

  setlocale(LC_ALL, "");
  FILE *arq;
  int i;
  char dado[20];
  int vetor[TAMANHO];

  arq = fopen("arq_dados.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return -1;
  }
  i = 0;
  while (i<TAMANHO) {
      fscanf(arq, "%s", dado);
      vetor[i] = atoi(dado);
      i++;
  }
  fclose(arq);

   for (i=0; i<TAMANHO;i++)
        cout << vetor[i] << "\t";

   bubblesort(vetor, TAMANHO);

   cout<<"\n\nVetor Ordenado\n";
   for (i=0; i<TAMANHO;i++)
        cout << vetor[i] << "\t";
   cout << "\n\n";
    return 0;
}

#include <iostream>
#include<locale>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define TAMANHO 8

void insertionsort(int vetor[],int n)
{
int eleito, j,i;
for(i = 1; i <n; i++) {
	eleito = vetor[i];
	j = i-1;
	while (j >= 0 && vetor[j] > eleito) {
		vetor[j+1] = vetor[j];
		j = j-1;
		}
	vetor[j+1] =  eleito;
	}
}

int main(){

  setlocale(LC_ALL, "");
  FILE *arq;
  int i;
  char dado[20];
  int vetor[TAMANHO];


  arq = fopen("arq_dados.txt", "rt");
  if (arq == NULL)  {
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

  insertionsort(vetor, TAMANHO);

  cout<<"\n\nVetor Ordenado\n";
  for (i=0; i<TAMANHO;i++)
        cout << vetor[i] << "\t";

  return 0;
}


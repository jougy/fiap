#include <iostream>
#include<locale>
#include<stdio.h>
#include<stdlib.h>
//#include<cstring>

using namespace std;

#define TAMANHO 8


int busca_binaria(float cpf[TAMANHO], float chave){
int i_baixo = 0,i_alto = TAMANHO-1, i_medio;
int achou = 0;
int	pos = -1;
int num_comparacao = 1;
while( achou != 1 && i_baixo <=  i_alto)	{
	i_medio = (i_baixo + i_alto)/2;
	if (chave == cpf[i_medio])  {
		pos = i_medio;
		achou =1;
		}
	else {
        num_comparacao++;
		if (chave < cpf[i_medio])
			i_alto = i_medio-1;
		else
			i_baixo = i_medio+1;
        }
	}
	return(num_comparacao);
}

int busca_sequencial(float vet[], float chave){
int i;
int num_comparacao = 0;
for(i=0; i<TAMANHO && vet[i]!=chave; i++)
    num_comparacao++;
return(num_comparacao);
}


int main()
{
  setlocale(LC_ALL, "");
  FILE *arq;
  int i;
  char cpf[16];
  float vet[TAMANHO], chave;
  int n, maior=0;

  arq = fopen("RM1024.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return -1;
  }
  i = 0;
  while (i<TAMANHO) {
      fscanf(arq, "%s", cpf);
      vet[i] = atof(cpf);
	  cout << "Linha " << i << ": " <<vet[i] <<endl;
      i++;
  }
  fclose(arq);

for (i=0; i<TAMANHO; i++){
    chave= vet[i];
 //   cout << "chave procurada " << chave <<endl;
    n = busca_sequencial (vet,chave);
    if (n > maior)
        maior = n;
}
cout << "\n\nNúmero de comparações busca sequencial: " << maior<<endl;

maior = 0;
for (i=0; i<TAMANHO; i++){
    chave= vet[i];
 //   cout << "chave procurada " << chave <<endl;
    n = busca_binaria(vet,chave);
    if (n > maior)
        maior = n;
}
cout << "\n\nNúmero de comparações busca binária: " << maior<<endl;
    return 0;
}

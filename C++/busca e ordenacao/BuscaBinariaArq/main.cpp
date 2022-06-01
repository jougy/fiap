#include <iostream>
#include<locale>
#include<stdio.h>
#include<stdlib.h>
# include <ctype.h>


using namespace std;

#define TAMANHO 30
#define NC 50

struct reg{
    int rm;
    char nome[NC];
    float media;
};

typedef struct reg TipoAluno;

int busca_binaria(TipoAluno vet[], int num, int chave){
int i_baixo = 0,i_alto = num-1, i_medio;
int achou = 0;
int	pos = -1;

while( achou != 1 && i_baixo <=  i_alto)	{
	i_medio = (i_baixo + i_alto)/2;
	if (chave == vet[i_medio].rm)  {
		pos = i_medio;
		achou =1;
		}
	else {
		if (chave < vet[i_medio].rm)
			i_alto = i_medio-1;
		else
			i_baixo = i_medio+1;
        }
	}
	return(pos);
}


int main()
{
  setlocale(LC_ALL, "");
  FILE *arq;

  char rmS[11],mediaS[5];
  TipoAluno aluno[TAMANHO];
  int n, chave;


  arq = fopen("registrosOrdenados.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
  }
  else{
    n=0;
    fscanf(arq, "%s%s%s", rmS, aluno[n].nome,mediaS);  //apresenta o cabeçalho da tabela
    cout << "RM \t Nome \t\tMédia \n";

      while (fscanf(arq, "%s%s%s", rmS, aluno[n].nome,mediaS)!= EOF)
      {
          aluno[n].rm = atoi(rmS);
          aluno[n].media =  atof(mediaS);
          cout << aluno[n].rm << " \t " << aluno[n].nome <<"\t\t"<< aluno[n].media << endl;
          n++;
      }
      fclose(arq);

    cout << "\n\nDigite o RM do aluno que deseja procurar: ";
    cin >> chave;
    n = busca_binaria(aluno,n, chave);
    if(n== -1)
        cout << "Registro não encontrado \n";
    else
        cout << "\n nome do aluno: " << aluno[n].nome <<" tem média: "<<aluno[n].media <<endl;
  }
return 0;
}


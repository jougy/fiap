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

int busca_sequencial(TipoAluno vet[], int num, int chave){
int i,pos=-1;
int achou = 0;
for(i=0; i<num && achou == 0; i++){
    if(vet[i].rm ==chave){
        achou = 1;
        pos= i;
    }
}
cout << "busca feita comparou " << i << " registros do arquivo\n";
return(pos);
}


int main()
{
  setlocale(LC_ALL, "");
  FILE *arq;

  char rmS[11],mediaS[5];
  TipoAluno aluno[TAMANHO];
  int n, chave;


  arq = fopen("registros.txt", "rt");
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
    n = busca_sequencial (aluno,n, chave);
    if(n== -1)
        cout << "Registro não encontrado \n";
    else
        cout << "\n nome do aluno: " << aluno[n].nome <<" tem média: "<<aluno[n].media <<endl;
  }
return 0;
}


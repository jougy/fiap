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

int busca_sequencial_exaustiva(TipoAluno vet[], int num, float chave, TipoAluno encontrados[]){
int i, ne=0;
for(i=0; i<num; i++){
    if(vet[i].media == chave){
        encontrados[ne] = vet[i];
        ne++;
    }
}
return ne;
}



int main()
{
  setlocale(LC_ALL, "");
  FILE *arq;

  char rmS[11],mediaS[5];
  TipoAluno aluno[TAMANHO], encontrados[TAMANHO];
  int n,i ,ne;
  float nota;

  arq = fopen("registros.txt", "rt");
  if (arq == NULL)              // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
  }
  else{
    n=0;
    fscanf(arq, "%s%s%s", rmS, aluno[n].nome,mediaS);  //apresenta o cabeçalho da tabela
    cout << rmS << " \t " << aluno[n].nome <<"\t\t "<< mediaS << endl;

      while (fscanf(arq, "%s%s%s", rmS, aluno[n].nome,mediaS)!= EOF)
      {
          aluno[n].rm = atoi(rmS); // converte string (ASCII) em inteiro
          aluno[n].media =  atof(mediaS); // converte string (ASCII) em float
          cout << aluno[n].rm << " \t " << aluno[n].nome <<"\t \t"<< aluno[n].media << endl;
          n++;
      }
      fclose(arq);


    cout << "\n\nDigite o nota que deseja procurar: ";
    cin >> nota;
    ne = busca_sequencial_exaustiva(aluno, n, nota, encontrados);
    cout << "\n   Alunos que tiveram nota procurada: \n";
    for(i=0; i< ne; i++){
        cout << encontrados[i].rm <<"  "<< encontrados[i].nome<< endl;
    }
  }

return 0;
}


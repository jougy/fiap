#include <iostream>
#include<locale>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include <array>


using namespace std;

#define N_PAC 100
#define N_MED 48
#define NC 20
#define NC_LINHA 80


struct paciente{
    char id[NC];
    int idade;
    char sexo[5], hipertensao[4];
};

typedef struct paciente TipoPaciente;

struct medida{
    char hora[NC];
    int sistole, diastole, frequencia,oxigenacao;
};

typedef struct medida TipoMedidas;

/*******************************************************************
TAREFA 1

    Inserir m�todo de busca mais adequado e eficiente que encontre
    no vetor de pacientes o paciente com ID passado como par�metro
********************************************************************/

int PosicaoDoPaciente(TipoPaciente pacientes[], int num, char id[]){
// Supondo que o array est� ordenado
    // Busca binaria
    int idBuscado = atoi(id);
    cout << "id: "<< id << endl;
    int iBaixo = 0;
    int iMedio;
    int iAlto = num-1;
    bool achou = false;
    int pos = -1;
    while(!achou && iBaixo <= iAlto){
        iMedio = (iBaixo + iAlto)/2;
        cout << "iBaixo: " << iBaixo << " iMedio: " << iMedio << " iAlto: " << iAlto << " pos: " << pos << " id: "<< pacientes[iMedio].id << endl;
        if(idBuscado == atoi(pacientes[iMedio].id)){
            pos = iMedio;
            achou = true;
        }
        else{
            if(idBuscado < atoi(pacientes[iMedio].id)){
                iAlto = iMedio-1;
            }
            else{
                iBaixo = iMedio+1;
            }
        }
    }
    cout << "pos: "<< pos << endl;
    return pos;
}


/******************************************************************************
TAREFA 2

    Inserir m�todo de busca mais adequado e eficiente no arquivo de medidas
    que apresente todas as medidas com pressao sist�lica passada como par�metro
*******************************************************************************/
void ApresentaMedidas(TipoMedidas medidas[], int num, int sistole){
    // Cabe�alho
    cout << "Horario\tSistole(mmHg)\tDiastole(mmHg)\tPulsacao(bat/min)\tOxigenacao(%)" << endl;

    //Busca Sequencial Exaustiva
    for(int i = 0; i < num; i++){
        if(medidas[i].sistole == sistole){
            cout << medidas[i].hora << "\t" << medidas[i].sistole << "\t" << medidas[i].diastole << "\t" << medidas[i].frequencia << "\t" << medidas[i].oxigenacao << endl;
        }
    }
}


/******************************************************************************
TAREFA 3

    Inserir m�todo de ordena��o mais adequado e eficiente que fa�a a ordena��o do
    vetor de medidas em ordem decrescente de pulsa��o.
*******************************************************************************/

void OrdenaMedidasPorPulsacao(TipoMedidas medidas[], int num){
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

int main(){

setlocale(LC_ALL, "");
FILE *arq;
int i,np,nm,n,resp,maior,cont;
char id[NC];
char auxS[NC], auxD[NC],auxF[NC], auxO[NC], aux[NC_LINHA];

TipoMedidas medidas[N_MED];
TipoPaciente pac[N_PAC];

arq = fopen("ListaConvenio.txt", "rt");
if (arq == NULL)  {
     printf("Problemas na abertura do arquivo\n");
     return -1;
    }
else{
      np = 0;
      fgets(aux, NC_LINHA,arq);
      cout <<aux<<endl;
      while (fscanf(arq, "%s%s%s%s", pac[np].id, aux,pac[np].sexo,pac[np].hipertensao) != EOF){
          pac[np].idade= atoi(aux);
          np++;
          }
   fclose(arq);
   do{
        cout << "Pacientes que j� enviaram o arquivo de medi��o:\n \tID1030\tTD1562\n ";
        cout <<"Qual ID de paciente que quer analisar: ";
        cin.getline(id, 80);
        cout << "Paciente a consultar: " << id<< endl;

 /******************************************************************************************
 TAREFA 4

    Chama a fun��o desenvolvida na TAREFA 1 para a obter a posi��o do registro do paciente
    no vetor de pacientes passando id como par�metro
*******************************************************************************************/
        n = PosicaoDoPaciente(pac, N_PAC, id);

        cout <<"ID: "<< pac[n].id<< " idade: "<< pac[n].idade << " sexo: "<<pac[n].sexo<< " hipertens�o: " <<pac[n].hipertensao <<endl;
        system("pause");


        strcat(id,".txt");
        arq = fopen(id, "rt");
        if (arq == NULL)  {
            printf("Problemas na abertura do arquivo\n");
            return -1;
            }
          nm= 0;
          fscanf(arq, "%s%s%s%s%s", medidas[nm].hora, auxS,auxD,auxF,auxO);
          while (nm<N_MED) {
              fscanf(arq, "%s%s%s%s%s", medidas[nm].hora, auxS,auxD,auxF,auxO);
              medidas[nm].sistole= atoi(auxS);
              medidas[nm].diastole= atoi(auxD);
              medidas[nm].frequencia= atoi(auxF);
              medidas[nm].oxigenacao= atoi(auxO);
              nm++;
          }
          fclose(arq);

          do{
            system("cls");
            cout << "1) Maior press�o sist�lica registrada e demais medidas e o hor�rio em que ocorreram.\n" ;
            cout << "2) Verifica se oxigena��o esteve abaixo de 92% e quantas medidas isso ocorreu ao longo do dia.\n";
            cout << "3) Ordenar o arquivo em ordem decrescente de frequ�ncia card�aca.\n";
            cout << "4) Encerrar an�lise do paciente.\n";
            cout << "\t Digite a op��o desejada: " ;
            cin >> resp;
            cin.ignore();
            switch(resp){
              case 1:
/******************************************************************************************
 TAREFA 5

   Inserir trecho de programa que encontra a maior medida de press�o sist�lica do paciente
*******************************************************************************************/
                      maior = 0;
                      for(int i = 0; i < N_MED; i++){
                          if(medidas[i].sistole > maior){
                              maior = medidas[i].sistole;
                          }
                      }

/******************************************************************************************
 TAREFA 6

    chama a fun��o desenvolvida na TAREFA 2 para apresentar todas os registros de medida
    onde foram registradas press�o sist�lica encontrada na TAREFA 5
*******************************************************************************************/
                      ApresentaMedidas(medidas, N_MED, maior);
                      system("pause");
                      break;
              case 2:
 /******************************************************************************************
 TAREFA 7

   Inserir trecho de programa conta todas as medidas de oxigena��o menores do que 92%
   do paciente
*******************************************************************************************/
                      cont = 0;
                      for(int i = 0; i < N_MED; i++){
                        if(medidas[i].oxigenacao < 92){
                            cont++;
                        }
                      }

                      if(cont == 0){
                        cout << "N�o ocorreram medidas de oxigena��o menores do que 92%" << endl;
                      }
                      else{
                        cout << "Ocorreram " << cont << " medidas menores do que 92%" << endl;
                      }
                      system("pause");
                      break;
              case 3:
 /******************************************************************************************
 TAREFA 8

    chama a fun��o desenvolvida na TAREFA 3 para ordenar os registros no vetor
    de medidas em ordem descrescente de pulsa��o implementado na TAREFA 3
*******************************************************************************************/
                      OrdenaMedidasPorPulsacao(medidas, N_MED);
                      cout<<"\n\nVetor Ordenado\n";
                      for (i=0; i<20;i++)
                        cout << "press�o: "<< medidas[i].sistole <<":" << medidas[i].diastole<< " frequencia: "<< medidas[i].frequencia<< " hora: "<< medidas[i].hora<<endl;
                      system("pause");
                      break;
              case 4: cout << "Encerrando a avalia��o do paciente. Gerar atualiza��o do prontu�rio!\n\n";
                      break;
              default: cout << "op��o inv�lida\n";
              }
            } while (resp!=4);
        cout << "Deseja analisar mais um paciente? (1-sim /Qualquer outro valor - n�o): ";
        cin >> resp;
        cin.ignore();
      }while(resp == 1);
    }
    return 0;

}

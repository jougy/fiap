/*
-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Integrantes:					    RM:
Andre Carlini Giovannet 			83939
João Paulo Taddeo do Val 			83615
Luiz Ricardo Maia Gomes Silva 		82164
Marcelo Silva Soares 				83561
Matheus Augusto de Paiva Cândido 	81117
=-==-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/



#include <iostream>
#include <locale>

using namespace std;

#include <stdlib.h>


#define NM 3  //número de medidas registradas para cada sensor
#define NC 30  // número de caracteres para armazenar as coordenadas
int tempoirriga;
int minutos = 0;
int horas = 7;


struct Sensor{
    int hashcode;
    char coordenada[NC];
    int medida[NM];
};
typedef struct Sensor TipoSensor;

#include "TipoABBSensor.h"          // Tarefa 1
#include "TipoFilaCoordenadas.h"    //Tarefa 2

void geraFila(TipoArvore  p, TipoFilaCoordenadas *ini, TipoFilaCoordenadas *fim)
{   // Implemente aqui essa função (DICA: use algum método para percorrer a ABB)
    if(p->dir != NULL){
        geraFila(p->dir, ini, &*fim);
    }
    if(p->dado.medida[0] < 20 || p->dado.medida[1] < 20 || p->dado.medida[2] < 20){
        enqueue(&*ini, &*fim, p->dado.coordenada);
    }
    if(p->esq != NULL){
        geraFila(p->esq, &*ini, &*fim);
    }

}

void atualizaHorario(int *horas, int *minutos, int t){
    *minutos += t;
    if(*minutos > 59){
        *horas += *minutos/60;
        *minutos = *minutos%60;
    }
    if(*horas > 23){
        *horas -= 24;
    }
}


int main()   {

setlocale(LC_ALL, "");
TipoArvore tree;
tree = NULL;
TipoFilaCoordenadas ini, fim;
int opcao, dt, n=0;
init(&ini, &fim);
TipoSensor s;
char hashcode[5];
char coord[NC];
int i,hashcodeInt;

char hc[9][NC] = {"47o55’42”W,21o00’35”S", "47o55’42”W,21o00’35”S","47o55’39”W,21o00’37”S", "47o55’44”W,21o00’39”S",
    "47o55’40”W,21o00’40”S", "47o55’32”W,21o00’34”S", "47o55’28”W,21o00’34”S","47o55’28”W,21o00’38”S", "47o55’33”W,21o00’39”S"};

for (i=0; i<9; i++){
            hashcode[0] = hc[i][6];
            hashcode[1] = hc[i][7];
            hashcode[2] = hc[i][17];
            hashcode[3] = hc[i][18];
            hashcode[4] = '\0';
            hashcodeInt = atoi(hashcode);
            strcpy(s.coordenada,hc[i]);
            s.hashcode = hashcodeInt;
            insere(&tree, s);
}
do {
    cout <<endl;
    cout << " 1- inserir mais 1 sensor \n 2- Lista Ordem Descrescente  \n 3- Atualiza Medidas\n";
    cout << " 4- Faz a irrigação \n 5- Consulta medidas de 1 local  \n 0- Sair\n";
    cin >> opcao;
    cin.ignore();
    switch(opcao){
        case 0:
            cout << "******** Irrigação Inteligente Encerrando ***************" << endl;
            break;
        case 1:
            cout << " Digite coordenadas do sensor a ser inserido: ";
//Lê do teclado as coordenadas do sensor e gera hash code
//insere na ABB o registro do sensor
            char coordenada[NC];
            cin >> coordenada;
            hashcode[0] = coordenada[6];
            hashcode[1] = coordenada[7];
            hashcode[2] = coordenada[17];
            hashcode[3] = coordenada[18];
            hashcode[4] = '\0';
            hashcodeInt = atoi(hashcode);
            strcpy(s.coordenada, coordenada);
            s.hashcode = hashcodeInt;
            insere(&tree, s);
            break;
        case 2:
            cout <<"\n******************* Lista Ordem Descrescente **********"<<endl;
// implemente essa função no arquivo header TipoABBSensor.h
// A função deve apresentar hash code e coordenada de cada sensor
            lista_em_ordemDesc(tree);
            cout <<"*********************************************************"<<endl;
            break;
        case 3:
            atualizaMedidas(tree, n); //implementado em TipoABBSensor.h
            n++;
            if (n==3){
                cout << "Gera uma fila com as coordenadas dos sensores \n";
//faz a chamada da função geraFila() implementada no início deste arquivo
                cout << "Fila gerada: \n";
                geraFila(tree, &ini, &fim);
                n=0;
            }
            break;
        case 4:
            cout << "Inicia irrigação buscando coordenadas na fila com as coordenadas dos sensores \n";
            if (isEmpty(ini,fim))
                cout << "Não foi ainda gerada fila de locais para irrigação\n";
            else{
//Retira 1 local da fila e pergunta o tempo de irrigação a ser aplicada no dia
//Repete a ação anterior até que a fila seja esvaziada
                while (!isEmpty(ini,fim)){
                    char coordenadaFila[30] = "";
                    dequeue(&ini, &fim, coordenadaFila);
                    cout << "Coordenadas: " ;
                    for(int i = 0; i <= NC; i++){
                        cout << coordenadaFila[i];
                    }
                    cout << "\ntempo de irrigação a ser aplicado (minutos): ";
                    cin >> tempoirriga;


                    cout << "Horário de início: " << horas << "h" << minutos;
                    atualizaHorario(&horas, &minutos, tempoirriga);
                    cout << "\tHorário de término: " << horas << "h" << minutos << "\n\n";
                }
            }
            break;
        case 5:
            cout << "hash code \t Coordenada\n";
            lista_em_ordemDesc(tree);
            cout << "escolha o hash code do sensor que deseja consultar as últimas medidas do solo: ";
            cin >> hashcodeInt;
// implemente a função consulta no arquivo header TipoABBSensor.h
            if (!consulta(tree, hashcodeInt))
                cout << "Não há sensor identificado com esse código\n";
            break;
        default: cout << "Opção inválida\n";
            }

}while (opcao !=0);


return 0;
}

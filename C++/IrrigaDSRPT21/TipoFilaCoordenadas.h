#include <cstring>
/* declaracao do no */
	struct noF {
        char dado[NC];       //tipo do elemento da pilha
        struct noF *prox;
	};

/*Definição do tipo de dado pilha */
	typedef struct noF* TipoFilaCoordenadas;

void init(TipoFilaCoordenadas *ini, TipoFilaCoordenadas *fim)
{
*ini  = NULL;
*fim = NULL;
}

int isEmpty(TipoFilaCoordenadas ini,TipoFilaCoordenadas fim)
{
    if ((ini == NULL) && (fim == NULL))
        return(1);
    else
        return(0);
}


void enqueue( TipoFilaCoordenadas *ini, TipoFilaCoordenadas *fim, char v[NC])
{
TipoFilaCoordenadas novo;
novo=(TipoFilaCoordenadas ) malloc (sizeof(struct noF));
if (novo==NULL)
	 cout << "Fila Cheia \n";
else  {
     strcpy(novo->dado, v);
	 //novo->dado= v;
	 novo->prox=NULL;
	 if (isEmpty(*ini, *fim)){
	     *ini = novo;
	     }
	 else{
	     (*fim)->prox= novo;
	     }
        *fim=novo;
	}
	cout << v << endl;

}

int dequeue( TipoFilaCoordenadas *ini, TipoFilaCoordenadas *fim, char v[NC])
{
    TipoFilaCoordenadas aux = *ini;
    if (isEmpty(*ini, *fim)){
   // cout << "Dequeue if" << endl;
        return 0;
    }
    else{
      //  cout << "Dequeue else"<< endl;
        //cout << "v antes de mudar: " << v << endl;
        strcpy(v, aux->dado);
       // cout << "v: " << v;
        *ini = aux->prox;
        if (*ini == NULL)
         //   cout << "if" << endl;
            *fim = NULL;
           // cout << "fim: " << *fim << endl;
        free(aux);
      //  cout << "v final: " << v << endl;
        return 1;
    }

}

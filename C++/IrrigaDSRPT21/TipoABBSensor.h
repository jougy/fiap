struct noInt {
	   Sensor dado;
	   struct noInt *esq,*dir;
	   };

typedef struct noInt* TipoArvore;

void insere(TipoArvore *p, Sensor info)
{
    TipoArvore novo;
    if (*p==NULL){
        novo=(TipoArvore) malloc(sizeof(struct noInt));
        if (novo!=NULL){
        novo->dado = info;
        novo->dir = NULL;
        novo->esq = NULL;
        *p=novo;
        }
    }
    else{
        if (info.hashcode < (*p)->dado.hashcode){
            insere(&(*p)->esq,info);
        }
        else{
            insere(&(*p)->dir,info);
        }
    }
}


// Essa função está correta apenas depois de alterar o dado da ABB para ser Registro do Sensor
void atualizaMedidas(TipoArvore  p, int i)
{
    if (p!=NULL){
        if(p->esq!=NULL){
            atualizaMedidas(p->esq,i);
        }
        cout << "atualiza medida do sensor com coordenada: " << p->dado.coordenada << endl;
        cout << "Medida de umidade: ";
        cin >> p->dado.medida[i];
        if(p->dir!=NULL){
            atualizaMedidas(p->dir,i);
        }
    }
}

int consulta(TipoArvore p, int info)
{
//Implemente essa função

    if(p->dir != NULL){
        if(consulta(p->dir, info)){
            return 1;
        }
    }
    if(info == p->dado.hashcode){
        cout << p->dado.medida[0] << " " << p->dado.medida[1] << " " << p->dado.medida[2] << endl;
        return 1;
    }
    if(p->esq != NULL){

        if(consulta(p->esq, info)){
            return 1;
        }
    }

    return 0;
}

void lista_em_ordemDesc(TipoArvore p){
    if(p->dir != NULL){
        lista_em_ordemDesc(p->dir);
    }
    cout << p->dado.hashcode << " " << p->dado.coordenada << endl;
    if(p->esq != NULL){
        lista_em_ordemDesc(p->esq);
    }
}




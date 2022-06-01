#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct pilha Pilha;

Pilha * pilha_cria(void);
void pilha_libera(Pilha * p);
void pilha_push(Pilha * p, int a);
int pilha_pop(Pilha * p);
int pilha_vazia(Pilha * p);

struct elemento
{
int info;
struct elemento * prox;
};
typedef struct elemento Elemento;
struct pilha
{
Elemento * topo;
};
Pilha * pilha_cria(void)
{
Pilha * p = (Pilha *) malloc(sizeof(Pilha));
p->topo = NULL;
return p;
}
int pilha_vazia(Pilha * p)
{
return (p->topo == NULL);
}
void pilha_push(Pilha * p, int a)
{
Elemento * novo = (Elemento *)malloc(sizeof(Elemento));
assert(novo != NULL);
novo->info = a;
novo->prox = p->topo;
p->topo = novo;
}
int pilha_pop(Pilha * p)
{
Elemento * t;
int a;
assert(!pilha_vazia(p));
t = p->topo;
a = t->info;
p->topo = t->prox;
free(t);
return a;
}
void pilha_libera(Pilha * p)
{
Elemento *t, * q = p->topo;
while (q != NULL)
{
t = q->prox;
free(q);
q = t;
}
free(p);
}

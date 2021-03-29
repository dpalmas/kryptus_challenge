/*
 ============================================================================
 Name        : Questão 2.
 Author      : Davi Josue Palmas
 Version     : 1.0.0
 Copyright   : Kryptus
 Description : Desafio Kryptus
 ============================================================================
 */

#include <stdio.h>

typedef void (*funcaoImpressao)  (void *inf);
typedef  int (*funcaoComparacao) (void *, void *);

struct Noh
{
    struct Noh *anterior;	
    void *info;
    struct Noh *proximo;
};

struct DLista
{
   struct Noh *primeiro;
   struct Noh *ultimo;
   int tamanho;
   funcaoComparacao fc;
};

struct DLista* criarLista(funcaoComparacao pfc)
{
  struct DLista *descritor;

  descritor = (struct DLista *) malloc(sizeof(struct DLista));
  descritor->primeiro   = NULL;
  descritor->ultimo     = NULL;
  descritor->tamanho = 0;
  descritor->fc         = pfc;

  return descritor;
}

int vaziaListaDinamica(struct DLista *lista)
{
   return(lista->tamanho == 0);
}

/* Função insere ordenado: insere elemento em ordem. */
void insereOrdenado(struct DLista *lista, void *valor)
{
   struct Noh *novo;
   struct Noh *anterior = NULL; /* ponteiro para elemento anterior */
   struct Noh p = lista; /* ponteiro para percorrer a lista */
   
   /* procura a posição de inserção */
   while(p != NULL && p->info < valor)
   {
      anterior = p;
      p = p->proximo;
   }

   /* cria novo elemento */
   novo = (struct Noh *) malloc(sizeof(struct Noh));
   novo->info = valor;

   /* encadeia elemento */
   if (anterior == NULL)
   {
      /* insere elemento no início */	   
      novo->proximo = lista;
      lista = novo;
   }else{
      /* insere elemento no meio da lista */	   
      novo->proximo = anterior->proximo;
      anteriro->proximo = novo;
   return lista;   
}

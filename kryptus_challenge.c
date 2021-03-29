/*
 ============================================================================
 Name        : Questão 1.
 Author      : Davi Josue Palmas
 Version     : 1.0.0
 Copyright   : Kryptus
 Description : Desafio Kryptus
 ============================================================================
 */

include <stdio.h>

typedef void (*funcaoImpressao)  (void *inf);
typedef  int (*funcaoComparacao) (void *, void *);

/* Estrutura de um nó da lista. */
struct Noh
{
    struct Noh *anterior;	
    void *info;
    struct Noh *proximo;
};

/* Estrutura da lista. */
struct DLista
{
   struct Noh *primeiro;
   struct Noh *ultimo;
   int tamanho;
   funcaoComparacao fc;
};

/* Cria uma lista dinâmica. */
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

/* put */
void adicionarInfo(struct DLista *lista, void *novaInfo){

   struct Noh *novo;

   novo = (struct Noh *) malloc(sizeof(struct Noh));

   lista->tamanho++;

   novo->info = novaInfo;
   novo->proximo = NULL;

   if(lista->primeiro == NULL)
   {
      lista->primeiro = novo;
   } else {
      lista->ultimo->proximo = novo;
   }

   lista->ultimo = novo;
}

/* Verifica se a lista está vazia. */
int vaziaListaDinamica(struct DLista *lista)
{
   return(lista->tamanho == 0);
}

/* remove */
void removerInfo(struct DLista *lista, void *info){

   struct Noh *atual, *anterior;

   if (lista == NULL)
       return;

   anterior   = NULL;
   atual = lista->primeiro;

   while(atual != NULL){

       if (lista->fc(atual->info, info) == 0){

           if (atual == lista->primeiro){
             lista->primeiro = atual->proximo;

           } else if(atual == lista->ultimo){
              lista->ultimo = anterior;
              anterior->proximo = NULL;
           } else{
               anterior->proximo = atual->proximo;
           }

           lista->tamanho--;
           free(atual);
           break;
       }

       anterior = atual;
       atual = atual->proximo;

   }
}

int insere_lista_inicio(struct DLista *lista, void *novaInfo)
{
  struct Noh *novo;

  novo = (struct Noh *) malloc(sizeof(struct Noh));
  if (novaInfo == NULL)
      return 0;
  if(novo == NULL)
      return 0;
  novo->info = novaInfo;
  novo->proximo = (*novaInfo);
  *novaInfo = novo;
  return 1;
}

int insere_lista_final(struct DLista *lista, void *novaInfo)
{
  struct Noh *novo;
  struct Noh *aux;
  novo = (struct Noh *) malloc(sizeof(struct Noh));
  aux = (struct Noh *) malloc(sizeof(struct Noh));
  if (novaInfo == NULL)
      return 0;
  if(novo == NULL)
      return 0;
  novo->info = novaInfo;
  novo->proximo = NULL;
  if((*novaInfo) == NULL) { //lista vazia: insere início
      *novaInfo = novo;
  } else {
    aux = *novaInfo;
    while(aux->proximo != NULL) {
      aux = aux->proximo;
    }
    aux->proximo = novo;
  }
  return 1;
}

/* display */
void mostrarLista(struct DLista *lista, funcaoImpressao fi){

   struct Noh *atual;

   atual = lista->primeiro;

   while (atual != NULL){

        /* imprime a informacao do no atual da lista */
        fi(atual->info);
        /* faz o atual apontar para o proximo no da lista*/
        atual = atual->proximo;
   }
}

struct DLista *controiLista(void *vet, int tam)
{
   struct DLista *novaLista; /* variável auxiliar para criar a nova lista */	
   novaLista = criarDescritor();
   struct Noh *p; /* variável auxiliar para percorrer a lista */
   int i;
   novaLista = NULL;

   for(i = n - 1; i >= 0; i--)
   {
      p = (struct Noh *) malloc(sizeof(struct Noh));
      p->proximo = novaLista;
      p->info = v[i];
      novaLista = p;
   }
   return novaLista;
}

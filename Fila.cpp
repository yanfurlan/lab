#include <malloc.h>
#include <iostream>
#include <string.h>
#include "Fila.h"

using namespace std;

#define MSG_FILAVAZIA "\nA Fila está vazia\n"

Fila *criaFila(){
  Fila* f = (Fila*) malloc(sizeof(Fila));

  f->primeiro = NULL;
  f->ultimo = NULL;
  f->qtdItens = 0;

  return f;
}

void liberaFila(Fila *f){
  free(f);
}

int estahVazia(Fila *f){
  return f->qtdItens == 0;
}

void enfileirar(Fila *f, int i, char n[]){
  Item *novoItem = (Item*) malloc(sizeof(Item));
  novoItem->numero = i;
  strcpy(novoItem->nome, n);

  if (estahVazia(f)){
    novoItem->prox = NULL;
  }else{
    novoItem->prox = f->ultimo;
  }

  f->ultimo = novoItem;
  f->qtdItens++;
}

int desenfileirar(Fila *f, char *nomeDesenfileirado[], int *nDesenfileirado){
  Item *i;

  if(!estahVazia(f)){
    i = f->primeiro;
    f->primeiro = i->prox;
    strcpy(*nomeDesenfileirado, i->nome);
    *nDesenfileirado = i->numero;
    free(i);
  }else{
    fprintf(stderr, MSG_FILAVAZIA);
    return 0;
  }
  f->qtdItens--;
  return 1;
}

void mostrarFila(Fila *f){
  Item *i = f->primeiro;

  while(i != f->ultimo){
    cout << " [Numero: " << i->numero << ", Nome: " << i->nome << "] |";
    i = i->prox;
  }
  cout << " [Numero: " << i->numero << ", Nome: " << i->nome << "]" << endl;
}

int quantidadeFila(Fila *f){
  return f->qtdItens;
}

void mostrarCaracteristicas(Fila *f){
  cout << " [Numero: " << f->primeiro->numero << ", Nome: " << f->primeiro->nome << "]" << endl;
}
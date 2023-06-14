#include <stdlib.h>
#include <stdio.h>

// defino o tamanho da tabela como 59, pois levo em consideração que será adicionado 30 elementos, 30 x 2 = 60 e procuro o numero primo mais proximo
#define TAM 59


/* Para implementação do encadeamento separado, cada espaço da tabela hash terá uma lista para tratar colisões*/
typedef struct no{
    int info;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void inicializarLista(Lista *list){
    list->inicio = NULL;
    list->tam = 0;
}
void iniciaTabela(Lista *tab){
    for(int i = 0; i < TAM; i++){
        inicializarLista(&tab[i]);
    }
}


void inserirLista(Lista *list, int valor){
    No *novo = malloc(sizeof(No));

    if(novo != NULL){
        novo->info = valor;
        novo->proximo = list->inicio;
        list->inicio = novo;
    } else {
        return;
    }
}

int buscaLista(Lista *list, int valor){
    No *aux = list->inicio;
    while(aux != NULL && aux->info != valor){
        aux = aux->proximo;
    }
    if(aux != NULL){
        return aux->info;
    } else {
        return 0;
    }
}

int buscaTabela(Lista* tab, int valor){
    int id = funcaoHash(valor, TAM);

    return buscaLista(&tab[id], valor);
}



int funcaoHash(int valor, int tamanhoTab){
    return valor % tamanhoTab;
}

void inserirTabela(Lista *tab, int valor){
    int id = funcaoHash(valor, TAM);
    inserirLista(&tab[id], valor);  
}
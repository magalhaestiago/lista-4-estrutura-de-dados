#include <stdio.h>
#include <stdlib.h>

#define TAM 59



typedef struct produto{
    int codigoUnico;
    char *nomeProduto;
    float precoProduto;
    int qtdDisponiveis;
};

typedef struct no{
    struct produto p;
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

void inserirLista(Lista *list, struct produto prod){
    No *novo = malloc(sizeof(No));

    if(novo != NULL){
        novo->p = prod;
        novo->proximo = list->inicio;
        list->inicio = novo;
    } else {
        return;
    }
}

void inserirTabela(Lista *tab, struct produto prod){
    int id = funcaoHash(prod.codigoUnico, TAM);
    inserirLista(&tab[id], prod);
}


int buscaLista(Lista *list, int codigoUnicoBusca){
    No *aux = list->inicio;
    while(aux != NULL && aux->p.codigoUnico != codigoUnicoBusca){
        aux = aux->proximo;
    }
    if (aux != NULL){
        return aux->p.codigoUnico;
    } else {
        return 0;
    }
}

int buscaTabela(Lista *tab, int codigoUnicoBusca){
    int id = funcaoHash(codigoUnicoBusca, TAM);

    return buscaLista(&tab[id], codigoUnicoBusca);
}

int funcaoHash(int valor, int tamanhoTab){
    return valor % tamanhoTab;
}

void imprimirInformacoesLista(Lista * list, struct produto prod){
    No *aux = list->inicio;
    int cont = 0;

    while(aux != NULL && aux->p.codigoUnico != prod.codigoUnico){
        aux = aux->proximo;
    }
    if(aux != NULL){
    printf("\n===============================\n");
    printf("%d\n", prod.codigoUnico);
    printf("%s\n", prod.nomeProduto);
    printf("%.2f", prod.precoProduto);
    printf("%d\n\n", prod.qtdDisponiveis);
    }
}


float maior(struct produto *prod, int tamanhoTab){
    float maior = 0;
    for(int i = 0; i < tamanhoTab; i++){
        if(prod[i].precoProduto > maior){
            maior = prod[i].precoProduto;
        }
    }
    return maior;
}
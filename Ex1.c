#define TAM 59
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// struct cidade com apenas o campo nome, como pedido na questão
typedef struct cidade{
    char* nomeCidade;
};

// Inicializar a tabela com strings vazias nos nomes das cidades
void inicializarTabela(struct cidade cidadesceara[]){
    for(int i = 0; i < TAM; i++){
        strcpy(cidadesceara[i].nomeCidade, "");
    }
}

// Função hash mais utilizada, pegando o resto da divisão entre o valor pelo tamanho da tabela
int funcaoHash(int valor){
    return valor % TAM;
}

// Função auxiliar para calcular o tamanho de uma string, sem utilizar a lib "string.h"
int tamanhoString(char *str){
    int length = 0;
    while(str[length] != "\0"){
        length++;
    }

    return length;
}


// Função que retorna uma função HASH para string, calculando a posição de um character pelo seu valor na tabela ASCII, assim evitando problemas com repetição de letras e colisão como as palavras "cama" e "maca"
int funcaoHashString(char *str){
    int tamanho = tamanhoString(str);
    int hash = 0;

    for(int i = 0; i < tamanho; i++){
        hash += str[i] * (i+1);
    }
    return hash % TAM;
}

// ALgoritmo de inserção utilizando para tratar colisão o elemetno será adicionado na proxima posição vazia
void inserir(struct cidade cidadesCeara[], struct cidade c1){
    int id = funcaoHashString(c1.nomeCidade);
    while(tamanhoString(cidadesCeara[id].nomeCidade) > 0){
        id = funcaoHash(id + 1);
    }
    cidadesCeara[id] = c1;
}

// ALgoritmo de busca similar ao algoritmo de inserção, se ele não for encontrado na posição da sua função Hash, será procurado na proxima
int busca(struct cidade cidadesCeara[], char *nomeBusca){
    int id = funcaoHashString(nomeBusca);

    while(tamanhoString(cidadesCeara[id].nomeCidade) > 0){
        if(cidadesCeara[id].nomeCidade == nomeBusca){
            return id;
        } else {
            id = funcaoHash(id + 1);
        }
    }
}


// Ordem alfabetica com bubble sort
void ordenarAlfabetico(struct cidade *cidadesCeara){
    
    for(int i = 0; i < TAM -1; i++){
        for(int j = 0; j < TAM - 1; j++){
            if(strcmp(cidadesCeara[j].nomeCidade, cidadesCeara[j+1].nomeCidade > 0)){
                char *aux = cidadesCeara[j].nomeCidade;
                cidadesCeara[j].nomeCidade = cidadesCeara[j + 1].nomeCidade;
                cidadesCeara[j+1].nomeCidade = aux;
            }
            
        }
    }
    
}


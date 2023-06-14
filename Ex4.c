#include <stdio.h>
#include <stdlib.h>

// defino o tamanho da tabela como 59, pois levo em consideração que será adicionado 30 elementos, 30 x 2 = 60 e procuro o numero primo mais proximo
#define TAM 59

typedef struct aluno{
    char *nome;
    int matricula;
};

void inicializarTabela(struct aluno *lista, int tamanhoTab){
    for(int i = 0; i < tamanhoTab; i++){
        lista[i].matricula = -1;
    }
}

int funcaoHash(int valorMatricula, int tamanhoTab){
    return valorMatricula % tamanhoTab;
}

int inserirAluno(struct aluno *lista, struct aluno a1){
    int id = funcaoHash(a1.matricula, TAM);
    lista[id] = a1;

    return id;
}


int buscaAluno(struct aluno *lista, int matriculaAluno){
    int idBusca = funcaoHash(matriculaAluno, TAM);

    return idBusca;
}

int removerAluno(struct aluno *lista, int matriculaAluno){
    int idRemover = funcaoHash(matriculaAluno, TAM);

    lista[idRemover].matricula = -1; // se o valor da matricula = -1, o elemento sera desconsiderado na tabela
    lista[idRemover].nome = "";
}


float mediaAlunos(struct aluno *lista, int tamanhoTab){
    int totalAlunosMatriculados = 0,  soma = 0;
    for(int i = 0; i < tamanhoTab; i++){
        if(lista[i].matricula != -1){
            totalAlunosMatriculados++;
            soma += lista[i].matricula;
        }
    }
    return soma / totalAlunosMatriculados;
}


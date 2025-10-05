#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct{
    int R, F;
    int vet[TAM];
}filavet;

void enfileira(int valor, filavet *p){
    if(p->R==TAM-1){
        printf("Fila Cheia");
        exit(0);
    }
    p->R++;
    p->vet[p->R]=valor;
}

int desenfileira(filavet *p){
    int aux;
    if(p->F == TAM){
        printf("Fila Vazia");
        exit(1);
    }
    aux=p->vet[p->F];
    p->F++;
    return aux;
}

int main(){
    filavet fila;
    int valor;
    fila.R=-1;
    fila.F=0;

    for(int i=0;i<TAM;i++){
        printf("Digite o valor a ser enfileirado: ");
        scanf("%d",&valor);
        enfileira(valor,&fila);
    }

    for(int i=0;i<TAM;i++){
        printf("\n%d",desenfileira(&fila));
    }
}
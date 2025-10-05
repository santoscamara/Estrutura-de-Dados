#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct{
    int topo;
    int vet[TAM];
}pilhavet;

void empilha(int valor, pilhavet *p){
    if(p->topo==TAM-1){
        printf("Pilha Cheia");
        exit(0);
    }
    p->topo++;
    p->vet[p->topo]=valor;
}

int desempilha(pilhavet *p){
    int aux;
    if(p->topo<0){
        printf("Pilha Vazia!");
        exit(1);
    }
    aux=p->vet[p->topo];
    p->topo--;
    return aux;
}

int main(){
    pilhavet pilha;
    int valor;
    pilha.topo=-1;

    for(int i=0;i<TAM;i++){
        printf("\nDigite o valor a ser empilhado: ");
        scanf("%d",&valor);
        empilha(valor,&pilha);
    }

    for(int i=0;i<TAM;i++){
        printf("%d\t",desempilha(&pilha));
    }
    return 0;
}
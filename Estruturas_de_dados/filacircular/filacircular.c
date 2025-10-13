#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct{
    int R, F, quant;
    int vet[TAM];
}filavet;

void enfileira(int valor, filavet *p){
    if(p->quant==TAM){
        printf("Fila Cheia");
        exit(0);
    }
    if(p-> R == TAM-1)
        p->R=0;
    else
        p->R++;
    p->vet[p->R]=valor;
    p->quant++;
}

int desenfilera(filavet *p){
    int elem;
    if(p->quant==0){
        printf("Fila Vazia");
        exit(1);
    }
    elem =p->vet[p->F];
    if(p->F == TAM-1)
        p->F=0;
    else
        p->F++;

    p->quant--;
    return elem;
}

int main(){
    filavet filacircular;
    int valor;
    filacircular.R=-1;
    filacircular.F=0;
    filacircular.quant=0;

    for(int i=0;i<TAM;i++){
        printf("\nDigite o valor a ser enfileirado: ");
        scanf("%d",&valor);
        enfileira(valor,&filacircular);
    }

    for(int i=0;i<TAM;i++){
        printf("\n%d",desenfilera(&filacircular));
    }

    return 0;
    
}
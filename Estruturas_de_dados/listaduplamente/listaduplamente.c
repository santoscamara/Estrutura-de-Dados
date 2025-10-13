#include <stdio.h>
#include <stdlib.h>

typedef struct dupla{
    int dado;
    struct dupla *elink, *dlink;
}no;

no *crialde(int n){
    no *ini=NULL, *p, *aux=NULL;
    int valor;

    for(int i=1;i<=n;i++){
        printf("\nDigite o valor %d da lista: ", i);
        scanf("%d",&valor);

        p = (no*)malloc(sizeof(no));
        p->dado = valor;
        p->elink = NULL;
        p->dlink = ini;

        if(ini != NULL){
            ini->elink=p;
        }
        else{
            aux=p; // guarda o primeiro nó
        }
        ini=p; //ultimo nó passa a ser o atual
    }
    return aux; // retorna o primeiro nó
}

void escrevelista(no *p){
    while (p != NULL){
        printf("%d\t", p->dado);
        p=p->elink;
    }
}

int main(){
    no *primeira;
    int n;

    printf("Criando uma lista duplamente encadeada");
    do{
        printf("\nEntre com o numero de nois: ");
        scanf("%d",&n);
    }while(n<0);

    primeira = crialde(n);

    if(primeira != NULL){
        printf("\nLista Criada:\n");
        escrevelista(primeira);
    }
    else{
        printf("\nLista vazia");
    }
    return 0;
}
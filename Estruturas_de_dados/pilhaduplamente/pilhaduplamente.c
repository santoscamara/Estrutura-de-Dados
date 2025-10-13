#include <stdio.h>
#include <stdlib.h>

typedef struct dupla{
    int dado;
    struct dupla *elink, *dlink;
}no;

no *crialde(int n){
    no *ini, *p;
    int valor;
    ini=NULL;
    for(int i =1;i<=n;i++){
        printf("\nDigite o valor %d da pilha: ",i);
        scanf("%d",&valor);

        p=(no*)malloc(sizeof(no));
        p->dado=valor;
        p->elink=NULL;
        
        if(ini != NULL)
            ini->elink=p;
        p->dlink=ini;
        ini=p;
    }
    return ini;
}

void escrevelista(no *p){
    while(p != NULL){
        printf("%d\t",p->dado);
        p=p->dlink;
    }
}

int main(){
    no *primeira;
    int n;
    printf("Criando uma pilha duplamente encadeada: ");
    do{
        printf("\n Entre com o numero de nois: ");
        scanf("%d",&n);

    }while(n<0);

    primeira=crialde(n);

    if(primeira != NULL){
        printf("\nLista Criada");
        printf("\n");
        escrevelista(primeira);

    }
    else
        printf("\nLista Vazia");
    
    
    return 0;

}
#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBinaria{
    int elem;
    struct arvoreBinaria *dir, *esq;
}arvoreBinaria;

arvoreBinaria* insere(arvoreBinaria *a, int el);
arvoreBinaria* remover(arvoreBinaria *a, int el);

void preOrdem(arvoreBinaria *a);
void emOrdem(arvoreBinaria *a);
void posOrdem(arvoreBinaria *a);

int main(){
    arvoreBinaria *raiz = NULL;
    int x;
    char op;

    do{
        printf("\n1 - Inserir\n2 - Excluir\n3 - preOrdem\n4 - emOrdem\n5 - posOrdem\n6 - Sair\n");
        scanf(" %c",&op);
        switch(op){
            case '1':
                printf("\nValor? ");
                scanf("%d",&x);
                raiz = insere(raiz, x);
                break;
            case '2':
                if(raiz != NULL){
                    printf("\nDigite um valor: ");
                    scanf("%d",&x);
                    raiz = remover(raiz, x);
                } else {
                    printf("\nÁrvore Vazia");
                }
                break;
            case '3':
                preOrdem(raiz);
                break;
            case '4':
                emOrdem(raiz);
                break;
            case '5':
                posOrdem(raiz);
                break;
        }
    } while(op != '6');

}

arvoreBinaria* insere(arvoreBinaria *a, int el){
    if(a == NULL){
        a =(arvoreBinaria*)malloc(sizeof(arvoreBinaria));
        a-> elem = el;
        a-> esq = a->dir = NULL;
        printf("\nInserido\n");
    } else if(el <= a->elem){
        a->esq = insere(a->esq, el);
    } else {
        a->dir = insere(a->dir, el);
    }
    return a;
}

arvoreBinaria *remover(arvoreBinaria *a, int el){
    if(a == NULL){
        printf("Elemento não encontrado\n");
        return NULL;
    }
    if(el < a->elem){
        a->esq = remover(a->esq, el);
    } else if(el > a->elem){
        a->dir = remover(a->dir, el);
    } else{ //achou o elemento
        if(a->esq == NULL && a->dir == NULL){
            free(a);
            return NULL;
        } else if(a->esq == NULL){
            arvoreBinaria *temp = a->dir;
            free(a);
            return temp;
        } else if(a->dir == NULL){
            arvoreBinaria *temp = a->esq;
            free(a);
            return temp;
        } else {
            arvoreBinaria *aux = a->dir;
            while(aux->esq != NULL){
                aux = aux->esq;
                a->elem = aux->elem;
                a->dir = remover(a->dir, aux->elem);
            }
        }
    }
    return a;
}

void preOrdem(arvoreBinaria *a){
    if(a != NULL){
        printf("%d\t", a->elem);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void emOrdem(arvoreBinaria *a){
    if(a != NULL){
        emOrdem(a->esq);
        printf("%d\t", a->elem);
        emOrdem(a->dir);
    } 
}

void posOrdem(arvoreBinaria *a){
    if(a != NULL){
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d\t", a->elem);
    }
}

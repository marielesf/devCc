#include <stdio.h>
#include <stdlib.h>

#define TAM 5 ou int consttam = 5;

/*
Insira tantos números quanto o usuário informar (via teclado)
em uma árvore binária e depois mostre-os com percorrimento
pré-ordem na tela, separados por espaço.
*/

typedef struct arv Arv;
struct arv {
    int value;
    Arv * esq;
    Arv * dir;
};

Arv * criaArv(int value) {
    //=Nó
    Arv * a = (Arv *) malloc(sizeof(Arv));
    a ->value = value;
    return a;
}

void insereValor(Arv ** a, int value) {
    if (*a == NULL) {
    //Se vazia
        *a = criaArv(value);
    }
    else if (value < (*a)->value) {
        insereValor(&(*a)->esq, value);
    }
    else {
        insereValor(&(*a)->dir, value);
    }printf("inserindo");
}

void printArv(Arv* a) {
    //Pré-ordem
    if (a != NULL) {
        printf("%d ", a->value);
        //mostra raiz
        printArv(a->esq);
        //mostra sae
        printArv(a->dir);
        //mostra sad
    }
}

int contemArv(Arv* a, int value){
    return a != NULL && (a->value == value ||
    contemArv(a->esq, value) || contemArv(a->dir,
    value));
}

/*
void arvv_libera (ArvVar* a)
{
ArvVar* p = a->prim;
while (p!=NULL) {
ArvVar* t = p->prox;
arvv_libera(p);
p = t;
}
free(a);
}
*/

int main()
{
    int n=10, num;
    Arv **arvore;
    //printf("Informe qtd valores: \n");
    //scanf("%d", &n);
    for(int i = 0; i< n; i++){
        scanf("%d", &num);
        insereValor(arvore, num);
    }
    printArv(*arvore);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int head;
    char data[SIZE];
}PilhaArrayStr;

PilhaArrayStr *pilhaArrayStr(){
	PilhaArrayStr* p = (PilhaArrayStr*) malloc(sizeof(PilhaArrayStr));
	p->head = -1;
	return p;
}

void push(PilhaArrayStr * p, int valor) {
    if (p->head < SIZE -1) {
        p->head++; //Incrementa o topo
        p->data[p->head] = valor; //Insere valor no topo
    }
}

char pop(PilhaArrayStr * p) {
    if (p->head > -1) {
        p->head--;
        return p->data[p->head+1];
    }
    return -1; //Supondo que -1 seja um valor inválido na aplicação
}

PilhaArrayStr * reallocPilha() {
    PilhaArrayStr* p = (PilhaArrayStr*) realloc(p, 1*sizeof(PilhaArrayStr));
    return p;
}

int verificaFechamento(){
    return 0;
}

int main()
{
    char s[100];
    pilhaArrayStr = (PilhaArrayStr*) malloc(sizeof(PilhaArrayStr));
    fgets(s, 100, stdin );
    int i = 0;
    for(i = 0; i < strlen(s); i++){
          if(s[i] == '[' || s[i] =='(' ){
            push(pilhaArrayStr, s[i]);
          } else{
                pop(pilhaArrayStr);
            }
    }

    printf("%s", pilhaArrayStr->data);


    return 0;
}


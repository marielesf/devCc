#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
	int value;
	Node * next;
};

typedef struct lista Lista;
struct lista{
	Node * first;	
};

Lista * criaLista(){
	Lista * l = (Lista *) malloc(sizeof(Lista));
	l->first = NULL;
	return l;
}

Node * criaNo(int value){
	Node * no = (Node *) malloc(sizeof(Node));
	no->value = value;
	no->next = NULL;
}

void append(Lista * l, int value){
	Node * no;
	if(l == NULL){
		return;
	}
	no = l->first;
	while(no != NULL){
		no = no->next;
	}
	if(no == NULL){
		Node * novo = criaNo(value);
		l->first = novo;
	}else{
		Node * novo = criaNo(value);
		no->next = novo;
	}
}

void mostraLista(Lista * l){
	if(l == NULL) return;
	Node * no = l->first;
	while(no != NULL){
		printf("%d  ",no->value);
		no = no->next;
	}
	
}


int main(int argc, char *argv[]) {
	Lista * l = criaLista();
	
	append(l, 5);
	append(l, 6);
	append(l, 8);
	append(l, 3);
	
	mostraLista(l);
	return 0;
}

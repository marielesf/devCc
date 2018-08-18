#include <stdio.h>
#include <stdlib.h>

/*
Implemente uma lista encadeada com as operações de criar, adicionar item ao final,
remover item em qualquer posição e imprimir a lista completa na tela.

Faça um programa que ofereça ao usuário um menu com as opções
1) Adicionar valor 2) Remover valor 3) Sair.

A opção adicionar valor deve solicitar um inteiro ao usuário e adicionar o valor digitado ao final da lista.
Mostre a lista após a inclusão.

A opção de remover valor deve solicitar um inteiro ao usuário e remover o valor na posição escolhida (começando em 0).
Mostre a lista após a remoção.
 */

typedef struct node Node;
struct node {
    int data;
    Node * next; //Ponteiro para o próximo nó, null se for o último
};

typedef struct {
    Node * firstNode; // Ponteiro para o primeiro nó; null se a lista estiver vazia
} List;

List * criaLista() {
    List * l = (List *) malloc(sizeof(List));
    l->firstNode = NULL;
    return l;
}

Node * criaNo(int valor) {
    Node * node = (Node *) malloc(sizeof(List));
    node->data = valor;
    node->next = NULL;
    return node;
}

void insereDado(List * lista, int valor) {
    Node * novo = criaNo(valor);
    if (lista->firstNode == NULL) {
        lista->firstNode = novo;
    }
    else {
        Node * atual = lista->firstNode;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        novo->next = atual->next;
        atual->next = novo;
    }
}

void printaLista(List * lista) {
    Node * v = lista->firstNode;
    while (v != NULL) {
        printf("%d ", v->data);
        v = v->next;
    }
}

 void RemoveDado(List * lista, int posicao)
{
   Node * atual = lista->firstNode;
   if (lista->firstNode == NULL)
  {
      return 0;  // Lista vazia !!!
  }
  else
  {
     if (posicao == 0) {
            free(lista->firstNode);
            lista->firstNode = atual->next;
        }else{
        for (int i = 0; i < posicao - 1; i++) {
                if (atual->next == NULL) break;
                atual = atual->next;
            }
            atual->next = atual->next->next;
            return 1;
        }
  }
  return 0;
}



int main()
{
    List * lista = criaLista();
    int valor;
    int opcao;
    int count = 0;
    printf ("Escolha opcao\n: 1) Adicionar valor 2) Remover valor 3) Sair\n" );
    scanf("%d", &opcao);
while(opcao != 3){
    switch (opcao)
    {
     case 1 :
        printf ("Informe valor inteiro\n" );
        scanf("%d", &valor);
        insereDado(lista, valor);
        printaLista(lista);
     break;

     case 2 :
       printf ("Informe posicao\n" );
        scanf("%d", &valor);
        RemoveDado(lista, valor);
        printaLista(lista);
    }
    printf ("Escolha opcao\n: 1) Adicionar valor 2) Remover valor 3) Sair\n" );
    scanf("%d", &opcao);
}
    return 0;
}

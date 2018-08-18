#include <stdio.h>
#include <stdlib.h>

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

typedef struct no {
   int info;
   int n;
   struct no *left;
   struct no *right;
}tree;

tree *tfather=NULL; //ponteiro que indica o pai de uma subarvore
//estrutura para a pilha
typedef struct pr {
   tree *nodo;
   struct erd *next;
   struct erd *prev;
}pilha;

pilha *topo = NULL,*base = NULL;

tree *findFather(tree *root,int father)
{
   tree *aux = root;
   if(aux->info == father)
      tfather = aux;
   //else
      //return NULL;
   if(aux->left != NULL)
   findFather(aux->left,father);
   if(aux->right != NULL)
   findFather(aux->right,father);
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

//Show binary tree by algorithm InOrder not recursive
void InOrder(tree *root)
{
   tree *aux = root;
   int flag = 0;

   while(flag == 0)
   {
      while(aux != NULL)
      {
         push(aux);
         aux = aux->left;
      }

      aux = pop();

      if(aux == NULL)
         flag = 1;
      else
      {
         printf("%d\t",aux->info);
         aux = aux->right;
      }
   }
}
//Show binary tree by algorithm PreOrder
void PreOrder(tree *root)
{
   tree *aux = root;
   int flag = 0;

   while(flag == 0)
   {
      while(aux != NULL)
      {
         printf("%d\t",aux->info);
         push(aux);
         aux = aux->left;
      }

      aux = pop();

      if(aux == NULL)
         flag = 1;
      else
      {
        aux = aux->right;
      }
   }
}

//Show Binary tree by algorithm PostOrder
void PostOrder(tree *root)
{
   tree *aux = root;

   int flag = 0;

   while(flag == 0)
   {
      while(aux != NULL)
      {
         aux->n=1;
         push(aux);
         aux = aux->left;
      }

      aux = pop();

      if(aux == NULL)
         flag = 1;
      else
      {
         if(aux->n == 1)
         {
            aux->n = 2;
          push(aux);
         aux   = aux->right;
         }
         else
         {
         printf("%d\t",aux->info);
         aux = NULL;
         }
      }
   }
}

void showInOrder(tree *root)
{
   if(root == NULL)
      return;
   showInOrder(root->left);
   printf("%d\t",root->info);
   showInOrder(root->right);
}
void showPreOrder(tree *root)
{
   if(root == NULL)
      return;
   printf("%d\t",root->info);
   showPreOrder(root->left);
   showPreOrder(root->right);
}
void showPostOrder(tree *root)
{
   if(root == NULL)
      return;
   showPostOrder(root->left);
   showPostOrder(root->right);
   printf("%d\t",root->info);
}
*/

int main()
{
    int num;
    Arv **arvore = criaArv(10);
    for(int i = 0; i< 10; i++){
        scanf("%d", &num);
        insereValor(arvore, num);
        printf("%d", num);
    }
    printArv(arvore);
    printArv(arvore);
    return 0;
}


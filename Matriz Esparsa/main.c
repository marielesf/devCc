#include <stdio.h>
#include <stdlib.h>
#define TAM 10

/*
 * MATRIZ ESPARSA
 * utilizando lista duplamente encadeada
 * Desenvolvido por: Cristina, Mariele e Monique
*/

typedef struct node // estrutura para um novo node
{
	int valor;
	int lin, col;
	struct node *prox;
	struct node *ant;
}Node;

Node *primeiro; //node que inicia a lista
Node *ultimo;  //ultimo node da lista
int total_colunas = -1; // total de colunas


Node *CRIAR_NO(int lin, int col, int valor) // funcao que cria um novo node
{
    if(lin < 0 || col < 0) //garante que a linha e coluna informadas sao validas
        return NULL;
	Node* novo = NULL;
	novo = (Node*)malloc(sizeof(Node)); // alloca memoria para o novo node
	novo->valor = valor;
	novo->lin = lin;
	novo->col = col; //atibui valores
	novo->prox = NULL; //seta com null o next elemento
	return novo;
}

Node *VERIFICAR(int lin, int col) //percorer a lista ate a linha e coluna para adicinar
{
	Node *p = primeiro; //pega o primeiro node
	while(p != NULL)  //verifica se o primeiro node eh null
	{
		if(lin == p->lin && col == p->col) //verifica se a linha e coluna estao no node certo
		{
			return p; //retrona o node encontrado
		}
		p = p->prox;
	}
	return p;
}

void BUSCAR_VALOR(int elemento, int maior_linha, int maior_coluna) //Busca um valor na lista
{
	int i = 0;
	int j = 0;
	int total_linhas = maior_linha;
	int total_colunas = maior_coluna;

	for(i = 0; i <= total_linhas; i++)
	{
		for(j = 0; j <= total_colunas; j++)
		{
			Node *no = VERIFICAR(i, j);
			if(no != NULL && no->valor == elemento)
			{
				printf("\n linha: %d coluna: %d", i, j);

			}
		}
	}
}

void ADICIONAR_NUMERO(Node *elemento)
{
		if(ultimo == NULL) //lista esta vazia
		{
			elemento->prox = NULL;
			elemento->ant = NULL;
			ultimo = elemento;
			primeiro = elemento;
		}
		else
		{
			Node *p, *ant;
			p = primeiro;
			ant = NULL;
			while(p != NULL) //
			{
			    //avanca linha da lista
				if((p->lin < elemento->lin) || ((p->lin == elemento->lin) && (p->lin + p->col) < (elemento->lin + elemento->col)))
				{
					ant = p;
					p = p->prox;
				}
				else
				{
					if(p->ant)
					{
						p->ant->prox = elemento;
						elemento->prox = p;
						elemento->ant = p->ant;
						p->ant = elemento;
						return;
					}
					elemento->prox = p;
					elemento->ant = NULL;
					p->ant = elemento;
					primeiro = elemento;
					return;
				}
			}
			ant->prox = elemento;
			elemento->prox = NULL;
			elemento->ant = ant;
			ultimo = elemento;
			return;
		}
}

void IMPRIMI_MATRIZ_ESPARSA( int maior_linha, int maior_coluna)
{
		int total_linhas = maior_linha;
		int total_colunas = maior_coluna;

		Node *p = primeiro;

		while(p != NULL)
		{
			if(p->col > total_colunas)
			{
				total_colunas = p->col;
			}
			p = p->prox;
		}

		for(int i = 0; i <= total_linhas; i++)
		{
			for(int j = 0; j <= total_colunas; j++)
			{
				Node *no = VERIFICAR(i , j);

				if(no != NULL)
				{

					printf("%d\t", no->valor);
				}
				else
				{
					printf("0\t");
				}
			}
			printf("\n");
		}


}

void IMPRIMI_MATRIZ_SEM_ZERO( Node* vet)
{
	/*int i;
	int j;
	int total_linhas = ultimo->lin;
		for(i = 0; i < total_linhas; i++)
		{
			for(j = 0; j < total_colunas; j++)
			{
				Node *no = VERIFICAR(i, j);
				if(no != NULL)
				{
					printf("%d\t", no->valor);
				}
		}*/
		printf("\t %d", vet->valor);

}

void APAGAR(int lin, int col)
{
		if(primeiro->lin == lin && primeiro->col == col)
		{
			Node *prox = primeiro->prox;
			if(prox!=NULL)
			{
				prox->ant = NULL;
			}
			primeiro = prox;
		}
		Node *p = primeiro->prox;
		while(p != NULL)
		{
			if(p->lin == lin && p->col == col)
			{
				if(p->prox)
				{
					p->ant->prox = p->prox;
					p->prox->ant = p->ant;
					return;
				}
				else
				{
					p->ant->prox = NULL;
					ultimo = p->ant;
					return;
				}

				free(p);
				return;

			}
			p = p->prox;
		}
}


int main()
{
	Node *vet[TAM];
	int i=0, linha=0, coluna=0, valor=0, qnt=0;
	int maior_linha=0, maior_coluna=0;
	int valorBuscado;
	int LinhaApagada, ColunaApagada;
	char opcao;

	printf("\n Matriz Esparsa \n");

	do{
		printf("\n Digite um valor: ");
		scanf("%d",&valor);

		printf("\n Digite a Posição X (Linha): ");
		scanf("%d",&linha);

		printf("\n Digite a Posição Y (Coluna): ");
		scanf("%d",&coluna);

		vet[qnt]=CRIAR_NO(linha, coluna, valor);
		ADICIONAR_NUMERO(vet[qnt]);

		if(maior_linha < linha)
		{
			maior_linha=linha;
		}
		if(maior_coluna < coluna)
		{
			maior_coluna = coluna;
		}

		if(qnt < TAM)
		{
			printf("\n Digite 'S' para inserir um novo elemento na Matriz ou qualquer tecla para sair: ");
			scanf(" %[^\n]",&opcao);//No Windows use o gets ou getchar
			qnt++;
		}


	}while(((opcao == 'S') || (opcao == 's')) && (qnt < TAM));

	printf("\nMATRIX ESPARSA COM OS VALORES NULOS:\n");
	IMPRIMI_MATRIZ_ESPARSA(maior_linha, maior_coluna);
	printf("\nMATRIZ ESPARSA SEM OS VALORES NULOS:\n");

	for(i = 0; i < qnt; i++)
	{
		IMPRIMI_MATRIZ_SEM_ZERO(vet[i]);
    }
	printf("\n");

	printf("INFORMAR VALOR BUSCADO: ");
	scanf("%d",&valorBuscado);
	BUSCAR_VALOR(valorBuscado, maior_linha, maior_coluna);
	printf("\n");

	printf("Linha: ");
	scanf("%d", &LinhaApagada);
	printf("Coluna: ");
	scanf("%d", &ColunaApagada);
	APAGAR(LinhaApagada,ColunaApagada);

	IMPRIMI_MATRIZ_ESPARSA(maior_linha, maior_coluna);
}

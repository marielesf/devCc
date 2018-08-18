#include<stdio.h>
#include<conio.h>

const int limit = 10;
struct cadastro
{
char nome[100];
char sexo[1];
char dtNascimento[10];
int idade;
char doencasImportantes[300];
}cad[10];



void cadastraCliente();
void buscarCliente();
void listarClientes();
void voltarAoMenuPrincipal();
void deletaCliente();
int main()
{
    int opcao;
    do
    {
        printf("1 - Cadastra Cliente\n");
        printf("2 - Buscar Cliente \n");
        printf("3 - Listar Clientes \n");
        printf("4 - Excluir Cliente \n");
        printf("0 - Sair \n");
        printf(" Digite sua opcao: ");
        scanf("%d",&opcao);
        getchar();
        printf("\n");

        if(opcao == 0){
            return 0;
        }else if(opcao == 1){
            cadastraCliente();
        }else if(opcao == 2){
            buscarCliente();
        }else if(opcao == 3){
                listarClientes();
        }else if(opcao == 4){
                deletaCliente();
        }

    } while (opcao != 0 );
}

void buscarCliente(){

char nome[100];
int pos = -1;
int i;
    printf("\nDigite o nome a ser pesquisado: ");
    scanf("%s", nome);
    fflush(stdin);
    for(i=0;i<limit;i++){
        if(strcmp(cad[i].nome,nome) == 0){
            pos = i;
            break;
        }
    }
    if(pos > -1){
        printf("\nNome: %s \nSexo: %s \nIdade: %d\n\n", cad[pos].nome, cad[pos].sexo, cad[pos].idade);
    }else{
        printf("Cliente não encontrado.");
    }
    voltarAoMenuPrincipal();
}
void deletaCliente(){
    char nome[100];
    int pos = -1;
    int i;
    printf("\nDigite o nome do cliente a ser deletado: ");
    scanf("%s", nome);
    fflush(stdin);
    for(i=0;i<limit;i++){
        if(strcmp(cad[i].nome,nome) == 0){
            pos = i;
            cad[i].idade = 0;
            break;
        }
    }
    if(pos > -1){
        printf("Cliente deletado");
    }else{
        printf("Cliente não encontrado.");
    }
    voltarAoMenuPrincipal();
}

void cadastraCliente(){
    int pos = verifica_pos();
    int diaN, mesN, anoN, diaA, mesA, anoA, idade;
    char dtAtual[10];
    if(pos>=0){
        printf("\nDigite o nome: ");
        scanf("%s", cad[pos].nome);

        printf("\nDigite o sexo: ");
        scanf("%s",&cad[pos].sexo);

        printf("\nDigite a Data de Nascimento(dd/mm/aaaa): ");
        scanf("%d/%d/%d", &diaN, &mesN, &anoN);

        printf("\nDigite a Data de hoje(dd/mm/aaaa): ");
        scanf("%d/%d/%d", &diaA, &mesA, &anoA);

        printf("\n Caso possua, digite as doencas importantes: ");
        scanf("%s",&cad[pos].doencasImportantes);

        if ((mesN > mesA) || ((mesN = mesA) && (diaN > diaA)))
            idade = anoA - anoN - 1;
        else idade = anoA - anoN;

        cad[pos].idade = idade;
        fflush(stdin);

    }else{
        printf("\nLimite de Registros atingido. Favor deletar algum antes de inserir um novo.");
    }
    voltarAoMenuPrincipal();
}

void voltarAoMenuPrincipal(){
    printf("\nPressione enter para volta ao menu principal");
    getchar();
    system("cls");
}

void listarClientes(){
    int i,j;
    for(i=0;i<limit;i++){
        if(cad[i].idade > 0)
            printf("\nNome: %s \nSexo: %s \nData de Nascimento: %s \nIdade: %d \nDoencas Importantes: %s\n\n", cad[i].nome, cad[i].sexo, cad[i].dtNascimento, cad[i].idade, cad[i].doencasImportantes);
    }
    voltarAoMenuPrincipal();
}
int verifica_pos()
{
    int cont = 0;
    while ( cont < limit )
    {
        if (cad[cont].idade == 0){
                 printf("\nEntrou");
            return(cont);
        }
        cont++;
    }
    return(-1);

}

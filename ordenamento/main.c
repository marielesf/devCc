#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main()
{
    int qtdExecucao= 0;
    int vetor[30] = {10,24,2,25,11,8,32,42,16,49,40,20,22,32,50,32,28,48,11,25,30,46,18,39,32,6,11,44,4,8};
    int i=0;
    int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);
    ordenar_countingSort(vetor);
    for (i = 0; i < tamanhoVetor; i++){ //Conta valores (count zerado)
         printf("%d", vetor[i]);
         printf("\n");
    }

    clock_t t;
    t = clock();
    for(qtdExecucao =0; qtdExecucao < 1000000 ; qtdExecucao++){
        ordenar_countingSort(vetor);
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("ordenar_countingSort: 1000000 chamadas - %f seconds to execute \n", time_taken);

    printf("------------------------ \n");

    int vetor1[30] = {10,24,2,25,11,8,32,42,16,49,40,20,22,32,50,32,28,48,11,25,30,46,18,39,32,6,11,44,4,8};
    ordenar_insertion_sort(vetor1);

     for (i = 0; i < tamanhoVetor; i++){ //Conta valores (count zerado)
         printf("%d", vetor1[i]);
         printf("\n");
     }

    qtdExecucao= 0;
    clock_t tv;
    tv = clock();

    for(qtdExecucao =0; qtdExecucao < 1000000 ; qtdExecucao++){
        ordenar_insertion_sort(vetor1);
    }
    tv = clock() - tv;
    time_taken = ((double)tv)/CLOCKS_PER_SEC; // in seconds
    printf("ordenar_insertion_sort: 1000000 chamadas - %f seconds to execute \n", time_taken);

    printf("Hello world!\n");
    return 0;
}

void ordenar_countingSort(int vetor1[30]){
    int maiorValor=0;
    int i=0;
    int vetAux [30];

    for (i = 0; i < 30; i++){ //Conta valores (count zerado)
     if(maiorValor < vetor1[i])
        maiorValor = vetor1[i];
    }
    maiorValor++;
    int count[maiorValor];

    for (i = 0; i < maiorValor; i++) //zerar contador
     count[i] = 0;

    for (i = 0; i < 30; i++) //Conta valores (count zerado)
     count[vetor1[i]]++;

    for (i = 1; i < maiorValor; i++) //Acumula valores
     count[i] += count[i-1];

    for (i = 0; i < 30; i++) //zerar vetor auxiliar
     vetAux[i] = 0;

    for (i = 0; i < 30; i++){ //Coloca cada valor no seu lugar
     vetAux[count[vetor1[i]] - 1] = vetor1[i];
     count[vetor1[i]]--;
    }

    for (i = 0; i < 30; i++){ //Coloca cada valor no seu lugar
     vetor1[i] = vetAux[i];
    }
}

void ordenar_insertion_sort(int vetor[30]){
int i=0,j=0,aux=0;
    for (i = 1; i < 30; i++){
        for (j = i; j > 0 && vetor[j-1] > vetor[j]; j--){
            aux=vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1]=aux;
        }
    }
}


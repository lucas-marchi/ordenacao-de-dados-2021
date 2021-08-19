#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gravarArquivo(int *vetor, int n)
{
    FILE *arq;
    int result = 0;

    arq = fopen("ArqOrdenado.txt", "w+");

    if (arq == NULL)
    {
        printf("Erro ao tentar abrir o arquivo.");
        return;
    }

    printf("Comecando a gravacao de dados no arquivo [ArqOrdenado.txt]...\n");

    for(int i = 0; i < n; i++) {
        fprintf(arq, "%d\n", vetor[i]);
        result = result+1;
    }

    printf("\n%d elementos gravados!\n", result);
    fclose(arq);
}

void menuOpcao(int opcao, int *vetor, int n)
{
    clock_t t;

    if (opcao == 1) {
        t = clock();
        quickSort(vetor, 0, n);
        t = clock() - t;
        printf("\nTempo de execucao da funcao quick: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
        gravarArquivo(vetor, n);
    }else if (opcao == 2) {
        t = clock();
        mergeSort(vetor, 0, n);
        t = clock() - t;
        printf("Tempo de execucao da funcao merge: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
        gravarArquivo(vetor, n);
    }
}

void printVetor(int vetor[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void trocar(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

int quickSort(int *vetor, int esquerda, int direita)
{
    int i, j, x, y;

    i = esquerda;
    j = direita;
    x = vetor[(esquerda + direita) / 2];

    while(i <= j) {
        while(vetor[i] < x && i < direita) {
            i++;
        }
        while(vetor[j] > x && j > esquerda) {
            j--;
        }
        if(i <= j) {
            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
        }
    }

    if(j > esquerda) {
        quickSort(vetor, esquerda, j);
    }
    if(i < direita) {
        quickSort(vetor, i, direita);
    }
}

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main(){
    FILE *teste;
    FILE *pont_arq;
    int opcao, opcao2, opcao3, op, n;

    printf("-----Escolha uma opcao-----\n\n");
    printf("1 - Quick Sort\n");
    printf("2 - Merge Sort\n");
    scanf("%d", &opcao);

    if ((opcao < 1)||(opcao > 2)) {
        printf("Opcao Invalida!\n");
        exit(0);
    }

    printf("-----Escolha uma opcao-----\n\n");
    printf("1 - 750000 numeros\n");
    printf("2 - 1000000 numeros\n");
    printf("3 - teste (20 numeros)\n");
    scanf("%d", &opcao2);

    if (opcao2 == 1) n = 750000;
    if (opcao2 == 2) n = 1000000;
    if (opcao2 == 3) n = 20;


    if (opcao2 == 3) {
        teste = fopen("teste.txt", "rb");

        int *vetor = (int*)malloc(20*sizeof(int));

        if (teste == NULL) {
            printf("Erro ao tentar abrir o arquivo.");
            return 0;
        }else{
            for(int i = 1; i <= 20; i++){
                fscanf(teste, "%d", &vetor[i]);
                printf("%d\n", vetor[i]);
            }
        }
        printf("\n");
        menuOpcao(opcao, vetor, n);

        return 0;
    }

    printf("-----Escolha uma opcao-----\n\n");
    printf("1 - Invertido\n");
    printf("2 - Ordenado\n");
    printf("3 - Randomico\n");
    scanf("%d", &opcao3);

    if (opcao2 == 1) {
        int *vetor = (int*)malloc(750000*sizeof(int));

        switch (opcao3) {
            case 1:
                pont_arq = fopen("Invertido0750000.txt", "rb");
                if (pont_arq == NULL) {
                    printf("Erro ao tentar abrir o arquivo.");
                    break;
                }else{
                    printf("Lendo dados...\n");
                    for(int i = 1; i <= 750000; i++){
                        fscanf(pont_arq, "%d", &vetor[i]);
                    }
                }
                menuOpcao(opcao, vetor, n);

                return 0;
                break;
            case 2:
                pont_arq = fopen("Ordenado0750000.txt", "rb");
                if (pont_arq == NULL) {
                    printf("Erro ao tentar abrir o arquivo.");
                    break;
                }else{
                    printf("Lendo dados...\n");
                    for(int i = 1; i <= 750000; i++){
                        fscanf(pont_arq, "%d", &vetor[i]);
                    }
                }
                menuOpcao(opcao, vetor, n);

                return 0;
                break;

            case 3:
                pont_arq = fopen("Randomico0750000.txt", "rb");
                if (pont_arq == NULL) {
                    printf("Erro ao tentar abrir o arquivo.");
                    break;
                }else{
                    printf("Lendo dados...\n");
                    for(int i = 1; i <= 750000; i++){
                        fscanf(pont_arq, "%d", &vetor[i]);
                    }
                }
                menuOpcao(opcao, vetor, n);

                return 0;
                break;
        }
    }else if(opcao2 == 2) {
        int *vetor = (int*)malloc(1000000*sizeof(int));

        switch(opcao3) {
            case 1:
                pont_arq = fopen("Invertido1000000.txt", "rb");
                if (pont_arq == NULL) {
                    printf("Erro ao tentar abrir o arquivo.");
                    break;
                }else{
                    printf("Lendo dados...\n");
                    for(int i = 1; i <= 1000000; i++){
                        fscanf(pont_arq, "%d", &vetor[i]);
                    }
                }
                menuOpcao(opcao, vetor, n);

                return 0;
                break;
            case 2:
                pont_arq = fopen("Ordenado1000000.txt", "rb");
                if (pont_arq == NULL) {
                    printf("Erro ao tentar abrir o arquivo.");
                    break;
                }else {
                    printf("Lendo dados...\n");
                    for(int i = 1; i <= 1000000; i++){
                        fscanf(pont_arq, "%d", &vetor[i]);
                    }
                }
                menuOpcao(opcao, vetor, n);

                return 0;
                break;

            case 3:
                pont_arq = fopen("Randomico1000000.txt", "rb");
                if (pont_arq == NULL) {
                    printf("Erro ao tentar abrir o arquivo.");
                    break;
                }else{
                    printf("Lendo dados...\n");
                    for(int i = 1; i <= 1000000; i++){
                        fscanf(pont_arq, "%d", &vetor[i]);
                    }
                }
                menuOpcao(opcao, vetor, n);

                return 0;
                break;
            default:
                printf("Opcao Invalida!\n");
                break;
        }
    }
    fclose(pont_arq);
    fclose(teste);
}

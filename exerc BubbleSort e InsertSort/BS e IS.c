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

void bubble_Sort (int n, int *vetor)
{
    int i, j;

    printf("Comparando... \n");
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n-i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j+1]);
            }
        }
    }
    printf("Ordenacao Finalizada!\n");
    //printVetor(vetor, n);
    gravarArquivo(vetor, n);
}

void insertion_Sort( int n, int *vetor)
{
    int i, j, key;

    printf("Comparando... \n");
    for (i = 0; i <= n; i++) {
        key = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
    printf("Ordenacao Finalizada!\n");
    //printVetor(vetor, n);
    gravarArquivo(vetor, n);
}

int menu(int opcao)
{
    int opcao2, opcao3, op;

    FILE *teste;
    FILE *pont_arq;

    printf("-----Escolha uma opcao-----\n\n");
    printf("1 - 750000 numeros\n");
    printf("2 - 1000000 numeros\n");
    printf("3 - teste (20 numeros)\n");
    scanf("%d", &opcao2);

    if (opcao2 == 3) {
        int *vetor = (int*)malloc(20*sizeof(int));

        teste = fopen("teste.txt", "rb");
        if (teste == NULL) {
            printf("Erro ao tentar abrir o arquivo.");
            return 0;
        }else{
            for(int i = 1; i <= 20; i++){
                fscanf(teste, "%d", &vetor[i]);
                printf("%d\n", vetor[i]);
            }
        }

        if (opcao == 1) bubble_Sort(20, vetor);
        if (opcao == 2) insertion_Sort(20, vetor);

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

                if (opcao == 1) bubble_Sort(750000, vetor);
                if (opcao == 2) insertion_Sort(750000, vetor);

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

                if (opcao == 1) bubble_Sort(750000, vetor);
                if (opcao == 2) insertion_Sort(750000, vetor);

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

                if (opcao == 1) bubble_Sort(750000, vetor);
                if (opcao == 2) insertion_Sort(750000, vetor);

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

                if (opcao == 1) bubble_Sort(1000000, vetor);
                if (opcao == 2) insertion_Sort(1000000, vetor);

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

                if (opcao == 1) bubble_Sort(1000000, vetor);
                if (opcao == 2) insertion_Sort(1000000, vetor);

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

                if (opcao == 1) bubble_Sort(1000000, vetor);
                if (opcao == 2) insertion_Sort(1000000, vetor);

                return 0;
                break;
            default:
                printf("Opcao Invalida!\n");
                break;
        }
    }
}

int main(){
    int opcao;

    printf("-----Escolha uma opcao-----\n\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insert Sort\n");
    scanf("%d", &opcao);

    if ((opcao == 1)||(opcao == 2)) menu(opcao);
    else printf("Opcao Invalida!\n");

    fcloseall;
}

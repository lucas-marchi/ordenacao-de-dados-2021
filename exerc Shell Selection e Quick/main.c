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

void menu_Opcao(int opcao,int *vetor, int n)
{
    clock_t t;

    if (opcao == 1) {
        t = clock();
        shell_Sort(n, vetor);
        t = clock() - t;
        printf("Tempo de execucao da funcao shell: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
        gravarArquivo(vetor, n);
    }
    else if (opcao == 2) {
        t = clock();
        selection_Sort(n, vetor);
        t = clock() - t;
        printf("Tempo de execucao da funcao selection: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
        gravarArquivo(vetor, n);
    }
    else if (opcao == 3) {
        t = clock();
        quick_Sort(vetor, 0, n);
        printf("\nTempo de execucao da funcao quick: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
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

int selection_Sort(int n, int *vetor)
{
    int i, j, min_idx;

    printf("Comparando... \n");
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i+1; j <= n; j++)
            if (vetor[j] < vetor[min_idx])
            min_idx = j;

        trocar(&vetor[min_idx], &vetor[i]);
    }
    printf("Ordenacao Finalizada!\n");
    return *vetor;
}

int quick_Sort(int *vetor, int esquerda, int direita)
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
        quick_Sort(vetor, esquerda, j);
    }
    if(i < direita) {
        quick_Sort(vetor, i, direita);
    }
    return *vetor;
}

int shell_Sort(int n, int *vetor)
{
    int i , j , value;
    int gap = 1;

    do {
        gap = 3*gap+1;
    }while(gap < n);

    printf("Comparando... \n");
    do {
        gap /= 3;
        for(i = gap; i <= n; i++) {
            value = vetor[i];
            j = i - gap;

            while (j >= 0 && value < vetor[j]) {
                vetor[j + gap] = vetor[j];
                j -= gap;
            }
            vetor[j + gap] = value;
        }
    }while(gap > 1);
    printf("Ordenacao Finalizada!\n");
    return *vetor;
}

int main(){
    FILE *teste;
    FILE *pont_arq;
    int opcao, opcao2, opcao3, op, n;

    printf("-----Escolha uma opcao-----\n\n");
    printf("1 - Shell Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Quick Sort\n");
    scanf("%d", &opcao);

    if ((opcao < 1)||(opcao > 3)) {
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
        menu_Opcao(opcao, vetor, n);

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
                menu_Opcao(opcao, vetor, n);

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
                menu_Opcao(opcao, vetor, n);

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
                menu_Opcao(opcao, vetor, n);

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
                menu_Opcao(opcao, vetor, n);

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
                menu_Opcao(opcao, vetor, n);

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
                menu_Opcao(opcao, vetor, n);

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

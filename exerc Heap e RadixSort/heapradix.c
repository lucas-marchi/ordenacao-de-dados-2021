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

void menuOpcao(int opcao,int *vetor, int n)
{
    clock_t t;

    if (opcao == 1) {
        t = clock();
        heapSort(vetor, n);
        t = clock() - t;
        printf("Tempo de execucao da funcao heap: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
        gravarArquivo(vetor, n);
    }
    else if (opcao == 2) {
        t = clock();
        radixSort(vetor, n);
        t = clock() - t;
        printf("Tempo de execucao da funcao radix: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
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

void heapficar(int *vetor, int n, int i) {
    int max = i;
    int filhoEsquerda = 2 * i + 1;
    int filhoDireita = 2 * i + 2;

    if (filhoEsquerda < n && vetor[filhoEsquerda] > vetor[max])
      max = filhoEsquerda;

    if (filhoDireita < n && vetor[filhoDireita] > vetor[max])
      max = filhoDireita;

    if (max != i) {
      trocar(&vetor[i], &vetor[max]);
      heapficar(vetor, n, max);
    }
}

int heapSort(int *vetor, int n) {
    for (int i = n / 2; i >= 0; i--)
      heapficar(vetor, n, i);

    for (int i = n; i >= 0; i--) {
      trocar(&vetor[0], &vetor[i]);

      heapficar(vetor, i, 0);
    }
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int v[], int tam) {
    int i;
    int *b;
    int maior = v[0];
    int exp = 1;

    b = (int *)calloc(tam, sizeof(int));

    for (i = 0; i < tam; i++) {
        if (v[i] > maior)
    	    maior = v[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tam; i++)
    	    bucket[(v[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tam - 1; i >= 0; i--)
    	    b[--bucket[(v[i] / exp) % 10]] = v[i];
    	for (i = 0; i < tam; i++)
    	    v[i] = b[i];
    	exp *= 10;
    }

    free(b);
}

int main(){
    FILE *teste;
    FILE *pont_arq;
    int opcao, opcao2, opcao3, op, n;

    printf("-----Escolha uma opcao-----\n\n");
    printf("1 - Heap Sort\n");
    printf("2 - Radix Sort\n");
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
  FILE *ordenado, *invertido, *randomico;
  int tam, x, chute;
  char nomeArquivo[255];
  srand (time(NULL));

  printf("Informe o tamanho do arquivo ");
  scanf("%d", &tam);
  sprintf(nomeArquivo, "Ordenado%07d.txt", tam);
  ordenado = fopen(nomeArquivo, "w");
  for (x=1;x<=tam;x++){
    fprintf(ordenado, "%d\n", x);
  }
  fclose(ordenado);

  sprintf(nomeArquivo, "Invertido%07d.txt", tam);
  invertido = fopen(nomeArquivo, "w");
  for (x=tam;x>=1;x--){
    fprintf(invertido, "%d\n", x);
  }
  fclose(invertido);

  sprintf(nomeArquivo, "Randomico%07d.txt", tam);
  randomico = fopen(nomeArquivo, "w");
  for (x=1;x<=tam;x++){
    chute = (rand() * rand())%tam + 1;
    fprintf(randomico, "%d\n", chute);
  }
  fclose(randomico);
}

#include <stdio.h>

int sequencia[10] = {7, 6, 10, 3, 4, 1, 8, 9, 5, 2};
int best[10] = {0,0,0,0,0,0,0,0,0,1};
int next[10] = {0,0,0,0,0,0,0,0,0,0};

void mostraMelhorSequencia(int index){
  printf("Tamanho da melhor sequencia a partir do %d: %d\n\n", sequencia[index], best[index]);

  printf("Sequencia: %d\t", sequencia[index]);

  while(next[index] != 0){
    index = next[index];

    printf("%d\t", sequencia[index]);
  }
}

int main(void) {

  for(int i = 0; i < 10; i++){
    printf("%d\t", sequencia[i]);
  }

  printf("\n\n");

  for(int i = 8; i >= 0; i--){
    best[i] = 1;

    for(int j = i + 1; j < 10; j++){
      if(sequencia[j] > sequencia[i] && 1 + best[j] > best[i]){
        best[i] = 1 + best[j];
        next[i] = j;
      }
    }
  }

  for(int i = 0; i < 10; i++){
    printf("%d\t", best[i]);
  }

  printf("\n\n");

  for(int i = 0; i < 10; i++){
    printf("%d\t", next[i]);
  }

  printf("\n\n");

  mostraMelhorSequencia(3);

  return 0;
}

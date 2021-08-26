#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}

main(){
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    fib(n);
}

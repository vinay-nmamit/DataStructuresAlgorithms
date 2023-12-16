/*Find the factorial of a number using iterative method*/
#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    int result = 1;
    for(int i = 1; i <= n; ++i){
        result *= i;
    }
    return result;
}

int main(){
    int n;
    scanf("%d", &n);

    if(n < 0) {
        printf("factorial not defined");
    } else {
        printf("%d",factorial(n));
    }
    return 0;
}
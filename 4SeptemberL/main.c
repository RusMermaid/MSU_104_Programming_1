#include <stdio.h>

void HelloWorld() {
    printf("Hello, World!\n");
}

void Factorial(){
    int m, x; x = 1;
    printf("input m\n");
    scanf("%d", &m);
    while (m > 0){
        x *= m;
        m--;
    }
    printf("%d", x);
}

int main() {

    HelloWorld();

    Factorial();

    return 0;
}




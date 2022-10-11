#include <stdio.h>
#include <stdlib.h>

void echangeContenu(int *a, int *b){
    int c= *a;
    *a= *b;
    *b=c;
}

int main(void) {
int a =10;
int b =20;
echangeContenu(&a,&b);
printf("%d %d",a,b);
} 
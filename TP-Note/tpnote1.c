#include <stdio.h>
#include <stdlib.h>




void repeat(int64_t t1[],int64_t t2[],int64_t tabresult[]){
    int compteur=0;
for (int i=0;i<3;i++){
    for(int j=0;j<t1[i];j++){
        tabresult[compteur]=t2[i];
        compteur++;
    }
}
}
int main(void) {
    int64_t t1={1,2,4};
    int64_t t2={10,3,8};
    int64_t tabresult= {0,0,0,0,0,0,0};
    repeat(t1,t2, tabresult);
    for(int i=0;i<7;i++){
        printf("%zu ",tabresult[i]);


        }
} 
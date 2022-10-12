#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
void matrix_mult(int64_t matriceResultat[][SIZE],int64_t matrice1[][SIZE],int64_t matrice2[][SIZE]){
    int stockage=0;
for (int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
        for(int k=0;k<SIZE;k++){
            stockage+= matrice1[k][i]*matrice2[j][k];
        }
        matriceResultat[i][j]=stockage;
        stockage=0;
    }
}
}
void print_matrix(int64_t matriceResultat[][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%zu ",matriceResultat[i][j]);


        }
    printf("\n");
    }
}





int main(void) {
int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
int64_t matriceResultat[SIZE][SIZE];

matrix_mult(matriceResultat,matrice1,matrice2);
print_matrix(matriceResultat);
} 
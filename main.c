#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void rellenaMatrizAleatorio(int m[][MAX],int fila,int cola);
void imprimeMatriz(int m[][MAX],int fila,int cola);
void invierteMatriz(int m[][MAX],int fila,int cola,int m2[][MAX]);
void pideNum(int *fila, int *cola);


int main() {
    int fila, cola;
    pideNum(&fila,&cola);
    int matriz[MAX][MAX];
    int tras[MAX][MAX];
    rellenaMatrizAleatorio(matriz,fila,cola);
    printf("\n---| MATRIZ GENERADA:\n");
    imprimeMatriz(matriz,fila,cola);
    invierteMatriz(matriz,fila,cola,tras);
    printf("\n---| MATRIZ TRASPUESTA:\n");
    imprimeMatriz(tras,cola,fila);
    return 0;
}

void rellenaMatrizAleatorio(int m[][MAX],int fila,int cola){
    srand(time(NULL));
    for (int i = 0; i < fila; ++i) {
        for (int j = 0; j < cola; ++j) {
            m[i][j]=rand()%10;
        }
    }
}

void imprimeMatriz(int m[][MAX],int fila,int cola){
    printf("\n");
    for (int i = 0; i < fila; ++i) {
        printf("|");
        for (int j = 0; j < cola; ++j) {
            printf("% d |",m[i][j]);
        }
        printf("\n");
    }
}

void invierteMatriz(int m[][MAX],int fila,int cola,int m2[][MAX]){
    int num;
    for (int i = 0; i < fila; ++i) {
        for (int j = 0; j < cola; ++j) {
            num=m[i][j];
            m2[j][i]=num;
        }
    }
}

void pideNum(int *fila, int *cola){
    printf("Introduce la dimension (filas): ");
    scanf("%d",fila);
    fflush(stdin);
    while (*fila>10 || *fila<0 ){
        printf("Valor maximo: 10\nIntroduce la dimension (filas): ");
        scanf("%d",fila);
        fflush(stdin);
    }
    printf("Introduce la dimension (columnas): ");
    scanf("%d",cola);
    fflush(stdin);
    while (*cola>10 || *cola<0){
        printf("Valor maximo: 10\nIntroduce la dimension (columnas): ");
        scanf("%d",cola);
        fflush(stdin);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "com112_sort.h"
#include "com112_file.h"

/* 
* PROTOTYPES
*/
char menu();
int numberRandom(int *vector,int *incVector, int *decVector);
void copyVector(int *vector1, int *vector2, int len);
void printfVector(int *vector, int len);

/*
* FUCTIONS
*/
void printfVector(int *vector, int len){
    int i;
    for (i = 0; i < len; i++){
        printf("%d ", vector[i]);
    }

    printf("\n");
}

void copyVector(int *vector1, int *vector2, int len){
    int i;
    for ( i = 0; i < len; i++){
        vector2[i] = vector1[i];
    }
    
}


int numberRandom(int *vector, int *incVector, int *decVector){
    int len, j, i;;

    printf("quantidade de numeros a serem gerados e ordenados: ");
    scanf("%d", &len);

    for ( i = 0; i < len; i++){
        vector[i] = rand() % 10000;

    }
    
    for(i = 0, j = len - 1; i < len; i++, j--){
		incVector[i] = i;
		decVector[i] = j;
	}
    
    input(incVector, len, 2);
    input(decVector, len, 3);

    return len;
}

char menu(){
    char choice;

    printf("SEJA BEM VINDO - TESTE UM METODO DE ORDENAÇÃO\n");
    printf("\n");
    printf("0 - Gerar numeros para ordenação\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Merge Sort\n");
    printf("5 - Quick Sort\n");
    printf("6 - Relatorio\n");
    printf("7 - Sair\n");
    printf("Opção: ");
    scanf(" %c", &choice);
    
    printf("\n");
    return choice;
}

/*
* Main
*/
int main(){
    char choice;
    int len;
    int originVector[10000];
    int sortVector[10000];
    int incVector[10000];
    int decVector[10000];

    int flag;
    int moves;
    int comparies;
    double time;
    clock_t Ticks[2];
    
    do{
        comparies = 0;
        moves = 0;
        time = 0.0;

        choice = menu();
        switch (choice){
        case '0':
            flag = 0;
            len = numberRandom(originVector, incVector,decVector);
            input(originVector, len, 1);

            printf("\n");
            break;

        case '1':
            copyVector(originVector, sortVector, len);

            Ticks[0] = clock();
            bubbleSort(sortVector,len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;

            printf("Vetor ordenado com buubleSort\n");
            
            if(!flag){
                output(sortVector,len, 1);
                flag = 1;
            }
            
            printf("Numeros de elementos: %d\n", len);
            printf("Comparações: %d\n", comparies);
            printf("Movimentações: %d\n", moves);
            printf("Tempo de execução: %f\n", time);
            break;

        case '2':
            copyVector(originVector, sortVector, len);

            Ticks[0] = clock();
            insertionSort(sortVector,len, &moves, &comparies);         
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            
            printf("Vetor ordenado com insertionSort\n");
            
            if(!flag){
                output(sortVector,len, 1);
                flag = 1;
            }
            printf("Numeros de elementos: %d\n", len);
            printf("Comparações: %d\n", comparies);
            printf("Movimentações: %d\n", moves);
            printf("Tempo de execução: %f\n", time);
            break;

        case '3':
            copyVector(originVector, sortVector, len);

            Ticks[0] = clock();        
            selectionSort(sortVector, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;

            printf("Vetor ordenado com selectionSort\n");

            if(!flag){
                output(sortVector,len, 1);
                flag = 1;
            }

            printf("Numeros de elementos: %d\n", len);
            printf("Comparações: %d\n", comparies);
            printf("Movimentações: %d\n", moves);
            printf("Tempo de execução: %f\n", time);
            break;

        case '4':
            copyVector(originVector, sortVector, len);

            Ticks[0] = clock();       
            mergeSort(sortVector ,0 , len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;

            printf("Vetor ordenado com mergeSort\n\n");

            if(!flag){
                output(sortVector,len, 1);
                flag = 1;
            }

            printf("Numeros de elementos: %d\n", len);
            printf("comparações: %d\n", comparies);
            printf("Movimentações: %d\n", moves);
            printf("Tempo de execução: %f\n", time);
            break;

        case '5':
            copyVector(originVector, sortVector, len);

            Ticks[0] = clock();
            quickSort(sortVector, 0, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;

            if(!flag){
                output(sortVector,len, 1);
                flag = 1;
            }

            printf("Numeros de elementos: %d\n", len);
            printf("comparações: %d\n", comparies);
            printf("Movimentações: %d\n", moves);
            printf("Tempo de execução: %f\n", time);
            break;

        case '6':
            printf("Processando relatorios...");

            copyVector(originVector, sortVector, len);
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            bubbleSort(sortVector, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Bubble Sort\n",len, moves, comparies, time, 1);
            
            if(!flag){
            	output(sortVector,len,1);
            	flag = 1;
			}
			
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            bubbleSort(incVector,len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Bubble Sort\n",len, moves, comparies, time, 2);
            
   			output(incVector,len,2);
            
            copyVector(decVector, sortVector, len);
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            bubbleSort(sortVector,len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Bubble Sort\n",len, moves, comparies, time, 3);
  		  	  
			output(sortVector,len,3);
			
			
            copyVector(originVector, sortVector,len);
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            insertionSort(sortVector,len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Insertion Sort\n",len, moves, comparies, time, 1);
            
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            insertionSort(incVector,len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Insertion Sort\n",len, moves, comparies, time, 2);
            
            copyVector(decVector, sortVector,len);
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            insertionSort(sortVector,len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Insertion Sort\n",len, moves, comparies, time, 3);
            

            copyVector(originVector, sortVector,len);
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            selectionSort(sortVector, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Selection Sort\n",len, moves, comparies, time, 1);
            
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            selectionSort(incVector, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Selection Sort\n",len, moves, comparies, time, 2);
            
            copyVector(decVector, sortVector,len);
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            selectionSort(sortVector, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Selection Sort\n",len, moves, comparies, time, 3);
            

            copyVector(originVector, sortVector, len);
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            mergeSort(sortVector, 0, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Merge Sort\n",len, moves, comparies, time, 1);
            
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            mergeSort(incVector, 0, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Merge Sort\n",len, moves, comparies, time, 2);
            
            copyVector(decVector, sortVector,len);
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            mergeSort(sortVector, 0, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Merge Sort\n",len, moves, comparies, time, 3);

			
            copyVector(originVector, sortVector,len);
            moves = 0; 
            comparies = 0;
            Ticks[0] = clock(); 
            quickSort(sortVector, 0, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Quick Sort\n",len, moves, comparies, time, 1);
            
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            quickSort(incVector, 0, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Quick Sort\n",len, moves, comparies, time, 2);
            
            copyVector(decVector, sortVector,len);
            moves = 0;
            comparies = 0;
            Ticks[0] = clock();
            quickSort(sortVector, 0, len, &moves, &comparies);
            Ticks[1] = clock();
            time = (Ticks[1] - Ticks[0]) / 3600.0;
            reportFile("Metodo Quick Sort\n",len, moves, comparies, time, 3);
            
            printf("Consulte os arquivos de relat�rio para ver as estat�sticas\n\n");
            break;

        case '7':
            printf("Programa finalizado");
            break;

        default:
            printf("Opção invalida. Tente novamente.\n\n");
            break;
        }
    }while(choice != '7');
    
    printf("\n");
    return 0;
}
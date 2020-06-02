#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "com112_sort.h"

/*
* Bubble Sort
*/
void bubbleSort(int *vector, int len, int *moves, int *comparies){

    int position_compare = len-1;
    int aux = 0;
    int x;
    int y;

    for (x = 0; x < position_compare; x++){
        for (y = 0; y < position_compare; y++){
            *comparies += 1;
            if (vector[y] > vector[y+1]){
                aux = vector[y];
                vector[y] = vector[y+1];
                vector[y+1] = aux;

                *moves +=1;
            }
        }
    }

}


void selectionSort(int *vector, int len, int *moves, int *comparies){
	int a, b, c;
	int exchange, t;
	for (a = 0; a < len-1; ++a) {
		exchange = 0;
		c = a;
		t = vector[a];
		for (b = a+1; b < len; ++b) {
			*comparies += 1;
			if (vector[b] < t) {
				c = b;
				t = vector[b];
				exchange = 1;
			} 
		}
		if (exchange) {
			vector[c] = vector[a];
			vector[a] = t;
			*moves += 1;
		} 
	} 
}

/*
* Insertion Sort
*/
void insertionSort(int *vector, int len, int *moves, int *comparies){

    int position_compare = len-1;
    int aux = 0;
    int j;
    int k;

    for(j = 1; j <= position_compare; j++ ){  

        for(k = j; k > 0; k--){
            *comparies +=1;
            if (vector[k] < vector[k-1]){
                aux = vector[k];
                vector[k] = vector[k-1];
                vector[k-1] = aux;

                *moves +=1;
            }else{
                break;
            }
        }
    } 
}

/*
* Merge Sort
*/
void merge(int *vector, int begin, int middle, int end, int *moves, int *comparies){
    int *temp, p1, p2, tamanho, i, j, k;
    int end1 = 0, end2 = 0;
    tamanho = end-begin+1;
    p1 = begin;
    p2 = middle+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL)
    {
        for(i=0; i<tamanho; i++)
        {
            if(!end1 && !end2)
            {
                *comparies += 1;
                if(vector[p1] < vector[p2])
                {
                    *moves += 1;
                    temp[i]=vector[p1++];
                }
                else
                {
                    *moves += 1;
                    temp[i]=vector[p2++];
                }
                if(p1>middle)
                {
                    end1=1;
                }
                if(p2>end)
                {
                    end2=1;
                }
            }
            else
            {
                if(!end1)
                {
                    *moves += 1;
                    temp[i]=vector[p1++];
                }
                else
                {
                    *moves += 1;
                    temp[i]=vector[p2++];
                }
            }
        }
        for(j=0, k=begin; j<tamanho; j++, k++)
        {
            vector[k]=temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *vector, int begin, int end, int *moves, int *comparies){
    int middle;
    if(begin < end){
        middle = floor((begin + end) / 2);
        mergeSort(vector, begin, middle, moves, comparies);
        mergeSort(vector, middle+1, end, moves, comparies);
        merge(vector, begin , middle, end, moves, comparies);
    }
}

/*
* Quick Sort
*/
int partition(int *v, int begin, int end, int *moves, int *comparies){
    int left, right, pivo, aux;
    left = begin;
    right = end;
    pivo = v[begin];
    while(left < right){
        while(v[left] <= pivo){
            *comparies += 1;
            left++;
        }
        while(v[right] > pivo){
            *comparies += 1;
            right--;
        }
        if(left < right){
            *moves += 1;
            aux = v[left];
            v[left] = v[right];
            v[right] = aux;
        }
    }

    if(begin != right){
        *moves += 1;
        v[begin] = v[right];
        v[right] = pivo;
    }

    return right;
}

void quickSort(int *v, int begin, int end,int *moves, int *comparies){
    int pivo;
    if(end > begin){
        pivo = partition(v, begin, end, moves, comparies);
        quickSort(v, begin, pivo-1, moves, comparies);
        quickSort(v, pivo+1, end, moves, comparies);
    }
}
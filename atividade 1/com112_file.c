#include <stdlib.h>
#include <stdio.h>
#include "com112_file.h"

void output(int *vector, int len, int cod){

    FILE *arq;
    int i;

    if(cod == 1){
		arq = fopen("com112_saida_aleatorio.txt", "w");
	}else if(cod == 2){
		arq = fopen("com112_saida_crescente.txt", "w");
	}else{
		arq = fopen("com112_saida_decrescente.txt", "w");
	}
    
    fprintf(arq,"%d\n", len);
    for (i = 0; i < len; i++){
       fprintf(arq, "%d ", vector[i]);
    }

    fclose(arq);
}

void input(int *vector, int len, int cod){

    FILE *arq;
    int i;

    if(cod == 1){
		arq = fopen("com112_entrada_aleatorio.txt", "w");
	}else if(cod == 2){
		arq = fopen("com112_entrada_crescente.txt", "w");
	}else{
		arq = fopen("com112_entrada_decrescente.txt", "w");
	}


    fprintf(arq,"%d\n", len);
    for (i = 0; i < len; i++){
       fprintf(arq, "%d ", vector[i]);
    }
        
    fclose(arq);
} 

void reportFile(char *sort, int len, int moves, int comparies, double time, int cod){

    FILE *arq;

    if(cod == 1){
		arq = fopen("com112_relatorio_aleatorio.txt", "a");
	}else if(cod == 2){
		arq = fopen("com112_relatorio_crescente.txt", "a");
	}else{
		arq = fopen("com112_relatorio_decrescente.txt", "a");
	}

    fprintf(arq,"Numero de elementos ordenados: %d\n", len);

    fprintf(arq, "%s", sort);
    fprintf(arq,"Tempo: %f\n", time);
    fprintf(arq,"Comparações: %d\n", comparies);
    fprintf(arq,"Movimentações: %d\n\n", moves);

    fclose(arq);
    printf("\n");
}

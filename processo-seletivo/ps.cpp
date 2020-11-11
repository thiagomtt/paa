/*
Trabalho Processo Seletivo - PAA ENPE 2020

Thiago de Moraes Teixeira
RA: 760667
*/

#include <cstdio>
#include <iostream>
using namespace std; 


// troca dois números de posição
void swap(double *num1, double *num2){  
    double temp = *num1;  
    *num1 = *num2;  
    *num2 = temp;  
}  

int partition (double arr[], int start, int end){  
    // pivo
    double pivo = arr[end];
    // Índice do menor elemento
    int i = (start - 1);   
  
    for (int j = start; j <= end - 1; j++){  
        // se o elemento corrente for menor que o pivo 
        if (arr[j] < pivo){
            // incremente o índice do menor elemento  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  

    swap(&arr[i + 1], &arr[end]);  

    return (i + 1);  
}  
  
void quickSort(double arr[], int start, int end){  
    if (start < end){  
        // pi particiona o índice para arr[p] ficar correto
        int pi = partition(arr, start, end);  
 
        quickSort(arr, start, pi - 1);  
        quickSort(arr, pi + 1, end);  
    }  
}  

int main() { 

    int C, K, N;

    // N = número de vagas oferecidas
    scanf("%d ", &N);

    // Vetor para armazenar o resultado de cada vaga
    double * results;
    results = new double[N];    


    for (int i = 0; i < N; i++) {
        
        // K = número de pessoas chamadas para a segunda fase
        // C = número de pessoas que concorreram a vaga
        scanf("%d %d", &K, &C);

        // Vetor para armazenar o numero exato de notas de uma vaga
        double * notas;
        notas = new  double[C];

        // notas obtidas por cada um dos candidatos
    	for (int j = 0; j < C; j++)
            scanf("%lf", &notas[j]);

        // Ordena o vetor de notas 
        quickSort(notas, 0, C-1);
        
        // Pega a nota na posição C-K, que é a nota de corte desejada 
		results[i] = notas[C - K];

        // Delete o vetor para criar o proximo
        delete[] notas;
	}
    	
    // Apresenta o valor desejado para cada vaga 
    for(int i=0; i<N; i++){
    	printf("%.2lf\n", results[i]);
    }
    

	return 0; 
    
} 

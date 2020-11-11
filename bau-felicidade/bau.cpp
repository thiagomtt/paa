/*
Trabalho Baú da Felicidade - PAA ENPE 2020

Thiago de Moraes Teixeira
RA: 760667
*/

#include <cstdio>
#include <iostream>
using namespace std; 

// troca dois números de posição
void swap(int *num1, int *num2){  
    int temp = *num1;  
    *num1 = *num2;  
    *num2 = temp;  
}  

int partition (int arr[], int start, int end){  
    // pivo
    int pivo = arr[end];
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
  
void quickSort(int arr[], int start, int end){  
    if (start < end){  
        // pi particiona o índice para arr[p] ficar correto
        int pi = partition(arr, start, end);  
 
        quickSort(arr, start, pi - 1);  
        quickSort(arr, pi + 1, end);  
    }  
} 

int main() { 

    int N;
    int result;

    scanf("%d ", &N);

    // Vetor para armazenar as moedas
    int * moedas;
    moedas = new int[N];

    for (int j = 0; j < N; j++)
        scanf("%d", &moedas[j]);    

    // Variaveis para armazenar o valor que cada irmão vai receber
    int irmao1 = 0;
    int irmao2 = 0;

    // Ordena o vetor de moedas
    quickSort(moedas, 0, N-1);
    
    // Atribui o maior valor ao irmao1 para iniciar a comparação com o valor do outro 
    irmao1 += moedas[N-1];
    
    for (int i=N-2; i>=0; i--) {
        
        if(irmao1 >= irmao2)
            irmao2 += moedas[i];
        else
            irmao1 += moedas[i];
    }


    result = abs(irmao1-irmao2);

    printf("%d\n", result);

    return 0; 
    
} 

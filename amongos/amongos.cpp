/*
Trabalho Em Trenós - PAA ENPE 2020

Thiago de Moraes Teixeira
RA: 760667
*/

#include <cstdio>
#include <iostream>
#include <limits.h> 
#include <stdio.h> 
using namespace std; 
 
// Função que acha o vértice com a menor distância dos vértices que não foram
// incluidos no caminho mínimo ainda
int minDistance(float dist[], int M, bool sptSet[]){  
    int min = 10000, min_index; 
  
    for (int v = 0; v < M; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 

// Função que implementa o algoritmo de Dijkstra para um grafo representado
// pela matriz de adjacência
float dijkstra(float **graph, int M, int src){ 
	// Vetor de saída com o valor do caminho mínimo para todos os vértices partindo da fonte
    float *dist = new float[M];
  
  	// sptSet[i] será true se o vértice i estiver no caminho mínimo entre a fonte e i 
    bool *sptSet = new bool[M]; 
  
    // Inicializa todas as distâncias como ""infinito"" and stpSet[] as false 
    for (int i = 0; i < M; i++) 
        dist[i] = 10000000000, sptSet[i] = false; 
  
    // A distância do vértice pra ele mesmo sempre é 0  
    dist[src] = 0.0; 
  
    // Acha o caminho mínimo para todos os vértices a partir da fonte
    for (int count = 0; count < M - 1; count++) { 
        // Pega o vértice de distância mínima dos vértices que ainda
        // não foram processados
        int u = minDistance(dist, M, sptSet); 
  
        // Marca o vértice como processado
        sptSet[u] = true; 
  
        // Atualiza o valor da distância dos vértices adjacentes ao escolhido
        for (int v = 0; v < M; v++) 
            // Atualiza dist[v]: 
            //	- se não estiver em sptSet
            //	- se houver outro caminho de u até v e o total do caminho da 
            //		fonte para v passando por u é menor que o valor de dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != 10000 && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    // Retorna o valor do menor caminho para o vértice 0 (sala do botão do nosso problema) 
    return dist[0];
}  
  
int main(){
	// M = Número de salas
	// E = Número de corredores
	// N = Número de tubulações
	// C = Número de consultas
	int M, E, N, C;
	scanf("%d %d %d %d", &M, &E, &N, &C);

	// Matriz MxM para armazenar o peso das arestas do grafo do tripulante
	float **corredores_tripulante;
	corredores_tripulante = new float *[M];
	for(int i=0; i<M; i++)
		corredores_tripulante[i] = new float[M];

	// Recebe a linha/coluna que serão os vértices e o peso da aresta entre eles
	int x = 0;
	int linha, coluna;
	float peso;
	while (x<E){
		scanf("%d %d %f", &linha, &coluna, &peso);
		corredores_tripulante[linha][coluna] = peso;
		corredores_tripulante[coluna][linha] = peso;
		x += 1;
	}

	// Matriz MxM para armazenar o peso dos vértices do grafo do impostor
	float **corredores_impostor;
	corredores_impostor = new float *[M];
	for(int i=0; i<M; i++)
		corredores_impostor[i] = new float[M];

	// Copia os valores do grafo do tripulante para o impostor
	// pois o grafo do impostor será menor(ou igual) ao grafo do tripulante
	for(int i=0; i<M; i++)
		for(int j=0; j<M; j++)
			corredores_impostor[i][j] = corredores_tripulante[i][j];

	// Matriz MxM para representar os vértices que tem tubulação entre eles
	float **tubulacao;
	tubulacao = new float *[M];
	for(int i=0; i<M; i++)
		tubulacao[i] = new float[M];	

	// Recebe a linha/coluna que são os vértices da tubulação, peso constante = 1.0 
	x = 0;
	while (x<N){
		scanf("%d %d", &linha, &coluna);
		tubulacao[linha][coluna] = 1.0;
		tubulacao[coluna][linha] = 1.0;
		x += 1;
	}

	// Varre a matriz do impostor com o propósito de:
	// - Substituir onde o valor do corredor é maior que 1.0 e há uma tubulação possível
	// - "Criar" a aresta onde não há corredor porém o impostor pode usar a tubulação, se existir
	for(int i=0; i<M; i++)
		for(int j=0; j<M; j++){
			if(tubulacao[i][j] == 1.0 && (corredores_impostor[i][j] > tubulacao[i][j] || corredores_impostor[i][j] == 0))
				corredores_impostor[i][j] = 1.0;
		}

	// Vetor com os casos de teste
	int *casos = new int[C];
	x = 0;
	while (x<C){
		scanf("%d", &casos[x]);
		x+=1;
	}

	// Varre o vetor de casos efetuando os testes e imprime o resultado
	float custo_tripulante, custo_impostor;
	for(int i=0; i<C; i++){
		custo_tripulante = dijkstra(corredores_tripulante, M, casos[i]) * 100;
		custo_impostor = dijkstra(corredores_impostor, M, casos[i]) * 100 + 0.1;

		if (custo_tripulante <= custo_impostor)
			printf("victory\n");
		else
			printf("defeat\n");
	}

    return 0; 
} 

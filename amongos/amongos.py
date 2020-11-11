'''
Trabalho Em Trenós - PAA ENPE 2020

Thiago de Moraes Teixeira
RA: 760667
'''

import sys 
import numpy as np
import time
  
class Graph(): 
  
    def __init__(self, vertices): 
        self.V = vertices 
        self.graph = [[0 for column in range(vertices)]  
                    for row in range(vertices)] 
  
    # A utility function to find the vertex with  
    # minimum distance value, from the set of vertices  
    # not yet included in shortest path tree 
    def minDistance(self, dist, sptSet): 
  
        # Initilaize minimum distance for next node 
        min = sys.maxsize 
  
        # Search not nearest vertex not in the  
        # shortest path tree 
        for v in range(self.V): 
            if dist[v] < min and sptSet[v] == False: 
                min = dist[v] 
                min_index = v 
  
        return min_index 
  
    # Funtion that implements Dijkstra's single source  
    # shortest path algorithm for a graph represented  
    # using adjacency matrix representation 
    def dijkstra(self, src): 
  
        dist = [sys.maxsize] * self.V 
        dist[src] = 0
        sptSet = [False] * self.V 
  
        for cout in range(self.V): 
  
            # Pick the minimum distance vertex from  
            # the set of vertices not yet processed.  
            # u is always equal to src in first iteration 
            u = self.minDistance(dist, sptSet) 
  
            # Put the minimum distance vertex in the  
            # shotest path tree 
            sptSet[u] = True
  
            # Update dist value of the adjacent vertices  
            # of the picked vertex only if the current  
            # distance is greater than new distance and 
            # the vertex in not in the shotest path tree 
            for v in range(self.V): 
                if self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]: 
                        dist[v] = dist[u] + self.graph[u][v] 
  
        return dist[0] 


def main():
	# M = Número de salas
	# E = Número de corredores
	# N = Número de tubulações
	# C = Número de consultas
	M, E, N, C = (int(x) for x in input().split())

	# Lista de tuplas para armazenar os pares de vértices ligados e seu peso
	corredores_tripulante = []
	triplas = input().split()
	x = 0
	while x < 3*E:
		corredores_tripulante.append(tuple((int(triplas[x]), int(triplas[x+1]), float(triplas[x+2]))))
		x += 3

	grafo_tripulante_matriz = np.zeros((M, M))

	for corredor in corredores_tripulante:
		grafo_tripulante_matriz[corredor[0]][corredor[1]] = corredor[2]
		grafo_tripulante_matriz[corredor[1]][corredor[0]] = corredor[2]

	grafo_tripulante = Graph(M)
	grafo_tripulante.graph = grafo_tripulante_matriz

	# Lista de tuplas para o impostor será a mesma do que o tripulante adicionado as tubulações
	corredores_impostor = corredores_tripulante.copy()
	# Lista de tuplas com os vértices da tubulação
	tubulacao = []

	pares = input().split()
	x = 0
	while x < 2*N:
		tubulacao.append(tuple((int(pares[x]), int(pares[x+1]), float(1.0))))
		x += 2

	for s in range(len(tubulacao)):
		for x in range(len(corredores_impostor)):
			if corredores_impostor[x][0] == tubulacao[s][0] and corredores_impostor[x][1] == tubulacao[s][1] and corredores_impostor[x][2]>1.0:
				del corredores_impostor[x]
				corredores_impostor.insert(x, tubulacao[s])
			if corredores_impostor[x][0] == tubulacao[s][0] and corredores_impostor[x][1] == tubulacao[s][1] and corredores_impostor[x][2]<1.0:
				del tubulacao[s]
				tubulacao.insert(s, corredores_impostor[x])

	for tubo in tubulacao:
		if not tubo in corredores_impostor:
			corredores_impostor.append(tubo)

	grafo_impostor_matriz = np.zeros((M, M))

	for corredor in corredores_impostor:
		grafo_impostor_matriz[corredor[0]][corredor[1]] = corredor[2]
		grafo_impostor_matriz[corredor[1]][corredor[0]] = corredor[2]		

	grafo_impostor = Graph(M)
	grafo_impostor.graph = grafo_impostor_matriz

	# Lista de casos 
	casos = []
	x = 0
	while x < C:
		try:
			caso = input()
			casos.append(int(caso))
		except EOFError:
			None
		x += 1

	for caso in casos:
		custo_tripulante = grafo_tripulante.dijkstra(caso)
		#print(f'custo do tripulante: {custo_tripulante}')

		custo_impostor = grafo_impostor.dijkstra(caso)
		#print(f'custo do impostor  : {custo_impostor}')


		if custo_tripulante <= custo_impostor:
			print('victory')
		else:
			print('defeat')
	
if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))

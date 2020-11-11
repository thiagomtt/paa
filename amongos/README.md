# Em Trenós

-	Descrição detalhada no arquivo pdf. 

-	Feito primeiramente em *Python* porém com tempo de execução entre \~0.8sec retornando erro (timeout) nos casos de teste do [RunCodes](https://run.codes/) (plataforma escolhida pelo professor). 
	Então foi reescrito em *C++* para obter sucesso na plataforma. 

**Entrada**

> A entrada apresenta um único grafo conexo, a descrição das tubulações e várias
> consultas. A primeira linha contém os valores inteiros **M**, **E**, **N** e​ **C** **(2≤M≤100,​ 2≤N≤20,​ M​≤E≤M​<sup>2</sup>​-M, 2≤C≤M)**, representando os números de salas, de ligações entre
> elas por meio de corredores, de ligações entre salas por tubulações e de consultas,
> respectivamente. Na próxima linha, encontram-se ​**3\*E** valores apresentados em triplas
> **(U, V, D), ​(0≤U, V<M, 0.5≤D≤10.0​)**, que descrevem as ligações entre as salas​ **U** e
> **V** por meio de um corredor com comprimento ​**D**. Os indicadores de vértices são
> números inteiros, enquanto o valor de distância pertence aos reais e é apresentado
> com uma casa decimal. A seguir, são apresentados ​**2\*N** números inteiros,
> representando os pares ​(U, V), ​(0≤U, V<M), que descrevem o fato de haver uma ligação entre as salas **U** e **V** por meio de tubos de ventilação, com distância 1 entre
> elas. A partir da quarta linha, há **C** linhas de consultas. Cada uma dessas linhas é
> composta por um inteiro, representando a sala onde você viu o impostor.

**Saída**

> Para cada uma das linhas de consulta, o seu programa deve imprimir “​**defeat​**” caso o
> impostor consiga chegar antes de sua personagem ao vértice 0 ou “​**victory​**”, caso
> contrário.
# Introdução
<p>
O objetivo deste projeto é apresentar 4 dos algoritmos estudados na disciplina <b>Teoria dos Grafos</b>, 
do curso <b>Ciência da Computação</b> pela <b>Universidade Federal de Alagoas</b>.<br>
<hr>
Cada pasta de cada algoritmo contém: <br><br> 
1. <tt>arquivo.cpp</tt> - código fonte escrito em C++;<br><br>
2. <tt>exemplo_de_grafo.dat</tt> - exemplo de entrada em que na primeira linha se encontram, respectivamente, o <b>número de vértices</b>, 
o <b>número de arestas</b> e o <b>vértice
inicial</b> (apenas para os algoritmos que exigem essa informação, como Dijkstra). As demais linhas apresentam as ligações existentes
entre cada par de vértices e seus respectivos pesos, dispostos em três "colunas" de valores. Exemplo: <br>
                      
<kbd>
6 10 0<br>
0 1 5<br>
0 2 6<br>
0 3 4<br>
1 2 1<br>
1 3 2<br>
2 3 2<br>
2 4 5<br>
2 5 3<br>
3 5 4<br>
4 5 4 <br>
</kbd>
<br>O grafo acima contém 6 vértices, 10 arestas e vértice inicial 0 dada a primeira linha. As demais linhas representam
as ligações entre u-v e seu respectivo peso.<br>
<b>Obs: A utilização dos vértices pelo programa se dá pelo intervalo numérico de 0 a N vértices, logo,
deve-se adotar esse padrão em arquivos de input.
</b>
<br><br>
3. <tt>makefile</tt> - arquivo para execução rápida no terminal.

# Execução dos arquivos
<p>
Para executar um programa no terminal, abra a pasta do algoritmo escolhido e digite o comando <tt>make</tt> para <i>compilar e executar</i> o código utilizando
o grafo contido na mesma pasta como input.<br>

Para <i>compilar sem executar</i> com o grafo de exemplo, digite o comando <tt>make build</tt>. Assim, fica a cargo do usuário executar o programa com a liberdade 
de inserir outro grafo como input.<br>

Para <i>remover</i> o arquivo gerado pela compilação, digite o comando <tt>make clean</tt>.


</p>

# Algoritmos escolhidos
<br>
<p align=center> 
<tt>Bellman Ford</tt><br> O Algoritmo de Bellman-Ford é um algoritmo de busca de caminho mínimo em um digrafo (grafo orientado ou dirigido) 
ponderado, ou seja, cujas arestas têm peso, inclusive negativo. O Algoritmo de Dijkstra resolve o mesmo problema, 
num tempo menor, porém exige que todas as arestas tenham pesos positivos.<br>Fonte: <a href=https://pt.wikipedia.org
/wiki/Algoritmo_de_Bellman-Ford#:~:text=O%20Algoritmo%20de%20Bellman%2DFord,as%20arestas%20tenham%20pesos%20positivos.>Algoritmo de Bellman Ford</a><hr>
</p align=center>

<p align=center> 
<tt>Dijkstra</tt><br> É um dos algoritmos que calcula o caminho de custo mínimo entre vértices de um grafo. 
Escolhido um vértice como raiz da busca, este algoritmo calcula o custo mínimo deste vértice para todos os demais vértices do grafo. 
Ele é bastante simples e com um bom nível de performance. 
Ele não garante, contudo, a exatidão da solução caso haja a presença de arcos com valores negativos. <br> 
Fonte: <a href=https://www.inf.ufsc.br/grafos/temas/custo-minimo/dijkstra.html>Algoritmo de Dijkstra</a><hr>
</p align=center>

<p align=center>
<tt>Kruskal</tt><br>O algoritmo de Kruskal é um algoritmo em teoria dos grafos que busca uma árvore geradora mínima para um grafo
conexo com pesos. Isto significa que ele encontra um subconjunto das 
arestas que forma uma árvore que inclui todos os vértices, onde o peso total, dado pela soma dos pesos das arestas da árvore, é minimizado.<br>
Fonte: <a href=https://pt.wikipedia.org/wiki/Algoritmo_de_Kruskal#:~:
text=O%20algoritmo%20de%20Kruskal%20%C3%A9,arestas%20da%20%C3%A1rvore%2C%20%C3%A9%20minimizado.>Algoritmo de Kruskal</a><hr>
</p align=center>

<p align=center>
<tt>Prim</tt><br>Na ciência da computação o algoritmo de Prim é um algoritmo guloso (greedy algorithm) 
empregado para encontrar uma árvore geradora mínima (minimal spanning tree) num grafo conectado, valorado e não direcionado.<br>
Fonte: <a href=https://pt.wikipedia.org/wiki/Algoritmo_de_Prim#:~:text=Na%20ci%C3%AAncia%20da%20computa%C3%A7%C3%A3o%20o,
conectado%2C%20valorado%20e%20n%C3%A3o%20direcionado.>Algoritmo de Prim</a><hr>
</p align=center>

</p>

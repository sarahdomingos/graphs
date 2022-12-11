#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

class CompConex {
    public:
    int pai, rank;
};

class Edge {
    int u, v, p;

    public:

    Edge(int u1, int v1, int p) {
        u = u1;
        v = v1;
        this->p = p;
    }
    int find_u () {
        return u;
    }
    int find_v () {
        return v;
    }
    int find_p () {
        return p;
    }
    // Sobrescrição do operador menor que, para organizar as arestas do menor ao maior peso.
    bool operator < (const Edge& edge2) const {
        return (p < edge2.p);
    }
};

class Graph {
    int n;
    vector<Edge>edges;
    public:

    Graph (int n) {
        this->n = n;
    }

    void add_edge (int u, int v, int p) {
        Edge edge (u, v, p);
        edges.push_back(edge);
    }

    // Função recursiva para encontrar o pai da componente conexa.
    int FIND (int u, CompConex comp_conex[]) {
        if (comp_conex[u].pai != u) {
            comp_conex[u].pai = FIND (comp_conex[u].pai, comp_conex);
        }
        return comp_conex[u].pai;
    }

    // Função para unir duas componentes conexas, alterando o pai da menor componente e seu rank, caso a condição seja atendida.
    void UNION (int u, int v, CompConex comp_conex[]) {
        if (comp_conex[u].rank >= comp_conex[v].rank) {
            comp_conex[v].pai = u;
            if (comp_conex[u].rank == comp_conex[v].rank) {
                comp_conex[u].rank++;
            }
        }
        else {
            comp_conex[u].pai = v;
        }
    }

    // Inicializa os valores de cada pai e rank.
    void MAKE_SET (CompConex comp_conex[]) {
        for (int i = 0; i < n; i++) {
            comp_conex[i].pai = i;
            comp_conex[i].rank = 0;
        }
    }

    void imprime_arvore (vector<Edge>arvore) {  
        int custoTotal = 0;
        cout << "u v peso" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << arvore[i].find_u() << " " << arvore[i].find_v() << "  " << arvore[i].find_p() << endl;
                custoTotal += arvore[i].find_p();
        }
        cout << "Custo total: " << custoTotal << endl;
    }

    void kruskal () {
        vector<Edge>arvore; // Cria árvore vazia.
        sort(edges.begin(), edges.end()); // Organiza as arestas da menor até a de a maior peso.

        // Criação e inicialização de n (vértices) componentes conexas.
        CompConex *comp_conex = new CompConex[(n * sizeof(CompConex))];
        MAKE_SET(comp_conex);

        for (int i = 0; i < m; i++) {
            int u = FIND(edges[i].find_u(), comp_conex); // Retorna o pai de u;
            int v = FIND(edges[i].find_v(), comp_conex); // Retorna o pai de v;
            if (u != v) { // Checagem para não gerar um ciclo na árvore.
                arvore.push_back(edges[i]);
                UNION(u, v, comp_conex);
            }
        }
        imprime_arvore (arvore);
    }
};

int main () {
    // Input do número de vértices (n) e número de arestas (m).
    cin >> n >> m;

    // Criação do grafo g.
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        g.add_edge(u, v, p);
    }
    g.kruskal();
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#define INFINITO 9999
using namespace std;

void imprime_caminho_minimo (vector<int>prev, vector<int>dist) {
    cout << "V Dist Prev" << endl;
    for (int i = 0; i < dist.size(); i++){
        cout << i << "   " << dist[i] << "   " << prev[i] << endl;
    }
    cout<<endl;
}

void dijkstra (vector<vector<int> >&w, vector<vector<int> >&adj, int origem) {

    int n = w.size(); // Número de vértices.
    vector<int>dist(n, INFINITO); // Vetor de distâncias do vértice de origem aos demais vértices.
    vector<int>prev(n, -1); // Vetor do vértice predecessor (para registro do caminho mínimo).
    dist[origem] = 0; // A distância da origem para ela mesma é zero.
    prev[origem] = origem; // O predecessor da origem é ela própria.

    // Lista de prioridade da menor à maior distância (estruturada por uma heap).
    auto cmp = [&](int& esq, int& dir) {
        return dist[dir] < dist[esq];
    };
    priority_queue<int, vector<int>, decltype(cmp)> fila(cmp);
    fila.push(origem); // A origem é a primeira a entrar na lista por ser a única com distância conhecida.
    
    while (!fila.empty()){
        // Atribui e remove o menor elemento da lista, que pela heap está sempre no topo.
        int u = fila.top();
        fila.pop();
        
        // Percorre os vizinhos de u.
        for (int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];

            // Se a atual distância de v for maior que o caminho até u mais o peso da aresta u-v,
            // a distância de v é atualizada e v entra na fila de prioridade.
            if (dist[v] > dist[u] + w[u][v]) { 
                dist[v] = dist[u] + w[u][v];
                prev[v] = u;
                fila.push(v);
            }
        }
    }
    imprime_caminho_minimo (prev, dist);
}

int main() {
    // Input do núemro de vértices (n), número de arestas (m) e vértice de origem (origem).
    int n, m, origem;
    cin >> n >> m >> origem;

    // Criação de uma lista de adjacência (adj) e uma matriz de pesos (w).
    vector<vector<int> > w;
    vector<vector<int> > adj(n, vector<int>(0));
    
    for (int i = 0; i < n; i++) {
        vector<int>info;
        for (int j = 0; j < n; j++) {
            info.push_back(-1);
        }
        w.push_back(info);
    }

    // Criação do GRAFO NÃO DIRECIONADO com arestas u-v e peso p.
    int u, v, p;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        adj[u].push_back(v);
        adj[v].push_back(u);
        w[u][v] = p;
        w[v][u] = p;
    }
    dijkstra (w, adj, origem);
    return 0;
}

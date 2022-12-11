#include <iostream>
#include <vector>
#define INFINITO 9999
using namespace std;

void imprime_caminho_minimo (vector<int> dist) {
    cout << "V  Dist" << endl;
    for (int i = 0; i < dist.size(); i++) {
            cout << i << "   " << dist[i] << endl;
        }
}

bool ciclo_negativo (vector<vector<int> > &adj, vector<vector<int> > &w, vector<int> dist) {
    int n = w.size();

    // Repete as verificações nas arestas e se surgir um novo menor caminho,
    // então há um ciclo negativo no grafo.
    for (int u = 0; u < n; u++) {
        for (int k = 0; k < adj[u].size(); k++) {
            int v = adj[u][k];
            if (dist[u] != INFINITO && dist[u] + w[u][v] < dist[v]) {
                cout << "O grafo possui ciclo negativo." << endl;
                return true;
            }
        }
    }
    return false;
}

void bellman_ford (vector<vector<int> > &adj, vector<vector<int> > &w, int origem) {
    int n = w.size(); // Número de vértices.
    vector<int> dist (n, INFINITO); // Vetor de distâncias do vértice de origem aos demais vértices.
    dist[origem] = 0; // A distância da origem para ela mesma é zero.

    for (int u = 0; u < n; u++) {
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i]; // Atribui a v os vizinhos de u.

            // Verificação da menor distância dado a dist atual de v e a soma do caminho
            // até u com o peso da aresta u-v;
            if (dist[u] != INFINITO && dist[v] > dist[u] + w[u][v]) {
            dist[v] = dist[u] + w[u][v];
            }
        }
    }

    if (!ciclo_negativo(adj, w, dist)) {
        imprime_caminho_minimo (dist);
    }
}

int main (){
    // Input do núemro de vértices (n), número de arestas (m) e vértice de origem (origem).
    int n, m, origem;
    cin >> n >> m >> origem;

    // Criação de uma lista de adjacência (adj) e uma matriz de pesos (w).
    vector<vector<int> > w;
    vector<vector<int> > adj(n, vector<int>(0));

    for (int i = 0; i < n; i++) {
        vector<int>info;
        for (int j = 0; j < n; j++) {
            info.push_back(INFINITO);
        }
        w.push_back(info);
    }

     // Criação do GRAFO DIRECIONADO com arestas u-v e peso p.
    int u, v, p;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        w[u][v] = p;
        adj[u].push_back(v);
        //adj[v].push_back(u);
        //w[v][u] = p;
    }
    bellman_ford (adj, w, origem);
    return 0;
}
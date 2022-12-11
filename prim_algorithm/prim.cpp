#include <iostream>
#include <vector>
#include <queue>
#define INFINITO 9999
using namespace std;

void imprime_resultado (vector<int>custo, vector<int>prev) {
    cout << "V   " << "Pai   " << "Custo" << endl;
    int custoTotal = 0;
    for (int i = 0; i < custo.size(); i++){
        cout << i << "     " << prev[i] << "     " << custo[i] << endl;
        custoTotal += custo[i];
    }
    cout << "Custo total: " << custoTotal << endl;
}

void prim (vector<vector<int> > &adj, vector<vector<int> > &w, int origem) {
    int n = w.size(); // Número de vértices.
    vector<int>custo(n, INFINITO); // Vetor do custo das arestas.
    vector<int>prev(n, -1); // Vetor do vértice predecessor.
    vector<int>check(n, 1); // Vetor binário para checagem da presença de cada vértice na lista de prioridades.
    custo[origem] = 0; // O custo da origem para ela mesma é zero.
    prev[origem] = origem; // O predecessor da origem é ela própria.

    // Lista de prioridade do menor ao maior custo (estruturada por uma heap).
    auto cmp = [&](int& esq, int& dir) {
        return custo[dir] < custo[esq];
    };
    priority_queue<int, vector<int>, decltype(cmp)> fila(cmp);
    fila.push(origem); // A origem é a primeira a entrar na lista por ser a única com custo conhecido.

    while (!fila.empty()) {
        // Atribui, remove e altera o vetor binário dado o vértice de menor custo da fila.
        int v = fila.top();
        fila.pop();
        check[v] = 0;

        // Percorre os vizinhos de u.
        for (int i = 0; i < adj[v].size(); i++) {
            int z = adj[v][i];
            if (check[z] == 1){ // A próxima verificação só ocorre se z está na fila.
                
                // Se o custo atual de z é maior que o peso da aresta v-z, o custo e o predecessor de z é atualizado.
                if (custo[z] > w[v][z]) {
                    custo[z] = w[v][z];
                    prev[z] = v;
                    fila.push(z); // z entra na fila.
                }
            }

        }
    }
    imprime_resultado (custo, prev);
}

int main () {
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
    prim(adj, w, origem);
    return 0;
}
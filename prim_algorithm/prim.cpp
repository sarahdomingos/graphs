#include <iostream>
#include <vector>
#include <queue>
#define INFINITO 9999
using namespace std;

void prim (vector<vector<int> > &adj, vector<vector<int> > &w, int origem) {

    int n = w.size();
    vector<int>custo(n, INFINITO);
    vector<int>prev(n, -1);
    vector<int>check(n, 1);
    custo[origem] = 0;
    prev[origem] = origem;

    auto cmp = [&](int& esq, int& dir) {
        return custo[dir] < custo[esq];
    };
    priority_queue<int, vector<int>, decltype(cmp)> fila(cmp);
    fila.push(origem);

    while (!fila.empty()) {
        int v = fila.top();
        fila.pop();
        check[v] = 0;

        for (int i = 0; i < adj[v].size(); i++) {
            int z = adj[v][i];
            if (check[z] == 1){
                if (custo[z] > w[v][z]) {
                    custo[z] = w[v][z];
                    prev[z] = v;
                    fila.push(z);
                }
            }

        }
    }

    cout << "V   " << "Pai   " << "Custo" << endl;
    int custoTotal = 0;
    for (int i = 0; i < n; i++){
        cout << i << "     " << prev[i] << "     " << custo[i] << endl;
        custoTotal += custo[i];
    }
    cout << "Custo total: " << custoTotal << endl;

}

int main () {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > w;
    vector<vector<int> > adj(n, vector<int>(0));
    
    for (int i = 0; i < n; i++) {
        vector<int>info;
        for (int j = 0; j < n; j++) {
            info.push_back(-1);
        }
        w.push_back(info);
    }

    int u, v, p;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        adj[u].push_back(v);
        adj[v].push_back(u);
        w[u][v] = p;
        w[v][u] = p;
    }
    prim(adj, w, 0);
}
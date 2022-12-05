#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra (vector<vector<int> >&w, vector<vector<int> >&adj, int origem) {

    int n = w.size();
    vector<int>dist(n, 9999);
    vector<int>prev(n, -1);
    dist[origem] = 0;
    prev[origem] = origem;

    auto cmp = [&](int& esq, int& dir) {
        return dist[dir] < dist[esq];
    };
    priority_queue<int, vector<int>, decltype(cmp)> fila(cmp);
    
    fila.push(origem);
    
    while (!fila.empty()){
        int u = fila.top();
        fila.pop();

        for (int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if (dist[v] > dist[u] + w[u][v]) {
                dist[v] = dist[u] + w[u][v];
                prev[v] = u;
                fila.push(v);
            }
        }
    }

   for (int i = 0; i < n; i++){
        cout << i << " " << dist[i] << " " << prev[i] << endl;
    }
    cout<<endl;
}

int main() {

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
    dijkstra (w, adj, 0);
}

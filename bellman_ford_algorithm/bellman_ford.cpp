#include <iostream>
#include <vector>

#define INFINITO 9999
using namespace std;

void bellman_ford (vector<vector<int> > &w, int origem, int n) {
    vector<int> dist;
    for (int i = 0; i < n; i++) {
        dist.push_back(INFINITO);
    }
    dist[origem] = 0;

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (w[j][k] != INFINITO){
                if (dist[j] != INFINITO && dist[j] + w[j][k] < dist[k]) {
                dist[k] = dist[j] + w[j][k];
                }
                
            }
        }
            
    }

    for (int i = 0; i < dist.size(); i++) {
       cout << i << " " << dist[i] << endl;
    }
}

int main (){

    int n, m;
    cin >> n >> m;

    vector<vector<int> > w;
    
    for (int i = 0; i < n; i++) {
        vector<int>info;
        for (int j = 0; j < n; j++) {
            info.push_back(INFINITO);
        }
        w.push_back(info);
    }

    int u, v, p;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        w[u][v] = p;
        //w[v][u] = p;
    }

    bellman_ford (w, 0, n);
}

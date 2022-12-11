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

    int FIND (int u, CompConex comp_conex[]) {
        if (comp_conex[u].pai != u) {
            comp_conex[u].pai = FIND (comp_conex[u].pai, comp_conex);
        }
        return comp_conex[u].pai;
    }

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

    void MAKE_SET (CompConex comp_conex[]) {
        for (int i = 0; i < n; i++) {
            comp_conex[i].pai = i;
            comp_conex[i].rank = 0;
        }
    }

    void kruskal () {
        vector<Edge>arvore;
        sort(edges.begin(), edges.end());
        CompConex *comp_conex = new CompConex[(n * sizeof(CompConex))];
        MAKE_SET(comp_conex);

        for (int i = 0; i < m; i++) {
            int u = FIND(edges[i].find_u(), comp_conex);
            int v = FIND(edges[i].find_v(), comp_conex);
            if (u != v) {
                arvore.push_back(edges[i]);
                UNION(u, v, comp_conex);
            }
        }

        int custoTotal = 0;
        cout << "u v peso" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << arvore[i].find_u() << " " << arvore[i].find_v() << "  " << arvore[i].find_p() << endl;
            custoTotal += arvore[i].find_p();
        }
        cout << "Custo total: " << custoTotal << endl;
    }
};

int main () {
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; i++) {

        int u, v, p;
        cin >> u >> v >> p;
        g.add_edge(u, v, p);
       
    }
    g.kruskal();
}
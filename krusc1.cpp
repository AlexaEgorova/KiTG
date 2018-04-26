#include <bits/stdc++.h>
using namespace std;

struct dsu{
    struct edge{
        int a{0};
        int b{0};
        int w{0};
        edge() {};
        edge(int a, int b, int w): a(a-1), b(b-1), w(w){
        }
    };
    
    vector<int> parent;
    vector<int> rank;
    vector<edge> edges;
    void init(int n){
        rank.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i += 1)
            parent[i] = i;
    }
    static bool comp(edge a, edge b){
        return a.w < b.w;
    }
    dsu(int n){
        init(n);
    }
    dsu(int n, int m){
        init(n);
        edges.resize(m);
        for (int i = 0; i < m; i += 1){
            int a, b, w;
            cin >> a >> b >> w;
            edges[i] = edge(a, b, w);
        }
        sort(edges.begin(), edges.end(), comp);
    }
    int find(int x){
        if (x != parent[x])
        	parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if (fx == fy)
            return false;
        if (rank[fx] > rank[fy])
            swap(fx, fy);
        parent[fx] = fy;
        if (rank[fx] == rank[fy])
            rank[fy]++;
        return true;
    }
    void getLength(int& sum){
        for(int i = 0; i < edges.size(); i += 1)
            if (unite(edges[i].a, edges[i].b))
                sum += edges[i].w;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    dsu ex(n, m);
    int ans = 0;
    cout << (ex.getLength(ans), ans) << endl;
}

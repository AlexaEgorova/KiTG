#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct dsu {
    struct edge {
        int a, b, w;
        edge() = default;
        edge(int a, int b, int w):a(a), b(b), w(w) {
        }
    };
    vector<edge> edges;
	vector<int> parent;
	vector<int> rank; //глубина вершины
	dsu() = default;
    static bool comp(edge x, edge y){
        return x.w < y.w;
    }
	dsu(int n, int m) 
    {
        parent.resize(n);
        edges.resize(m);
        rank.resize(n, 0);
        for (int i = 0; i < n; i += 1)
        {
            parent[i] = i;
        }
        for (int i = 0; i < m; i += 1)
        {
            cin >> edges[i].a >> edges[i].b >> edges[i].w;
            --edges[i].a, --edges[i].b;
        }
        sort(edges.begin(), edges.end(), comp);

    }
	int find(int x) {
		int y = x;
		while (parent[x] != x) {
			x = parent[x];
		}
		while (parent[y] != y) {
			int tmp = y;
			y = parent[y];
			parent[tmp] = y;
		}
		return x;
	}
	bool unio(int x, int y) {
		int fx = find(x), fy = find(y);
        if (fx == fy) return false;
		if (rank[x] > rank[y]) {
			parent[fy] = fx;
		}
		else {
			parent[fx] = fy;
			if (rank[x] == rank[y]) rank[y]++;
		}
        return true;
	}
    void kruskal(){
        int res = 0;
        for (int i = 0; i < edges.size(); i += 1)
        {
            if(unio(edges[i].a, edges[i].b)) res += edges[i].w;
        }
        cout << res;
    }
};

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    dsu name(n, m);
    name.kruskal();
}

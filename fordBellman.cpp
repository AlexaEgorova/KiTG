#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long inf = 1e7;
	int n, m;
	cin >> n >> m;
	vector<int> H(n, -1), L(m), I(m), J(m), C(m);
	for (int i = 0; i < m; i += 1){
		cin >> I[i] >> J[i] >> C[i];
		--I[i], --J[i];
	}
	for (int i = 0; i < m; i += 1){
		L[i] = H[I[i]];
		H[I[i]] = i;
	}
	vector<int> distance(n, inf);
	distance[0] = 0;
	for (int i = 0; i < n - 1; i+=1){
		for (int j = 0; j < m; j+=1){
			if (distance[I[j]] < inf){
				distance[J[j]] = min(distance[J[j]], distance[I[j]] + C[j]);
			}
		}
	}
	for (int i = 0; i < n; i += 1){
		if (distance[i] == inf)
			distance[i] = 30000;
		cout << distance[i] << " \n"[i + 1==n];
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long inf = 1e7; //изначально расстояние до всех вершин будет равно бесконечности = 10000000
	int n, m;
	cin >> n >> m;
	vector<int> H(n, -1), L(m), I(m), J(m), C(m);
	for (int i = 0; i < m; i += 1){
		cin >> I[i] >> J[i] >> C[i];
		//--I[i], --J[i];//расскомментировать, если вершины в задаче нумеруются с единицы
	}
	for (int i = 0; i < m; i += 1){
		L[i] = H[I[i]];
		H[I[i]] = i;
	}
	vector<int> distance(n, inf);
	distance[0] = 0;//Расстояние от вершины с которой считаем до неё же самой 0
	for (int i = 0; i < n - 1; i+=1){
		for (int j = 0; j < m; j+=1){
			if (distance[I[j]] < inf){//Заходим, если эта вершина была хоть раз затронута;
				/*В нашей задаче первый раз выполнится, когда
				ребро будет исходить из вершины 0
				*/
				distance[J[j]] = min(distance[J[j]], distance[I[j]] + C[j]);
				/*
				Берём минимум из расстояния которое было посчитано до этой вершины
				и расстояние которое может быть с новым ребром
				*/
			}
		}
	}
	for (int i = 0; i < n; i += 1){
		if (distance[i] == inf)
			distance[i] = 30000;//для задачи http://acmp.ru/index.asp?main=task&id_task=138
		cout << distance[i] << " \n"[i + 1==n];//Выводим расстояние до всех вершин от вершины 0
	}
	return 0;
}
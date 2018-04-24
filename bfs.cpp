#include <bits/stdc++.h>
using namespace std;

int main(){
	int m;
	int sizeH = -1;
	cout << "Введите количество ребёр\n";
	cin >> m;
	vector<int> I(m);
	vector<int> J(m);
	int a = 0, b = 0;
	for(int k = 0; k < m; k += 1){
		cin >> a;
		cin >> b;
		sizeH = max(sizeH, max(a, b));//поиск вершины с максимальным номером, чтобы задать размер Head
		I[k] = a;
		J[k] = b;
	}
	sizeH += 1;//Так как количество вершин от 0 до sizeH  -> sizeH + 1
	vector<int> H(sizeH, -1);
	vector<int> L(m);
	for(int k = 0; k < m; k += 1){
		L[k] = H[I[k]];
		H[I[k]] = k;
	}
	vector<int> parent(sizeH, -1);
	vector<int> distance(sizeH, 1e8);//заполняем вектор числами 10^8, типа бесконечности в нашем случае
	queue<int> ochered;
	int startovayaVershina = 0;
	cout << "Введите начальную вершину\n";
	cin >> startovayaVershina;
	distance[startovayaVershina] = 0;
	parent[startovayaVershina] = startovayaVershina;
	ochered.push(startovayaVershina);//добавление элемента в очередь
	while(!ochered.empty()){
		int otkudaIdem = ochered.front();//взятие первого элемента в очереди
		ochered.pop();//удаление взятого элемента
		for(int k = H[otkudaIdem]; k != -1; k = L[k]){
			int kudaIdem = J[k];
			if (distance[otkudaIdem] + 1 < distance[kudaIdem]){//проверка, посещали ли мы эту вершину, меняя её размер с бесконечного на адекватный
				ochered.push(kudaIdem);
				distance[kudaIdem] = distance[otkudaIdem] + 1;
				parent[kudaIdem] = otkudaIdem;
			}
		}
	}
	for(int i = 0; i < parent.size(); i += 1)
		if (parent[i] != -1)//Если мы посещали i-ую вершину
			cout << "родитель " << i << "-ой вершины - " << parent[i] << endl;
}
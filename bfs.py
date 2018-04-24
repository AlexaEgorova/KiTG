from collections import deque

m = int(input("Введите количество рёбер\n"))
I = [0] * m
J = [0] * m
for i in range(m):
	I[i], J[i] = map(int, input().split())
H = [-1] * (max(max(I), max(J)) + 1)
L = [0] * m
for k in range(m):
	L[k] = H[I[k]]
	H[I[k]] = k
p = [-1] * len(H)
d = [100] * len(H)
q = deque()
s = int(input("Введите стартовую вершину\n"))
p[s] = s
d[s] = 0
q.append(s)
while q:
	v = q.popleft()
	k = H[v]
	while k != -1:
		to = J[k]
		if d[v] + 1 < d[to]:
			d[to] = d[v] + 1
			p[to] = v
			q.append(to)
		k = L[k]
for i in range(len(p)):
	if p[i] != -1:
		print("родитель", i, "-ой вершины -", p[i])
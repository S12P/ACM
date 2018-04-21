#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <climits>
using namespace std;


int mat[105][105];
int resultat, resint, s, t;
vector<vector<int>> adj;
vector<int> p;

int m, w, V;

void calcul(int v, int ma) {
	if (v == s) {
		resint = ma;
		return;
	} else if (p[v] != -1) {
		calcul(p[v], min(ma, mat[p[v]][v]));
		mat[p[v]][v] -= resint;
		mat[v][p[v]] += resint;
	}
}

void EdmondKarps() {
	resultat = 0;
	while (true) {
		resint = 0;
		bitset<105> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(105, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) adj[u].size(); i++) {
				int v = adj[u][i];
				if (mat[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		calcul(t, INT_MAX);
		if (resint == 0)
			break;
		resultat += resint;
	}
}

int main() {
	int id1, id2, c, u1, u2, v1, v2;
	while (cin >> m >> w && m || w){
		V = m * 2 - 2;
		memset(mat, 0, 105);
		adj.assign(V, vector<int>());
		s = 0;
		t = V - 1;
		for (int i = 0; i < m - 2; i++){
			int id, c, u, v;
			cin >> id >> c;
			id--;
			u = id + id - 1;
			v = u + 1;
			mat[u][v] = c;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 0; i < w; i++){
			cin >> id1 >> id2 >> c;
			id1--;
			id2--;
			if (id1 != 0 && id1 != m - 1){
				u1 = id1 + id1 - 1;
				v1 = u1 + 1;
			}
			else {
				if (id1 == 0){
					u1 = v1 = 0;
				}
				else{
					u1 = v1 = V - 1;
				}
			}
			if (id2 != 0 && id2 != m - 1){
				u2 = id2 + id2 - 1;
				v2 = u2 + 1;
			}
			else{
				if (id2 == 0){
					u2 = v2 = id2;
				}
				else{
					u2 = v2 = V - 1;
				}
			}
			mat[v1][u2] = c;
			mat[v2][u1] = c;
			adj[v1].push_back(u2);
			adj[u2].push_back(v1);
			adj[v2].push_back(u1);
			adj[u1].push_back(v2);
		}

		EdmondKarps();
		cout << resultat << endl;
	}

	return 0;
}

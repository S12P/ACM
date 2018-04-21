#include <cstdio>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int mat[38][38], resultat, resint, s, t;
vector<vi> adj;
vi p;

int total, n;
char app, pc;
bool fin = false;

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

void entre() {
	total = 0;
	memset(mat, 0, sizeof mat);
	adj.assign(38, vi());
	s = 0;
	t = 38 - 1;
	for (int i = 27; i < 38 - 1; i++) {
		mat[i][t] = 1;
		adj[i].push_back(t);
		adj[t].push_back(i);
	}
	while (true) {
		if (scanf("%c", &app) == EOF) {
			fin = true;
			break;
		}
		if (app == '\n')
			break;
		cin >> n;
		mat[0][app - 'A' + 1] = n;
		adj[0].push_back(app - 'A' + 1);
		adj[app - 'A' + 1].push_back(0);
		total += n;
		while (true) {
			scanf("%c", &pc);
			if (pc == ';') {
				scanf("%c", &pc);
				break;
			}
			mat[app - 'A' + 1][pc - '0' + 27] = 1;
			adj[app - 'A' + 1].push_back(pc - '0' + 27);
			adj[pc - '0' + 27].push_back(app - 'A' + 1);
		}
	}
}

void EdmondKarps() {
	resultat = 0;
	while (1) {
		resint = 0;
		bitset<38> visite;
		visite.set(s);
		queue<int> q;
		q.push(s);
		p.assign(38, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) adj[u].size(); i++) {
				int v = adj[u][i];
				if (mat[u][v] > 0 && !visite.test(v)) {
					visite.set(v);
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

void reponse() {
	if (total != resultat) {
		cout << "!\n";
	}
	else{
		for (int i = 27; i < 37; i++) {
			bool boo = false;
			for (int j = 1; j <= 26; j++) {
				if (mat[i][j]) {
					printf("%c", j + 'A' - 1);
					boo = true;
					break;
				}
			}
			if (!boo)
				cout << "_";
		}
		cout << "\n";
	}
}

int main() {
	while (true) {
		entre();
		EdmondKarps();
		reponse();
		if (fin)
			break;
	}
	return 0;
}

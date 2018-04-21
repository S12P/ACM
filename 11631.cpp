#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
// j'applique l'algorithme de kruskal
using namespace std;

typedef tuple<int, int, int> arete;

int parent[200001];
arete a;
vector<arete> adj;


int parent_(int i){
	if (parent[i] != i){
     return parent_(parent[i]);
	}
	else{
		return i;
	}
}

void c_parent(int i, int j){
	parent[parent_(j)] = parent[i];
}

bool c_bool(arete a, arete b){
	if (get<0>(a) > get<0>(b)){
		return true;
	}
	return false;
}

int main(){
	int n, m, i, j, x, y, z;
	long taille_tot;
	long taille_min;
	while (true) {
		cin >> n >>m;
		if (n == 0 && m == 0)
			break;
		taille_tot = 0;
		taille_min = 0;
		adj.clear();
		for (i = 0; i < n; i++)
			parent[i] = i;
		for (i=0;i<m;i++) {
			cin >> x >> y >> z;
			taille_tot += z;
			adj.push_back(make_tuple(z, x, y));
		}
		sort(adj.begin(), adj.end(), c_bool);
		while(--n) {
			a = adj.back();
			adj.pop_back();
			while(parent_(get<1>(a)) == parent_(get<2>(a))) {
				a = adj.back();
				adj.pop_back();
			}
			taille_min+=get<0>(a);
			c_parent(get<1>(a), get<2>(a));
		}
		cout << taille_tot-taille_min << endl;
	}
}

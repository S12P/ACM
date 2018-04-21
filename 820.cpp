#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>


using namespace std;

int mat[101][101];
vector<int> p;
int n,resultat,resint,depart,destination,ligne;
//on cherche un chemin de depart à arrive on enleve a chaque arete du chemin le poids min
// et on fait cela jusqu'a ne plus avoir de chemin

void calcul(int v, int ma){//ma : min arrete
	if (v==depart){
		resint=ma;
		return;
	}
	else if(p[v]!=-1){
		calcul(p[v],min(ma, mat[p[v]][v]));
		mat[p[v]][v]-=resint;
		mat[v][p[v]]+=resint;
	}
}

void algo(){
	int v;
	resultat = 0;
	while(true) {
		resint = 0;
		vector<int> vint(n, -1);
		vint[depart] = 0;
		queue<int> q;
		q.push(depart);
		p.assign(n, -1);
		while(!q.empty()) {
				int u = q.front();
				q.pop();
				if(u == destination) break;
				for(v = 0; v < n; v++) {
						if(mat[u][v] > 0 && vint[v] == -1) {
								vint[v] = vint[u] + 1;
								q.push(v);
								p[v] = u;
						}
				}
		}
		calcul(destination, INT_MAX);
		if(resint == 0) break;
		resultat += resint;
	}
}

int main(){
  int s,t,c,i,j,compteur=1,flot=0;
	while (true){
  	cin >> n;
		if (n==0) break;
		cin >> depart >> destination >> ligne;
		depart--;
		destination--;
  	for (i=0;i<101;i++){
    	for (j=0;j<101;j++){
      	mat[i][j]=0;
    	}
  	}
		cout << "Network " << compteur << endl;
		compteur++;
  	while (ligne--){
    	cin >> s >> t >> c;
    	mat[s-1][t-1]+=c;
    	mat[t-1][s-1]+=c;
  	}
  algo();
	cout << "The bandwidth is " << resultat << ".\n\n";
	}
}

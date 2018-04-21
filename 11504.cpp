#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;



int visite[110000];
vector<int> adj[110000];
vector<int> adj_int;

void dfs(int u)
{
    visite[u]=true;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(!visite[v]){
          dfs(v);
        }
    }
    adj_int.push_back(u);
    return;
}

int calcul(int n){
    int compteur=0,i;
    memset(visite,0,110000);
    for(i=1; i<=n; i++){
        if(!visite[i]){
          dfs(i);
        }
	}
    memset(visite,0,110000);
    for(i=adj_int.size()-1; i>=0; i--)
        if(!visite[adj_int[i]]){
            compteur++;
            dfs(adj_int[i]);
        }
 	return compteur;
}



int main(){
  int N,n,m,i,x,y,k,compteur, calc,inter;
  cin >> N;
  for (k=0;k<N;k++){
    cin >> n >> m;
    for (i=0;i<m;i++){
      cin >> x >> y;
      adj[x].push_back(y);
    }
    cout << calcul(n) << endl;
    adj_int.clear();
    for(int i=1; i<=n; i++){
      adj[i].clear();
    }
  }
  return 0;
}

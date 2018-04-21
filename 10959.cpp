#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

//je crée une liste d'adjacense et je fait un bfs

using namespace std;
vector<int> adj[1001];
int d[1001];

void BFS(void){
  int i;
   queue<int> Q;
   Q.push(0);
   d[0] = 0;
   while (!Q.empty()){
      int u = Q.front(); Q.pop();
      for (i=0; i<adj[u].size(); i++){
         int v = adj[u][i];
         if (d[v]==-1){
            d[v] = d[u]+1;
            Q.push(v);
         }
      }
   }
}

int main(){
  int n,i,personne,danse,x,y,j;
  int premier=0;
  cin >> n;
  for (i=0;i<n;i++){
    if (premier!=0){
      cout << "\n";
    }
    if (premier==0){
      premier++;
    }
    cin >> personne >> danse;
    for (j=0;j<personne;j++){
      adj[j].clear();
      d[j]=-1;
    }
    for (j=0;j<danse;j++){
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    BFS();
    for (j=1;j<personne;j++){
      cout << d[j] <<"\n";
    }
  }
}

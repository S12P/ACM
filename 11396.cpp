#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> adj[3001];
int couleur[3001];
int visite[3001];
// tous sauf ceux qui sont bipartis

int parcours(vector<int> adj[3001],int n){
  int i;
  couleur[1]=1;
  visite[1]=1;
  queue<int> toDo;
  toDo.push(1);
  while (!toDo.empty()){
    i = toDo.front();
    toDo.pop();
    for (auto j : adj[i]){
      if (couleur[j]==-1){
        couleur[j]=1-couleur[i];
        visite[j]=1;
        toDo.push(j);
      }
      else if (couleur[j]==couleur[i]){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}


int main(){
  int n, x, y, i;
  while(cin >> n){
    if (n==0){
      break;
    }
    for (i=1;i<=n;i++){
      couleur[i]=-1;
      visite[i]=0;
    }
    while (true){
      cin >> x >> y;
      if (x==0 && y==0){
        break;
      }
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    parcours(adj,n);
    for (i=0;i<=n;i++){
      //couleur[i]=-1;
      adj[i].clear();
    }
  }
}

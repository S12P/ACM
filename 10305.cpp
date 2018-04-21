#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector < vector <int> > adj(101);
vector <int> couleur(101);
vector <int> file;

// Je crée une liste d'adjacense et j'applique l'algorithme d'algo2 de tri topologique

void tri_topologique(int s){
  couleur[s]=0;
  for (auto v : adj[s]){
    if (v&&couleur[v]==1){
      tri_topologique(v);
    }
  }
  couleur[s]=-1;
  file.push_back(s);
}


int main(){
  int n,m,i,x,y,k;
  while (cin >> n >> m){
    adj[0]={0};
    file={0};
    for (k=1;k<=n;k++){
      adj[0].push_back(k);
      adj[k]={0};
      couleur[k]=1;
    }
    for (k=1;k<=m;k++){
      cin >> x >> y;
      if (x==0 && y==0){
        break;
      }
      adj[x].push_back(y);
    }
    if (m==0){
      for (k=1;k<=n;k++){
        cout << k << " ";
      }
      cout << endl;
    }
    else{
      tri_topologique(0);
      for (i=n;i>0;i--){
        cout << file[i] << " ";
      }
      cout << endl;
    }
    file.clear();
  }
}

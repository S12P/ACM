#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int N, compteur;
int visite[10001], minn[10001];
vector<int> adj[10001];
vector< pair<int,int> > crit ;

void dfs(int x, int parent)
{
    compteur++;
    minn[x]=compteur;
    visite[x]=compteur;
    for (int i = 0 ; i < adj[x].size() ; i++){
        int y = adj[x][i];
        if (y == parent){
          continue;
        }
        if (visite[y] == 0){
            dfs(y, x);
            minn[x] = min(minn[x], minn[y]);
            if (minn[y] == visite[y]){
                crit.push_back(make_pair(min(x,y),max(x,y)));
            }
        }
        else{
            minn[x] = min(minn[x], visite[y]);
        }
    }
}


int main(){
    while( cin >> N ){
     int i, x, y, M;
     for( int i = 0 ; i < N ; i++ ){
          visite[i] = 0 ;
          adj[i].clear();
     }
     compteur = 0 ;
     crit.clear();
     for (i = 0; i < N; i++) {
        scanf("%d (%d)",&x,&M);//parentheses...
        for( int j = 0 ; j < M ; j++ ){
             cin >> y ;
             adj[x].push_back(y);
        }
     }
     for (x = 0; x < N; x++)
         if (visite[x] == 0) dfs(x, -1);
     cout << crit.size() << " crit links" << "\n";
     sort(crit.begin(),crit.end());
     for( int i = 0 ; i < crit.size() ; i++ )
          cout << crit[i].first << " - " << crit[i].second << "\n";
      cout << "\n";
     }
}

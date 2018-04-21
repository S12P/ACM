#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int adj[110][110];
int visite[110];
string sortie=": average length between pages = ";

int main(){
  int i,j,k,x,y,n=1,cas=1;
  float somme=0, divise=0;
  while (true){
    memset(visite,0,sizeof(visite));
    memset(adj, 1, sizeof adj);
    somme=0;
    divise=0;
    cin >> x >> y;
    n=1;
    if (x==0 && y==0){
      break;
    }
    adj[x][y]=1;
    visite[x]=1;
    visite[y]=1;
    while (true){
      cin >> x >> y;
      if (x==0 && y==0){
        break;
      }
      adj[x][y]=1;
      visite[x]=1;
      visite[y]=1;
    }
    for (i=0;i<110;i++){
      for (j=0;j<110;j++){
        for (k=0;k<110;k++){
          adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);
        }
      }
    }
    for (i=0;i<105;i++){
      for (j=0;j<105;j++){
        if (visite[j] && visite[i] && i!=j){
          somme+=adj[i][j];
          divise++;
        }
      }
    }
    printf("Case %d: average length between pages = %.3f clicks\n",cas,somme/divise);
    cas++;
  }
}

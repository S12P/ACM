#include <iostream>
using namespace std;


int n;
struct point {
	int x,y;
	void ppoint() { scanf("%d%d",&x,&y); }
} pol[1010],test;

bool Scr(int a,int b) {
	return ((pol[a].y <= test.y && test.y <= pol[b].y) || (pol[b].y <= test.y && test.y <= pol[a].y));
}

int main() {
  int compteur=0;
	while(cin >> n && n) {
		for(int i=0;i<n;i++){
			pol[i].ppoint();
    }
		pol[n] = pol[0];
		test.ppoint();
    compteur = 0;
		for(int i=1;i<=n;i++)
			if(pol[i].x == pol[i-1].x && pol[i].x < test.x && Scr(i,i-1)){
				compteur++;
      }
		if(compteur & 1){
      cout << "T" << endl;
    }
		else{
      cout << "F" << endl;
    }
	}
}

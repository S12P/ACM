#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>


int somme(int x, int y, int t[]){
  if(x==0){
    int res=0;
    while(y>=0){
      res+=t[y];
      y=(y&(y+1))-1;
    }
    return res;
  }
  else
    return somme(0,y,t)-somme(0,x-1,t);
}

void incremente(int x, int inc, int t[], int taille) {
  while(x<taille){
    t[x]+=inc;
    x=x|(x+1);
  }
}



int main(){
	int N, tableau[200002],tableau_f[200002], aux, x, y;
	int compteur=1;
	std::string aux_s;
	while (true){
		int i=0, j=0;
		for (int i=0; i<200002; i++){
			tableau[i]=0;
		}
		std::cin >> N;
		if (!N){
            break;
		}
		if (compteur>1){
			std::cout << "\n";
		}
		std::cout << "Case " << compteur << ":\n";
		for (i=0; i<N;i++){
			std::cin >> aux;
			tableau[i+1]=aux;
			tableau_f[i+1]=0;
		}
		for (i=1; i<=N;i++){
			for (j= (i & (i+1)); j<=i;j++){
				tableau_f[i]+=tableau[j];
		}
		}
		while (true){
			std::cin >> aux_s;
			if (aux_s=="END"){
				break;
			}
			std::cin >> x;
			std::cin >> y;
			if (aux_s=="S"){
				incremente(x,y-tableau[x],tableau_f,N);
				tableau[x]=y;
			}
			else{
				int s=somme(x,y,tableau_f);
				std::cout << s << "\n";
			}
		}
		compteur+=1;
	}
}

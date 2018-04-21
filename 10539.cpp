#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long int> presque_premier;
bool nb_premier[1000001];

void eratosthene(void){
	long long int x,nb,ii;
	long long int i,j;
	for (i=0;i<1000001;i++){
		nb_premier[i]=true;
	}
	nb_premier[0]=false;
	nb_premier[1]=false;
	for (i=4;i<1000001;i+=2){
		nb_premier[i]=false;
	}
	for (i=3;i<1000001;i+=2){
		if (nb_premier[i]){
			ii=i*2;
			for (j=i*i;j<1000001;j+=ii){
				nb_premier[j]=false;
			}
		}
	}
}

int calcul(long long int borne_inf,long long int borne_sup,vector<long long int> presque_premier){
	long long int i, compteur=0;
	if (borne_sup-borne_inf==1000000000000-1){
		return presque_premier.size();
			}
	else{
		for (i=0;i<=1000000;i++){
			if (presque_premier[i]>=borne_inf && presque_premier[i]<=borne_sup){
				compteur++;
			}
			else if (presque_premier[i]>borne_sup){
				return compteur;
			}
		}
	}
	return 0;
}

int main(){
	long long int n, i,j;
	long long int borne_inf,borne_sup;
	eratosthene();
	for (i=2;i<=1000000;i++){
		if (nb_premier[i]){
			for(j=i*i;j<=1000000000000;j*=i){
				presque_premier.push_back(j);
			}
		}
	}
	sort(presque_premier.begin(),presque_premier.end());
	while(cin >> n){
		for (i=0;i<n;i++){
			cin >> borne_inf >> borne_sup;
			cout << calcul(borne_inf,borne_sup,presque_premier) << "\n";
		}
	}
}

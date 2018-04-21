#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>

long long intm=INT_MAX;
long long int mat[101][101];
int ta[101];
int m[101][101];
bool visite[101];

using namespace std;

bool end(int a, int b){
	if (a == b){
		return true;
	}
	visite[b] = true;
	for (int i = 1; i <= mat[b][0]; i++){
	    if (mat[b][i] && !visite[mat[b][i]] && end(a, mat[b][i])){
 	       return true;
		}
	}
	return false;
}

bool bellman_ford(int n){
	int x_int,l,j;
	bool cycle=false;
	m[1][0]=100;
    for (int k = 1; k <= n-1; k++){
	    for (int i = 1; i <= n; i++){
			x_int = m[i][k - 1];
			l = mat[i][0];
			for (j = 1; j <= l; j++){
 	        	if (m[mat[i][j]][k - 1] > 0){
					x_int = max(x_int, m[mat[i][j]][k - 1] + ta[i]);
				}
			}
			m[i][k] = x_int;
		}
	}
	for (int i = 1; i <= n; i++){
		x_int = m[i][n-1];       
		l = mat[i][0];
		for (j = 1; j <= l; j++){
			if (m[mat[i][j]][n-1] > 0){
				cycle |= m[mat[i][j]][n-1]+ta[i]> x_int && end(i, n);
			}
		}
	}
	return cycle;
}


int main() {
    int n, e, l,i,j,k;
    while (cin >> n){
		if (n==-1) break;
		for (i=1;i<=n;i++){
			m[i][0]=-intm;
			mat[i][0]=0;
			visite[i]=false;
		}
		for (i=1;i<=n;i++){
			cin >> ta[i] >> l;
			for (j=0;j<l;j++){
				cin >> k;
				mat[k][++mat[k][0]]=i;
			}
		}
        if (bellman_ford(n) || m[n][n-1] > 0){
			cout << "winnable" << endl;
		}
		else{
			cout << "hopeless" << endl;
		}
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

int p[501], r[501];

struct E {
    int x, y;
    int v;
};
E D[250000];

int comparaison(const void *i, const void *j) {
    E *x, *y;
    x=(E *)i;
	y=(E *)j;
    return x->v - y->v;
}

void init(int n) {
    int i;
    for(i=0; i<= n; i++)
        p[i]=i, r[i]=1;
}

int cherche(int x) {
	if (p[x]==x){
		return x;
	}
	else{
		return (p[x]=cherche(p[x]));
	}
}

int union_(int x, int y) {
    x = cherche(x);
	y = cherche(y);
    if(x != y) {
        if(r[x] > r[y])
            p[y] = x, r[x] += r[y];
        else
            p[x] = y, r[y] += r[x];
        return 1;
    }
    return 0;
}
int main() {
    int N, S, P,m=0,compteur=0,i,j;
    int x[501], y[501];
    cin >> N;
    while(N--) {
        cin >> S >> P;
		m = 0;
        for(i = 0; i < P; i++) {
            scanf("%d %d", &x[i], &y[i]);
            for(j = i-1; j >= 0; j--) {
                D[m].x = i, D[m].y = j;
                D[m].v = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                m++;
            }
        }
        qsort(D, m, sizeof(E), comparaison);
        init(P);
        compteur = 0;
        for(i = 0; i < m; i++) {
            compteur += union_(D[i].x, D[i].y);
            if(compteur == P-S) {
                cout << fixed  << setprecision(2) << sqrt(D[i].v) << endl;
                break;
            }
        }
    }
    return 0;
}

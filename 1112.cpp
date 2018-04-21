#include <string.h>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

typedef pair < int, int > pii;

vector <pii> g[110];
int N, E, T, M;
int dist[110];


int dijkstra(int src ){
	int xd, xa, t, cout;
    priority_queue < pii > pq;
    for( int i = 1; i <= N; i++ ){
		dist[i] = INT_MAX;
	}
    pq.push( pii(src, 0));
    dist[src] =0;
    while( !pq.empty() ){
        xd = pq.top().first;
        cout = pq.top().second;
        pq.pop();
        if( dist[xd] == cout && dist[xd] <= T){
        	for( int i = 0; i < (int) g[xd].size(); i++ ){
            	xa = g[xd][i].first;
            	t = g[xd][i].second;
            	if( dist[xd] + t < dist[xa]){
            	    dist[xa] = dist[xd] + t;
            	    pq.push(pii(xa, dist[xa]));
            	}
        	}
		}
    }
    int resultat = 0;
    for( int i = 1; i <= N; i++ )
        if( dist[i] <= T )
            resultat += 1;
    return resultat;
}
int main(){
    int test, xd, xa, t, nb_de_test;
    cin >> nb_de_test;
    while(nb_de_test--){
        cin >> N >> E >> T >> M;
        for( int i = 0; i < M; i++ ){
            cin >> xd >> xa >> t;  // xa : x arrive et xd : x depart
            g[xa].push_back( pii(xd, t) );
        }
    cout << dijkstra(E) << endl;
    if (nb_de_test){
		cout << "\n";
	}
	for( int i = 1; i <= N; i++ ){
		g[i].clear();
	}
    }

	return 0;
}

#include <iostream>
#include <climits>
#include <math.h>
#include <vector>
// algorithme de Jarvis

using namespace std;

struct point{
  int x,y;
};
vector<point> v;
int m[100][100];

double aire(vector<point> p) {
  int n = p.size();
  double s = 0;
  for (int i = 1; i < n; i++) {
    s += ((p[i-1].x * p[i].y) - (p[i].x * p[i-1].y))/2;
  }
  return s;
}

int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int formule(vector<point> v){
  int i;
  double compteur=0;
  for (i=1;i<=v.size();i++){
    compteur+=(v[i-1].x*v[i].y)-(v[i].x*v[i-1].y);
  }
  return compteur/2;
}


void javis(vector<point> points){
  int n=points.size();
    if (n < 3)
        return;
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    do
    {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        next[p] = q;
        p = q;
    }
    while (p != l);
    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1){
            cout << points[i].x << " " << points[i].y << endl;
            v.push_back(points[i]);
        }
    }
    cout << formule(v) << endl;
}


int main(){
  int N,i,m1,m2;
  vector<point> ep; //ensemble point
  while (true){
    cin >> N;
    if (N==-1){
      break;
    }
    else{
      for (i=0;i<N;i++){
        point p;
        cin >> p.x >> p.y;
        ep.push_back(p);
      }
      javis(ep);
    }
  }
  while (cin >> m1 >> m2){

  }
}

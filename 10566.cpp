#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double x,y,c;

double calcul(double z){
  double x1=sqrt(x*x-z*z);
  double x2=sqrt(y*y-z*z);
  return (1/(1/x1+1/x2));
}

int main(){
  double i,j,m,r,l,M;
  while(cin >> x >> y >> c){
    l=0;
    if (x<=y){
      r=x;
    }
    else{
      r=y;
    }
    while(r-l>0.000001){
      m=(l+r)/2;
      if (calcul(m)>c){
        l=m;
      }
      else{
        r=m;
      }
    }
    cout << setprecision(3) << fixed << m << endl;
  }
}

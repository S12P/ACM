#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long int> v;
int pgcd(long long int a,long long int b){
  int in;
  if (a>=b){
    while (a%b!=0){
      in=a;
      a=b;
      b=in%a;
    }
    return b;
  }
  else{
    return pgcd(b,a);
  }
}

int calcul(vector<long long int> v,long long int nb_int){
  long long int i,aux=pgcd(v[0],v[1]);
  if (v.size()>2){
    for (i=2;i<nb_int;i++){
      aux=pgcd(aux,v[i]);
    }
  }
  return aux;
}

int main(){
  string s="impossible";
  long long int n,n_int,i,j,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,max=0,pgcd_;
  bool zero=false;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> n_int;
    for (j=0;j<n_int;j++){
      cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 >> x8 >> x9 >> x10;
      if (max<x10){
        max=x10;
      }
      if (x1+x2+x3+x4+x5+x6+x7+x8+x9-x10==0){
        zero=true;
      }
      v.push_back(abs(x1+x2+x3+x4+x5+x6+x7+x8+x9-x10));
    }
    if (zero){
      cout << s << "\n";
      zero=false;
      v.clear();
      max=0;
    }
    else{
      pgcd_=calcul(v,n_int);
      if (pgcd_<=max || pgcd_==1){
        cout << s << "\n";
      }
      else{
        cout << pgcd_ << "\n";
      }
      v.clear();
      max=0;
    }
  }
}

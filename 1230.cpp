#include <iostream>
#include <vector>
using namespace std;

int calcul(int x, int y,int z){
  if (y==1){
    return(x%z);
  }
  else if (y%2==0){
    return(calcul(x*x%z,y/2,z)%z);
  }
  else{
    return(x*calcul(x*x%z,(y-1)/2,z)%z);
  }
}

int main(){
  int n, x, y, z, i;
  cin >> n;
  for (i=0; i<n;i++){
    cin >> x >> y >> z;
    cout << calcul(x,y,z) << "\n";
  }
}

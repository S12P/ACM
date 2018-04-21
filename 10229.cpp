#include <iostream>
using namespace std;

void mult_matrice(unsigned long long int F[2][2], unsigned long long int M[2][2], unsigned long long int modulo)
{
  unsigned long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  unsigned long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  unsigned long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  unsigned long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x%modulo;
  F[0][1] = y%modulo;
  F[1][0] = z%modulo;
  F[1][1] = w%modulo;
}

void mult_matrice_global(unsigned long long int F[2][2], int n, unsigned long long int modulo){
  if( n == 0 || n == 1)
      return;
  unsigned long long int M[2][2] = {{1,1},{1,0}};

  mult_matrice_global(F, n/2, modulo);
  mult_matrice(F, F,modulo);

  if (n%2 != 0)
     mult_matrice(F, M, modulo);
}



int fib(int n, int m)
{
  unsigned long long int F[2][2] = {{1,1},{1,0}};
  unsigned long long int modulo=1<<m;
  if (n == 0){
    return 0;
  }
  else{
    mult_matrice_global(F,n-1,modulo);
    }
  return F[0][0]%modulo;
}



int main(){
  int n, m, i;
  while(cin >> n >>m){
    cout << fib(n,m) << "\n";
  }
}

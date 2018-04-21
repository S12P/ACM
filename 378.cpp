#include <iostream>

using namespace std;

 int main(){
   int n, x1, y1, x2, y2, x3, y3, x4, y4, a, b, c, d, e, f, det;
   double k;
   cin >> n;
   cout << "INTERSECTING LINES OUTPUT" << endl;
   while(n--){
     cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
     a = y1 - y2;
     b = x2 - x1;
     c = x2*y1 - x1*y2;
     d = y3 - y4;
     e = x4 - x3;
     f = x4*y3 - x3*y4;
     k = (a*1.0)/(d*1.0);
     if ( k*d == a && k*e == b && k*f == c ){
       cout << "LINE" << endl;
       continue;
     }
     det = a*e - b*d;
     if( !det ){
       cout << "NONE" << endl;
       continue;
     }
     printf("POINT %.2lf %.2lf\n",(double)((c*e-b*f)*1.0/(det*1.0)),(double)((a*f-c*d)*1.0/(det*1.0)));
   }
   cout << "END OF OUTPUT" << endl;
 }

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
 int a,b;
 cout << "Input a, b: ";
 cin >> a >> b;
 
 a=abs(a);
 b=abs(b);
 int r;
 while(b!=0)
 {
  r = a%b;
  a = b;
  b = r;
 }
 cout << a << endl;

}

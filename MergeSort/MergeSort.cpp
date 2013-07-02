#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>

using namespace std;

/* array pointer: No need to pass by reference*/
void merge(int* array, int p, int q, int r)
{
 cout << endl << p << q << r << endl;
 int* left = new int(q-p+2);
 int* right = new int(r-q+1);
 int i,j,k;
 for(i=0;i<=q-p;i++)  {left[i]=array[p+i]; cout << left[i] ;} cout << endl;
 for(j=0;j<=r-q-1;j++) {right[j]=array[q+1+j]; cout << right[j];}
 left[i]=numeric_limits<int>::max();
 right[j]=numeric_limits<int>::max();

 cout << endl;
 i=0;j=0;
 for(k=p;k<=r;k++)
 {
  if(left[i]<=right[j]) array[k]=left[i++];
  else array[k]=right[j++];
  cout << array[k];
 } 
 cout << endl;
}

void mergesort(int* array, int p, int r)
{
 int q;
 if(p<r)
 {
  q = floor((p+r)/2);
  mergesort(array, p, q);
  mergesort(array, q+1,r);
  merge(array, p, q, r);
 }
}

int main()
{
  int* a = new int(10);
  for(int i=0;i<10;i++)
  {
   a[i] = rand()%10;
   cout << a[i] ;
  }
  cout << endl;

  mergesort(a,0,9);
}

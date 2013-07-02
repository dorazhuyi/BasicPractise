#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n = 10;
    int* a = new int [n];
 
    int i, j, k;
    int key;
 
    for(i = 0; i < n; i++)
    { 
	a[i] = rand()%10;
	cout << a[i];
    }
    cout << endl;

    for(i = 1; i < n; i++)
    {
	key = a[i];
	for (j = i - 1; j >= 0; j--)
	{
	    if(key >= a[j])
	    {
		for(k = i; k >= j+1; k--)
		{
		    a[k] = a[k-1];
		}
		a[k] = key;
		break;
	    }
	}
    }

    for(i = 0; i < n; i++)
    { 
	a[i] = rand()%10;
	cout << a[i];
    }
    cout << endl;

    delete[] a;
    return 0; 
}

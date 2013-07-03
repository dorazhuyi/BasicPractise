#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n = 10;
    int* a = new int[n];
 
    int i, j;
    int key;

    /* Create Array */
    for(i = 0; i < 10; i++)
    { 
	a[i] = rand()%10;
	cout << a[i];
    }
    cout << endl;

    /* Sort */
    for(i = 1; i < n; i++)
    {
	key = a[i];
	j = i - 1;
	while( j >= 0 && key < a[j])
	{
	    a[j+1] = a[j];
	    j--;
	}
	a[j+1] = key; // <- When I put "a[j] = key" here, it occured "double free/corruption" error. WHY???
    }

    /* Display */
    for(i = 0; i < n; i++)
    { 
	cout << a[i];
    }
    cout << endl;

    delete[] a;

    return 0; 
}

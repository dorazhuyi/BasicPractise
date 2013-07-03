#include <iostream>
#include <cstdlib>

using namespace std;

void insert(int* array, int i)
{
    int j = i - 1;
    int key = array[i];
    while( j > -1 && key < array[j] )
    {
	array[j+1] = array[j];
	j--;
    }
    array[j+1] = key;
}

/* Recursive function */
void insertsort(int* array, int n)
{
    if(n>1)
    {
	insertsort(array, n-1);
    }
    insert(array, n);
}

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

    /* call */
    insertsort(a, n);

    /* Display */
    for(i = 0; i < n; i++)
    { 
	cout << a[i];
    }
    cout << endl;

    delete[] a;
    return 0; 
}

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int n = 10;
    int* a = new int[n];
    srand(time(NULL)); // <- this gives the random number generator a seed 
                       // try replacing time(NULL) with an int and run several times to see what happens

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
                      // because the while loop ends with j = -1 , so ..
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

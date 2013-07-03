#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

// try figuring this one out
int main()
{
    int n = 10;
    int* a = new int[n];
    srand(time(NULL));

    /* Create Array */
    for(int i = 0; i < 10; i++)
    {
        a[i] = rand()%10;
        cout << a[i];
    }
    cout << endl;
<<<<<<< HEAD
    // mergeTest
=======
    // merge test 2
>>>>>>> origin/master
    /* Sort */
    for(int i = 1; i < n; i++)
    {
        while(a[j] > a[j-1])
        {
            a[j] ^= a[j-1];
            a[j-1] ^= a[j];
            a[j--] ^= a[j-1];
        }
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

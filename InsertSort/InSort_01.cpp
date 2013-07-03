#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

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

    /* Sort */
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(a[j-1] > a[j] && j > 0)
        {
            a[j] ^= a[j-1];
            a[j-1] ^= a[j];
            a[j--] ^= a[j-1];
        }
    }
    /* Display */
    for(int i = 0; i < n; i++)
    {
       cout << a[i];
    }
    cout << endl;

    delete[] a;

    return 0;
}

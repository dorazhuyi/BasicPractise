#include <iostream>

using namespace std;

Partition(int* array, int l, int r)
{
	int p = array[l];
	int i = l+1;
	for (j=l+1; j<=r; j++)
	{
		if (array[j]<p)
		{
			array[j] ^= array[i];
			array[i] ^= array[j];
			array[j] ^= array[i];
			i++;
		}
	}
	array[l] ^= array[i-1];
	array[i-1] ^= array[i-1];
	array[l] ^= array[i-1];
}

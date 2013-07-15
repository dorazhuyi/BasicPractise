#include <iostream>

using namespace std;

int Partition(int *array, int l, int r)
{
	int p = array[l];
	int i = l+1;
	int j;
	for (j=l+1; j<=r; j++)
	{
		//cout << j << " " << array[j];
		if (array[j]<p) 
		{
			if ( i != j){
				array[j] ^= array[i];
				array[i] ^= array[j];
				array[j] ^= array[i];
			}
			i++;
		}
		
	}
	if(l < i-1){
		array[l] ^= array[i-1];
		array[i-1] ^= array[l];
		array[l] ^= array[i-1];
	}
	return (i-1);
}

void QuickSort(int *array, int l, int r)
{
	if(l >= r) return;
	cout << "Sort: " << l << " " << r << endl;
	int i = Partition(array,l,r);
	QuickSort(array,l,i-1);
	QuickSort(array,i+1,r);
}

int main()
{
	//int *a = new int [8];
	int a[] = {1,5,6,4,2,7,8,9};
	
	/* Display Original array */
	int i = 0;
	while(i<8)
		cout << a[i++] ;
	cout << endl;
	
	/* Test on bit swap
	cout << a[0] << a[1] << endl;
	cout << "Test swap" << endl;
	a[0] ^= a[1]; cout << a[0] << a[1] << endl;
	a[1] ^= a[0]; cout << a[0] << a[1] << endl;
	a[0] ^= a[1]; cout << a[0] << a[1] << endl;*/
	
	QuickSort(&a[0], 0, 7);
	//cout << Partition(&a[0],1,7) << endl;
	
	/* Display Sorted array */
	i = 0;
	while(i<8)
		cout << a[i++] ;
	cout << endl;

	return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

int Partition(int *array, int l, int r)
{
	//cout  << "pivot: " << array[l] << endl;
	
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

int RSelect(int *array, int l, int r, int ithorder, int& cnt)
{
	if(l < r) 
	{
		//cout << "Sort: " << l << " " << r << endl;
		cnt += r-l;
		int j = Partition(array,l,r);
		/* Index j, ith order element */
		// cout << j << ithorder << endl;
		if( j+1 == ithorder ) 
			//return;
			return array[j]; //if RSelect returns the value
		if( j+1 > ithorder ) 
			RSelect(array, l, j-1, ithorder, cnt);
		else if ( j+1 < ithorder ) 
			RSelect(array, j+1, r, ithorder, cnt);
	}
	/* If RSelect returns value: */ 
	else if ( l == r) 
	{
		return array[l];
	}
}

int main()
{
	/* Simple check*/ 
	//int a[] = {4,6,7,3,1};
	int a[] = {1,5,6,2,4};
	int alength = 5;
	int i;
	
	/* Read input integers 
	int a[10000];
	ifstream IntFile;
	IntFile.open("QuickSort.txt");
	
	
	int alength = 10000;
	int i = 0;
	if(IntFile.is_open())
	{
		while(!IntFile.eof())
			IntFile >> a[i++] ;
	} */ 
	
	
	
	/* Display array */
	i = 0;
	while(i<5)
		cout << a[i++];
	cout << endl;
	
	int c = 0;
	int ithorder =4; 
	RSelect(&a[0], 0, alength-1, ithorder, c);
	
	/* Display array */
	i = 0;
	while(i<5)
		cout << a[i++];
	cout << endl;
	
	cout << "# of comparisons: " << c << endl;
	cout <<  ithorder << "th order statics: " << a[ithorder-1] << endl;

	return 0;
}

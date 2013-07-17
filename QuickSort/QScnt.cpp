#include <iostream>
#include <fstream>

using namespace std;

/* Use 1st element as pivot */
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

void QuickSort(int *array, int l, int r, int & cnt)
{
	if(l < r) 
	{
		//cout << "Sort: " << l << " " << r << endl;
		cnt += r-l;
		int i = Partition(array,l,r);
		QuickSort(array,l,i-1,cnt);
		QuickSort(array,i+1,r,cnt);
	}
}

int main()
{
	
	int a[10000];
	
	/* Read input integers */
	ifstream IntFile;
	IntFile.open("QuickSort.txt");
	
	
	int alength = 10000;
	int i = 0;
	if(IntFile.is_open())
	{
		while(!IntFile.eof())
			IntFile >> a[i++] ;
	}
	
	/* Display array */
	i = 0;
	while(i<10)
		cout << a[i++] << endl;
	
	int c = 0;
	QuickSort(&a[0], 0, alength-1, c);
	
	
	
	cout << "# of comparisons: " << c << endl;

	return 0;
}

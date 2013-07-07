#include <iostream>
#include <limits>
#include <cmath>
#include <fstream>

using namespace std;

void merge_and_countSplitInv(int* array, int p, int q, int r, unsigned& cnt)
{
	//cout << p << q << r ;
	
	int* Left = new int [q - p + 2];
	int* Right = new int [r - q + 1];
	
	int i, j, k;
	for ( i = 0; i < q-p+1; i++ )
		Left[i] = array[p+i];
		
	for ( j = 0; j < r-q; j++ )
		Right[j] = array[q+1+j];
		
	Left[i] = numeric_limits<int>::max();
	Right[j] = numeric_limits<int>::max();
	
	i = 0;
	j = 0;
	k = p;
	while( k <= r )
	{
		if ( Left[i] <= Right[j] )
		{
			array[k++] = Left[i++];
		} 
		else
		{
			array[k++] = Right[j++];
			if ( i != q-p+1 )
				cnt += q-p - i + 1;
			//cout << " " << cnt << endl;
		}
	}
}

void findinversion(int* array, int p, int r, unsigned& cnt)
{
	if(p < r){
		int q = floor( (p + r) / 2 );
		findinversion(array, p, q, cnt);
		findinversion(array, q+1, r, cnt);
		merge_and_countSplitInv(array, p, q, r, cnt);
	}
}

int main()
{
    /* simply try */
	int a[] = { 1, 5, 8, 2, 6, 9 };
	
	for (int i=0; i<6; i++)
	{
		cout << a[i];
	}
	cout << endl; 
	
	/*
	ifstream integerFile;
	integerFile.open("IntegerArray.txt");
	
	int a[100000];
	
	int i = 0;
	if (integerFile.is_open())
	{
		while(!integerFile.eof())
		{
			integerFile >> a[i++]; 
		}
	}*/
	
	/* incase # of inversions is huge */
	unsigned c = 0;
	
	findinversion(a, 0, (100000-1), c);
	
	/* display sorted array
	for (int i=0; i<6; i++)
	{
		cout << a[i];
	}
	cout << endl;*/
	
	cout << "# of Inversions: " << c << endl;
}



#include <iostream>
#include <limits>
#include <cmath>
#include <fstream>

using namespace std;

void merge_and_countSplitInv(int* array, int p, int q, int r, unsigned& cnt)
{
	cout << "p:" << p << " q:" << q << "r:" << r << endl;

    int* left = new int[q-p+1];
    int* right = new int[r-q];

	int i, j, k;

	for ( i = 0; i < q-p+1; i++ )
		left[i] = array[p+i];

	for ( j = 0; j < r-q; j++ )
		right[j] = array[q+1+j];

	// left[i] = numeric_limits<int>::max();
	// right[j] = numeric_limits<int>::max();

	i = 0;
	j = 0;
	k = p;
	while( k <= r )
	{
		if ( i < q-p+1 && j < r-q)
		{
		    if(left[i] <= right[j]){
                array[k++] = left[i++];
		    }else{
		        // I THINK I BROKE THE COUNT CODE...
		        // I'M NOT SO SURE WHAT IS IT FOR
                array[k++] = right[j++];
                if ( i != q-p+1 )
                    cnt += q - p - i + 1;
		    }
		}
		else if(i == q-p+1){
            array[k++] = right[j++];
		}else{
            array[k++] = left[i++];
		}
	}

	// 1. delete the stuff you newed ..
	delete[] left;
	delete[] right;
}

void findinversion(int* array, int p, int r, unsigned& cnt)
{
	if(p < r){
		int q = floor((p + r) / 2 );
		findinversion(array, p, q, cnt);
		findinversion(array, q+1, r, cnt);
		merge_and_countSplitInv(array, p, q, r, cnt);
	}
}

int main()
{
    // DO A DIFF ON THE CODE

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

	findinversion(a, 0, 5, c);

	// display sorted array
	for (int i=0; i<6; i++)
	{
		cout << a[i];
	}
	cout << endl;

	cout << "# of Inversions: " << c << endl;
}



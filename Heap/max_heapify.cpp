#include <iostream>

using namespace std;

void max_heapify(int* array, int i, int heap_size)
{
	int l = 2*(i+1)-1; // left = 2j; j = index+1;
	int r = 2*(i+1); // right = 2j + 1; j = index+1;
	int largest= -1;
	//cout << l << r << largest << endl;
	if ( l<heap_size && array[l]>array[i] )
		largest = l;
	else largest = i;
	if ( r<heap_size && array[r]>array[largest])
		largest = r;
	if( largest != i)
	{
		array[i] ^= array[largest];
		array[largest] ^= array[i];
		array[i] ^= array[largest];
		max_heapify(array,largest,heap_size);
	}
}

void build_max_heap(int* array, int heap_size)
{
	for(int i=(heap_size)/2-1;i>=0;i--)
		max_heapify(array,i,heap_size);
}

int main()
{
	int a[] = {23,17,14,6,13,10,1,5,7,12};
	int heap_size = 10;
	for(int i=0;i<heap_size;i++)
		cout << a[i] << " ";
	cout << endl;

	//max_heapify(&a[0],0,heap_size);
	build_max_heap(&a[0],heap_size);
	
	for(int i=0;i<heap_size;i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}

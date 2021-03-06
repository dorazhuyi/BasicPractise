#include <iostream>
#include <vector>

using namespace std;

void max_heapify(vector<int>& array, int i, int heap_size)
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

void build_max_heap(vector<int>& array, int heap_size)
{
	for(int i=heap_size/2-1;i>=0;--i)
		max_heapify(array,i,heap_size);
}

void heapsort(vector<int>& array, int heap_size)
{
	int size_now = heap_size;
	build_max_heap(array,heap_size);
	for(int i = (heap_size-1);i>0;i--)
	{
		array[0] ^= array[i];
		array[i] ^= array[0];
		array[0] ^= array[i];
		size_now--;
		max_heapify(array,0,size_now);
	}
	
}

void display(vector<int>& array, int heap_size)
{
	vector<int>::iterator it;
	for(it = array.begin();it != array.end(); ++it)
		cout << *it << " ";
	cout << endl;
}
	

int main()
{
	int a[] = {23,17,14,6,13,10,1,5,7,12};
	vector<int> va(a, a+sizeof(a)/sizeof(int)); 
	int heap_size = va.size();
	display(va, heap_size);

	//max_heapify(&a[0], 0, heap_size);

	build_max_heap(va, heap_size);
	cout << "MAX-HEAP: ";
	display(va, heap_size);
	
	heapsort(va, heap_size);
	cout << "Sorted: ";
	display(va, heap_size);

	return 0;
}

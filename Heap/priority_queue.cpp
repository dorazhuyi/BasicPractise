#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>

using namespace std;

void max_heapify(vector<int>& array, int i, int heap_size)
{
	//int heap_size = array.size();
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
		/*array[i] ^= array[largest];
		array[largest] ^= array[i];
		array[i] ^= array[largest];*/
		swap(array[i], array[largest]);
		max_heapify(array,largest, heap_size);
	}
}

void build_max_heap(vector<int>& array)
{
	int heap_size = array.size();
	for(int i=heap_size/2-1;i>=0;--i)
		max_heapify(array, i, heap_size);
}

vector<int> heapsort(vector<int> array)
{
	vector<int> result (array);
	int heap_size = array.size();
	build_max_heap(result);
	for(int i = (heap_size-1);i>0;i--)
	{
		/*array[0] ^= array[i];
		array[i] ^= array[0];
		array[0] ^= array[i];*/
		swap(result[0], result[i]);
		heap_size--;
		max_heapify(result,0,heap_size);
	}
	return result;
}

void display(vector<int>& array)
{
	int heap_size = array.size();
	for(int i=0;i<heap_size;++i)
		cout << array[i] << " ";
	cout << endl;
}

int heap_maximum(vector<int> array)
{
	return array[0];
}

int heap_extract_max(vector<int>& array)
{
	int heap_size = array.size();
	if(heap_size < 1)
		throw invalid_argument("Heap underflow.");
	int max = array[0];
	heap_size--;
	array[0] = array[heap_size];
	array.pop_back();
	max_heapify(array,0, heap_size);
	return max;
}

void heap_increase_key(vector<int>& array, int i, int key)
{
	if(i >= array.size())
		throw invalid_argument("Index exceeds.");	
	if(key < array[i])
		throw invalid_argument("New key is smaller than current key.");
	array[i] = key;
	while( i>0 && array[(i+1)/2-1] < array[i]) // parent: j/2
	{
		swap(array[(i+1)/2-1], array[i]);
		i = (i+1)/2 - 1;
	}
}

void max_heap_insert(vector<int>& array, int key)
{
	array.push_back(numeric_limits<int>::min());
	heap_increase_key(array, array.size()-1, key);
}

int main()
{
	int a[] = {23,17,14,6,13,10,1,5,7,12};
	vector<int> va(a, a+sizeof(a)/sizeof(int)); 
	int heap_size = va.size();
	display(va);

	//max_heapify(&a[0], 0, heap_size);

	build_max_heap(va);
	cout << "MAX-HEAP: ";
	display(va);
	
	heapsort(va);
	cout << "Sorted: ";
	display(va);

	try
   	{
		heap_extract_max(va);
		display(va);
		heap_increase_key(va, 7, 9);
		display(va);
		max_heap_insert(va, 11);
		display(va);
	}
	catch(invalid_argument& e)
	{
		cout << "???" << endl;
		cerr << e.what() << endl; 
	}

	return 0;
}

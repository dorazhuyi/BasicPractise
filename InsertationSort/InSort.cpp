#include <iostream>

using namespace std;

int main ()
{
	int sort [10] = {2,5,6,8,1,4,7,9,0,3};
	int i, j, key;

	cout <<"Original Array: ";
	for (j = 0; j<sizeof(sort)/4;j+=1){
	  cout << sort[j] << " ";
	}
	cout <<" "<<endl;

	cout << "Array size: " << sizeof(sort)/4 << endl;	

	for (j = 1; j<sizeof(sort)/4;j+=1){
	  //cout << j << endl;
	  key = sort[j];
	  i = j-1;
	  while ( i >= 0 && sort[i]>key){
	    sort[i+1] = sort[i];
	    i=i-1;
	  }
	  sort[i+1]=key;
	}

	cout <<"Sorted Array: ";
	for (j = 0; j<sizeof(sort)/4;j+=1){
	  cout << sort[j] << " ";
	}
	cout <<" "<<endl;
	return 0;

}

	

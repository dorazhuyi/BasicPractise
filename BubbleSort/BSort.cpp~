#include <iostream>

using namespace std;

int main()
{
	int sort [10] = {2,5,6,8,1,4,7,9,0,3};
	int i, j, key;

	cout <<"Original Array: ";
	for (j = 0; j<sizeof(sort)/4;j+=1){
	  cout << sort[j] << " ";
	}
	cout <<" "<<endl;

	cout << "Array size: " << sizeof(sort)/4 << endl;	

	for (i=0;i<sizeof(sort)/4;i++){
	  for (j=sizeof(sort)/4;j>i;j--){
	    if(sort[j]<sort[j-1]){
		key=sort[j];
		sort[j]=sort[j-1];
		sort[j-1]=key;
	    }
	  }
	}

	cout <<"Sorted Array: ";
	for (j = 0; j<sizeof(sort)/4;j+=1){
	  cout << sort[j] << " ";
	}
	cout <<" "<<endl;
	return 0;
}


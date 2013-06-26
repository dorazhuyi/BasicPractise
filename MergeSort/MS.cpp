#include <iostream>
#include <cmath>

using namespace std;

void merge(int *sort, int p, int q, int r)
{ 
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    int i,j;

/*  Debugging  
    cout << "n1: " << n1 <<" n2: "<< n2 << endl;
    cout << "p: " << p <<" q: "<< q << " r: " << r << endl;
*/

//    cout << "L: ";
    for(i=0;i<n1;i++){
	L[i]=sort[p+i];
//        cout << L[i] << " ";
    }
//    cout << " " <<endl;
//    cout << "R: ";
    for(j=0;j<n2;j++){
	R[j]=sort[q+1+j];
//        cout << R[j] << " ";
    }
//    cout << " " <<endl;
//    cout << "i now: "<< i <<endl;

//    cout << "j now: "<< j <<endl;
    L[i]=100;
    R[j]=100;

    i=0;
    j=0;
    for (int k=p;k<=r;k++){
	if ( L[i] <= R[j] ){
	  sort[k]=L[i];
	  i++;
	} else {
	  sort[k]=R[j];
	  j++;
	}
    }
}

void mergesort(int *sort, int p, int r)
{
	if (p<r){
	  int q = floor((p+r)/2);
	  mergesort(sort,p,q);
	  mergesort(sort,q+1,r);
	  merge(sort, p, q, r);
	}


}

int main()
{
	int sort [10] = {2,5,6,8,1,4,7,9,0,3};
	int arraylength = sizeof(sort)/4;

	cout <<"Original Array: ";
	for (int j = 0; j<arraylength;j++){
	  cout << sort[j] << " ";
	}
	cout <<" "<<endl;

	cout << "Array size: " << arraylength << endl;	

	mergesort(sort, 0, arraylength-1);

	cout <<"Sorted Array: ";
	for (int j = 0; j<arraylength;j++){
	  cout << sort[j] << " ";
	}
	cout <<" "<<endl;
	return 0;
}

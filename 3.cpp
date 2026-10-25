
#include<iostream>
using namespace std;

int recursiveCount=0;
int mergeCount=0;
int comparisonCount=0;

void merge(int arr[], int left, int mid, int right){
	int n1=mid-left+1;
	int n2=right-mid;

	int *L=new int[n1];
	int *R=new int[n2];

	for(int i=0; i<n1; i++){
		L[i]=arr[left+i];
	}

	for(int j=0; j<n2; j++){
		R[j]=arr[mid+1+j];
	}

	int i=0,j=0,k=left;

	while(i<n1 && j<n2){
		comparisonCount++;

		if(L[i]<=R[j]){
			arr[k++]=L[i++];
		}
		else{
			arr[k++]=R[j++];
		}
	}

	while(i<n1)
		arr[k++]=L[i++];

	while(j<n2)
		arr[k++]=R[j++];

	mergeCount++;

	delete[] L;
	delete[] R;
}

void mergeSort(int arr[], int left, int right){
	recursiveCount++;

	if(left<right){
		int mid=(left+right)/2;

		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);

		merge(arr,left,mid,right);
	}
}

int main(){
	int n;

	cout<<"Enter number of elements: ";
	cin>>n;

	if(n<=0){
		cout<<"Error: Array size must be greater than 0.";
		return 0;
	}

	int *arr=new int[n];

	cout<<"Enter "<<n<<" elements: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	cout<<"\nOriginal Array: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}

	cout<<"\n\n";

	mergeSort(arr,0,n-1);

	cout<<"Sorted Array: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}

	cout<<"\n\nTotal Recursive Calls: "<<recursiveCount;
	cout<<"\nTotal Merge Operations: "<<mergeCount;
	cout<<"\nTotal Comparisons: "<<comparisonCount;

	delete[] arr;

	return 0;
}

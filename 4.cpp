
#include<iostream>
using namespace std;

int partitionCount=0;

int partition(int arr[], int low, int high){
	int pivot=arr[high];

	cout<<"\nPivot: "<<pivot;
	cout<<"\nSubarray Boundaries: "<<low<<" to "<<high<<endl;

	int i=low-1;

	for(int j=low; j<high; j++){
		if(arr[j]<pivot){
			i++;

			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}

	int temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;

	partitionCount++;

	cout<<"After Partition "<<partitionCount<<": ";
	for(int x=0; x<7; x++){
		cout<<arr[x]<<" ";
	}
	cout<<endl;

	return i+1;
}

void quickSort(int arr[], int low, int high){
	if(low<high){
		int pi=partition(arr,low,high);

		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}

int main(){
	int arr[]={40, 20, 70, 10, 60, 30, 50};
	int n=7;

	cout<<"Original Array: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}

	cout<<"\n\n";

	quickSort(arr,0,n-1);

	cout<<"\nSorted Array: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}

	cout<<"\nTotal Partition Operations: "<<partitionCount<<endl;

	return 0;
}

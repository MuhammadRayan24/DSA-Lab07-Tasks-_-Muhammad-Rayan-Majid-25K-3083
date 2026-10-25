#include<iostream>
using namespace std;

int comparisonCount=0;
int partitionCount=0;

int partition(int arr[], int low, int high){
    int pivot=arr[low];

    cout<<"\nPivot: "<<pivot<<endl;

    int i=low+1;
    int j=high;

    while(i<=j){
        while(i<=high && arr[i]<=pivot){
            comparisonCount++;
            i++;
        }

        while(j>low && arr[j]>pivot){
            comparisonCount++;
            j--;
        }

        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;

    partitionCount++;

    cout<<"After Partition "<<partitionCount<<": ";
    for(int x=0; x<7; x++){
        cout<<arr[x]<<" ";
    }
    cout<<endl;

    return j;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int arr[]={55, 25, 75, 15, 65, 35, 45};
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

    cout<<"\nTotal Comparisons: "<<comparisonCount;
    cout<<"\nTotal Partition Operations: "<<partitionCount<<endl;

    return 0;
}
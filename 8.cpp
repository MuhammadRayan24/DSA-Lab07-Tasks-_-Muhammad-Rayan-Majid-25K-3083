
#include<iostream>
using namespace std;

int passCount=0;

void countingSort(int arr[], int n, int exp){
    int output[100];
    int count[10]={0};

    // Frequency Count
    for(int i=0; i<n; i++){
        int digit=(arr[i]/exp)%10;
        count[digit]++;
    }

    // Cumulative Count
    for(int i=1; i<10; i++){
        count[i]=count[i]+count[i-1];
    }

    // Build Output Array
    for(int i=n-1; i>=0; i--){
        int digit=(arr[i]/exp)%10;
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }

    // Copy Output to Original Array
    for(int i=0; i<n; i++){
        arr[i]=output[i];
    }

    passCount++;

    cout<<"\nAfter Pass "<<passCount<<": ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void radixSort(int arr[], int n){
    int max=arr[0];

    for(int i=1; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    for(int exp=1; max/exp>0; exp=exp*10){
        countingSort(arr,n,exp);
    }
}

int main(){
    int arr[]={94, 802, 7, 1234, 56, 321, 405, 18};
    int n=8;

    cout<<"Original Array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n";

    radixSort(arr,n);

    cout<<"\nSorted Array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nTotal Number of Passes: "<<passCount<<endl;

    return 0;
}

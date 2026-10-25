
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

    // Stable Counting Sort
    for(int i=n-1; i>=0; i--){
        int digit=(arr[i]/exp)%10;
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }

    // Copy Output to Original Array
    for(int i=0; i<n; i++){
        arr[i]=output[i];
    }

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
        passCount++;
        countingSort(arr,n,exp);
    }
}

int main(){
    int arr[]={7314, 314, 731, 34, 3147, 147, 47, 7314, 4, 314};
    int n=10;

    cout<<"Original Array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n";

    radixSort(arr,n);

    cout<<"\nSorted Accession Numbers: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nMaximum Number of Digit Passes: "<<passCount<<endl;

    return 0;
}
	
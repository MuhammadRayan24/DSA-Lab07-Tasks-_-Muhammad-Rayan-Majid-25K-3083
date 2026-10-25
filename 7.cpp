
#include<iostream>
using namespace std;

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

    cout<<"\nAfter Pass (exp = "<<exp<<"): ";
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
    int arr[]={91, 8, 1024, 56, 305, 7, 120};
    int n=7;

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

    cout<<endl;

    return 0;
}

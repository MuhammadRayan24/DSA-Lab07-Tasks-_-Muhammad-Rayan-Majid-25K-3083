
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

    cout<<"\nFrequency Count Array: ";
    for(int i=0; i<10; i++){
        cout<<count[i]<<" ";
    }

    // Cumulative Count
    for(int i=1; i<10; i++){
        count[i]=count[i]+count[i-1];
    }

    cout<<"\nCumulative Count Array: ";
    for(int i=0; i<10; i++){
        cout<<count[i]<<" ";
    }

    // Stable Counting Sort
    for(int i=n-1; i>=0; i--){
        int digit=(arr[i]/exp)%10;
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }

    cout<<"\nOutput Array: ";
    for(int i=0; i<n; i++){
        cout<<output[i]<<" ";
    }

    // Copy Output to Original Array
    for(int i=0; i<n; i++){
        arr[i]=output[i];
    }

    cout<<"\nArray After Copying: ";
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

        cout<<"\n========== Pass "<<passCount<<" =========="<<endl;

        countingSort(arr,n,exp);
    }
}

int main(){
    int trackingIDs[]={4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100};
    int n=12;

    cout<<"Original Array: ";
    for(int i=0; i<n; i++){
        cout<<trackingIDs[i]<<" ";
    }

    cout<<"\n";

    radixSort(trackingIDs,n);

    cout<<"\nSorted Tracking IDs: ";
    for(int i=0; i<n; i++){
        cout<<trackingIDs[i]<<" ";
    }

    cout<<"\nTotal Number of Passes: "<<passCount<<endl;

    return 0;
}

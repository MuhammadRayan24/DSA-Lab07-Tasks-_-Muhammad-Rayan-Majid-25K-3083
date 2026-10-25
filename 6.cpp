
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

    cout<<"\nFrequency Count: ";
    for(int i=0; i<10; i++){
        cout<<count[i]<<" ";
    }

    // Cumulative Count
    for(int i=1; i<10; i++){
        count[i]=count[i]+count[i-1];
    }

    cout<<"\nCumulative Count: ";
    for(int i=0; i<10; i++){
        cout<<count[i]<<" ";
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

    cout<<"\nOutput Array: ";
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

    int pass=1;

    for(int exp=1; max/exp>0; exp=exp*10){
        cout<<"\nPass "<<pass++;

        if(exp==1)
            cout<<" (Ones Place)";
        else if(exp==10)
            cout<<" (Tens Place)";
        else
            cout<<" (Hundreds Place)";

        cout<<endl;

        countingSort(arr,n,exp);
    }
}

int main(){
    int arr[]={329, 457, 657, 839, 436, 720, 355};
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

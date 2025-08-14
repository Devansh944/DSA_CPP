#include <iostream>
using namespace std;

void Insertion(int arr[] , int n){

    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        } 
        arr[prev+1]=curr;
    }
    
}


int main() {
    int arr[] = {5,6,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    Insertion(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}                   
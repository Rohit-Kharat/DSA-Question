#include<iostream>

using namespace std;

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubbleSort(int arr[],int n){
    for(int i =0;i<n;i++){
        for(int j = 0;j<n - i - 1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                printArr(arr,n);
            }
        }
    }

};

int main() {
    int arr[] = {5,3,2,1,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,n);

    return 0;
}
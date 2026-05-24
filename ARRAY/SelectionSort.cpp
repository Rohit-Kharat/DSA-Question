#include<iostream>

using namespace std;
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void SelectionSort(int arr[],int n){
    for(int i = 0 ;i< n-1 ;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
        printArr(arr,n);
    }
}
int main() {
    int arr[] = {5,3,2,1,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr,n);
    return 0;
}
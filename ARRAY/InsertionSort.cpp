#include<iostream>

using namespace std;
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]
    }
}
int main() {
    int arr[] = {5,3,2,1,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertSort(arr,n);
    return 0;
}
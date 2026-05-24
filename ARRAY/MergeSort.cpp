#include<iostream>

using namespace std;
void printArr(int arr[],int n){
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void mergeBoth(int arr[],int s,int e,int mid){
    int leftLength = mid - s  + 1;
    int rightLength = e - mid;

    int * leftArr = new int[leftLength];
    int * rightArr = new int[rightLength];

    int index = s;
    //leftArr copy
    for(int i=0;i<leftLength;i++){
        leftArr[i] = arr[index];
        index++;
    }
    //rightArr copy
    index = mid + 1;
    for(int i = 0;i<rightLength;i++){
        rightArr[i] = arr[index];
        index++;
    }

    //merge logic
    int i = 0;
    int j = 0;
    int mainIndexOfArr = s;
    while(i<leftLength && j<rightLength){
        if(leftArr[i] < rightArr[j]){
            arr[mainIndexOfArr] = leftArr[i];
            i++;
            mainIndexOfArr++;
        }else{
            arr[mainIndexOfArr] = rightArr[j];
            j++;
            mainIndexOfArr++;
        }
    }
    while(i < leftLength){
        arr[mainIndexOfArr] = leftArr[i];
            i++;
            mainIndexOfArr++;
    }
    while(i < rightLength){
        arr[mainIndexOfArr] = rightArr[i];
            j++;
            mainIndexOfArr++;
    }
    delete[] leftArr;
    delete[] rightArr;
   
}
void mergeSort(int arr[],int s ,int e){
    if(s >= e){
        return ;
    }
    int mid = s + (e - s) / 2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    mergeBoth(arr,s,e,mid);
}
int main() {
    int arr[] = {5,1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = n - 1;
    mergeSort(arr,s,e);
     printArr(arr,n);
    return 0;
}
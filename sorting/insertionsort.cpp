#include<iostream>
int * insertionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            arr[i]=arr[i]-arr[i+1];
            arr[i+1]=arr[i+1]+arr[i];
            arr[i]=arr[i+1]-arr[i];
            for(int j=i;j>0;j--){
                if(arr[j]<arr[j-1]){
                    arr[j-1]=arr[j-1]-arr[j];
                    arr[j]=arr[j]+arr[j-1];
                    arr[j-1]=arr[j]-arr[j-1];
                }
            }
        }
    }
    return arr;
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<std::endl;
    }
}
int main(){
    int arr[]={25,6,9,1,17,99,38,48};
    int size=sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,size);
    printArray(arr,size);
}
#include<iostream>

int * selectionSort(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(arr[i]>arr[j]){
                arr[i]=arr[i]-arr[j];
                arr[j]=arr[j]+arr[i];
                arr[i]=arr[j]-arr[i];
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
    selectionSort(arr,size);
    printArray(arr,size);
}
#include<iostream>

int * bubblesort(int arr[],int size){
    int i=size;
    while(i!=0){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                arr[j]=arr[j]-arr[j+1];
                arr[j+1]=arr[j+1]+arr[j];
                arr[j]=arr[j+1]-arr[j];
            }
        }
        i--;
    }
    return arr;
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<std::endl;
    }
}
int main(){
    int arr[]={41,2,3,81,9,1,-5,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,size);
    printArray(arr,size);
}
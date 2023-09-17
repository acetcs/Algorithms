#include<iostream>

int heap(int arr[],int len){
    int leftarr[len/2];
    int rightarr[len/2];
    int node=arr[0];

    for(int i=1;i<len;i++){
        
    }
}

void heapify(int arr[],int len){
    int ansArr[len];
    for(int i=len-1;i<=0;i--){
        heap(arr,i);
    }
}

int main(){
    int arr[]={7,5,8,1,2,45,9,4,6};
    int len=sizeof(arr)/sizeof(arr[0]);
    heapify(arr,len);
}
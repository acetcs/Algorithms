#include<iostream>
int binarysearch(int arr[],int size,int key){
    int front=0,rear=size;
    int count=0;
    while(front<=rear){
        int mid=(front + rear)/2;
        if(arr[mid]>key){
            rear=mid -1;
        }
        else if(arr[mid]<key){
            front = mid+1;
        }
        else{
            return mid+1;
        }
    }
}
int main(){
    int arr[]={6,8,10,19,34,56,89,291},key=89;
    int size=sizeof(arr)/sizeof(arr[0]),res=binarysearch(arr,size,key);
    std::cout<<"The position of target key is "<<res<<std::endl;
}
#include<iostream>

void merge(int arr[],int front,int mid,int rear){
    for(int i=0;i<=mid;i++){
        for(int j=mid;j<=rear;j++){
            if(arr[i]>arr[j]){
                for(int k=j+1;k<=rear;k++){
                    if(arr[i]>arr[k]||k==rear){
                        arr[i]=arr[i]-arr[k];
                        arr[k]=arr[k]+arr[i];
                        arr[i]=arr[k]-arr[i];
                        break;
                    }
                    else if(arr[i]<arr[k]){
                        arr[i]=arr[i]-arr[k-1];
                        arr[k-1]=arr[k-1]+arr[i];
                        arr[i]=arr[k-1]-arr[i];
                        break;
                    }
                }
            }
        }
    }
}
void mergeSort(int arr[],int front,int rear){
    if(front<rear){
        int mid= (front+rear)/2;
        mergeSort(arr,front,mid);
        mergeSort(arr,mid+1,rear);
        merge(arr,front,mid,rear);
    }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<std::endl;
    }
}
int main(){
    int arr[]={41,2,3,81,9,1,-5,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    printArray(arr,size);
}
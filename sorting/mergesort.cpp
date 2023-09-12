#include<iostream>

void merge(int arr[],int front,int mid,int rear){
    const int n1=mid-front+1;
    const int n2=rear-mid;
    int leftarr[n1],rightarr[n2];
    if(mid==front){
        mid = mid+1;
    }
    for(int i=0;i<n1;i++){
        leftarr[i]=arr[front+i];
    }
    for(int i=0;i<n2;i++){
        rightarr[i]=arr[mid+i];
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(leftarr[i]<rightarr[j]){
                if(j!=0||n2==1){
                    int temp;
                    leftarr[i]=temp;
                    leftarr[i]=rightarr[j-1];
                    rightarr[j-1]=temp;
                }
                break;
            }
        }
    }
    int k=0,j=0;
    for(int i=front;i<=rear;i++){
        if(k<=n1){
            arr[i]=leftarr[k];
            k++;
        }
        else{
            arr[i]=rightarr[j];
            j++;
        }
        
    }
    // for(int i=front;i<mid;i++){
    //     for(int j=mid;j<=rear;j++){
    //         if(arr[i]>arr[j]){
    //             for(int k=j+1;k<=rear;k++){
    //                 if(arr[i]>arr[k]||k==rear){
    //                     arr[i]=arr[i]-arr[k];
    //                     arr[k]=arr[k]+arr[i];
    //                     arr[i]=arr[k]-arr[i];
    //                     break;
    //                 }
    //                 else if(arr[i]<arr[k]){
    //                     arr[i]=arr[i]-arr[k-1];
    //                     arr[k-1]=arr[k-1]+arr[i];
    //                     arr[i]=arr[k-1]-arr[i];
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }
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
#include<iostream>
//merge function
void merge(int arr[], int front, int mid, int rear) {
    int n1=mid-front+1;
    int n2=rear-mid;

    int leftarr[n1], rightarr[n2];

    for(int i=0;i<n1;i++){
        leftarr[i]=arr[front+i];
        
    }
    for(int i=0;i<n2;i++){
        rightarr[i]=arr[mid+1+i];
        
    }
    int i=0,j=0,k=front;
    while(n1>i&&n2>j){
        if(leftarr[i]>rightarr[j]){
            arr[k]=rightarr[j];
            j++;
        } else{
            arr[k]=leftarr[i];
            i++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=leftarr[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=rightarr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int front, int rear) {
    if (front < rear) {
        int mid = (front + rear) / 2;
        mergeSort(arr, front, mid);
        mergeSort(arr, mid + 1, rear);
        merge(arr, front, mid, rear);
    }
}
//printing the array
void printArray(int arr[], int size) {
    for (int i = 0;i < size;i++) {
        std::cout << arr[i] << std::endl;
    }
}
//main function
int main() {
    int arr[] = { 41,2,3,81,9,1,-5,0 };
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
}
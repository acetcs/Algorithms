#include<iostream>

int linearsearch(int arr[],int key){
/*linearsearch is a bruteforce solution, it will check every and each
element with the key.*/
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={14,15,2,6,89,109,1,7};//given array, 
    //you can also take it from user
    int key = 109;//finding these elements position from the above array
    int res=linearsearch(arr,key);
    std::cout<<"The position of target key is "<<res<<std::endl;
}
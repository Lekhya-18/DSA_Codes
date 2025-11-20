#include<stdio.h>
#include<stdbool.h>
//Quick sort to sort arrayy
void swap(int *a,int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}
int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quick(int arr[],int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quick(arr,low,pi-1);
        quick(arr,pi+1,high);
    }
} 
int binary(int arr[],int low,int high,int key){
    while(low<=high){
        int mid = (high+low)/2;
        if(arr[mid]==key){
           return mid;
        }
        else if(arr[mid]>key){
            high = mid-1;
        }
        else if(arr[mid]<key){
            low = mid+1;
        }
    }
    return -1;
}
int main(){
    int size,key;
    printf("Enter size:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements:",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    quick(arr,0,size-1);
    printf("Enter key:");
    scanf("%d",&key); 
    int res = binary(arr,0,size-1,key);
    if(res != -1)
       printf("ELement Found at %d.",res);
    else
       printf("ELement not found.\n");
    return 0;
}
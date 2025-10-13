//Quick Sort O(nlogn)
#include<stdio.h>
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
int main(){
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements:",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    quick(arr,0,size-1);
    printf("=======Sorted Array=======\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
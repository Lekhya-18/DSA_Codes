#include<stdio.h>
void merge(int arr[],int low,int mid,int high){
    int l = mid - low+1;
    int r = high - mid;
    int left[l],right[r];
    for(int i=0;i<l;i++)
        left[i] = arr[low+i];
    for(int j=0;j<r;j++)
        right[j]= arr[mid+1+j];
    int i=0, j=0,k=low;
    while(i<l && j<r){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else{
             arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<l){
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<r){
        arr[k]=right[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[],int low,int high){
  if(low< high){
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
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
    mergeSort(arr,0,size-1);
    printf("=======Sorted Array=======\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
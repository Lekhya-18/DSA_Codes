//BUBBLE SORT O(n^2)
#include<stdio.h>
void swap(int *a,int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
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
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    printf("=======Sorted Array========\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
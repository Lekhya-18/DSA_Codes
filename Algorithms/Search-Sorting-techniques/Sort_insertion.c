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
    for(int i=1;i<size;i++){
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
    }
    printf("=======Sorted Array=======\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
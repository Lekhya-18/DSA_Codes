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
    for(int i=0;i<size;i++){
        int min = i;
        for(int j = i+1;j<size;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
    printf("=======Sorted Array=======\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
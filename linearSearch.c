#include<stdio.h>
#include<stdbool.h>
int main(){
    int size,key;
    printf("Enter size:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements:",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    bool found = false;
    printf("Enter key:");
    scanf("%d",&key); 
    for(int i=0;i<size;i++){
        if(key == arr[i]){
            printf("Key %d found.\n",key);
            found = true;
            break;
        }
    }
    if(!found){
        printf("Key %d Not found.\n",key);
    }
    return 0;
}
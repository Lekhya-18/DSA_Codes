#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int size;
int *queue;
int front =-1, rear = -1;
bool full(){
    return (rear == size-1);
}
bool empty(){
    return (front ==-1 && rear == -1);
}
void enqueue(int val){
    if(full()){
      printf("Queue is fulled! Can't insert\n");
      return;
    }
    else if(empty()){
        front = rear = 0;
    }
    else
      rear++;
    queue[rear]=val;
    printf("%d is inserted\n",queue[rear]);
    }
void dequeue(){
    if(empty()){
        printf("Queue is empty!Can't delete");
        return;
    }
    else if(front == rear){
        printf("%d is dequeued\n",queue[front]);
        front = rear = -1; 
    }
    else{
        printf("%d is dequeued\n",queue[front]);
        front++;
    }
}
void peek(){
    if(empty()){
        printf("Queue is empty!Nothing to peek\n");
        return;
    }
    else
     printf("Front Element: %d\n",queue[front]);
}
int search(int val){
    if(empty()){
        printf("Queue is empty!");
        return -1;
    }
    else{
        for(int i=front;i<=rear;i++){
            if(val==queue[i]){
                return i;
            }
        }
        return -1;
    }
}
void display(){
    if(empty()){
        printf("Queue is empty!");
        return;
    }
    printf("_______Queue Elements_______\n");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
        if(i!=rear){
            printf("<-");
        }
    }
    printf("\n");
}
int main(){
    printf("_____Queue Using Array_____\n");
    int choice,value;
    printf("Enter Size:");
    scanf("%d",&size);
    queue = (int*)malloc(size*(sizeof(int)));
    printf("_________MENU________\n");
    printf("1.Enqueue\n" "2.Dequeue\n"
            "3.Check Overflow\n"
            "4.check Underflow\n"
            "5.Peek Element\n"
            "6.Search\n" "7.Display\n"
            "8.Exit\n");
    while(1){
        printf("Enter Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value to insert:\n");
                    scanf("%d",&value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: full()? printf("Queue Overflow\n") :printf("Queue is not filled completely\n");
                    break;
            case 4: empty()? printf("Queue Underflow\n") :printf("Queue is not empty\n");
                    break;
            case 5: peek();
                    break;
            case 6: printf("Enter value to search:\n");
                    scanf("%d",&value);
                    int found = search(value);
                    found == -1? printf("ELement Not Found.\n") : printf("Element Found at %d Position\n",found+1);
                    break;
            case 7: display();
                    break;
            case 8: exit(0);
                    break;
            default: printf("Invalid Operation.\n");
        }
    }
}
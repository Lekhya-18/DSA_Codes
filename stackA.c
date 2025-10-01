//Stack Using Arrays
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
int size; 
int *stack;
int top = -1;
bool empty(){
    return top== -1;
}
bool full(){
    return top == size-1;
}
void push(int val){
    if(full()){
        printf("Stack Overflow! Can't insert\n");
    }
    else{
        stack[++top]=val;
        printf("%d is inserted\n",stack[top]);
    }
}
void pop(){
   if(empty()){
        printf("Stack Underflow! Can't delete\n");
    }
    else{
     printf("%d is deleted from stack\n",stack[top]);
     top--;
    }
}
void peek(){
    if(empty())
       printf("Stack is empty\n");
    else
       printf("Top Most element in stack: %d\n",stack[top]);
}
int search(int key){
    if(empty()){
      return -1;
    }
    else{
        for(int i=0;i<=top;i++){
            if(key == stack[i]){
                return i;
            }
        }
    }
    return -1;
}
void display(){
    if(empty())
      printf("Stack is Empty");
    else{
        for(int i=0;i<=top;i++){
            printf("%d",stack[i]);
            if(i != top) 
               printf(" -> ");
        }
        printf("\n");
    }
}
int main(){
  int choice,value;
  printf("__________Stack_________\n");
  printf("Enter Size:");
  scanf("%d",&size);
  stack = (int*)malloc(size* sizeof(int));
  printf("_______Menu______\n");
  printf("1.To check Overflow\n" "2.To check Underflow\n"
        "3.Push element\n"  "4.Pop element \n"
        "5.Peek element \n"   "6.Search element\n"
        "7.Display stack\n"   "8.Exit\n" );
  while(1){
    printf("Enter choice:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: full()?printf("Stack Overflow\n") : printf("Stack is not filled completely\n");
                break;
        case 2: empty()?printf("Stack Underflow\n") : printf("Stack is not empty\n");
                break;
        case 3: printf("Enter value to be pushed:\n");
                scanf("%d",&value);
                push(value);
                break;
        case 4: pop();
                break;
        case 5: peek();
                break;
        case 6: printf("Enter value to search:\n");
                scanf("%d",&value);
                int found = search(value);
                found == -1? printf("Element Not Found in stack\n") : printf("Element Found at %d\n",(found+1));
                break;
        case 7: display();
                break;
        case 8: exit(0);
                break;
        default: printf("Invalid Operation\n");
    }
  }                 
  return 0;
}
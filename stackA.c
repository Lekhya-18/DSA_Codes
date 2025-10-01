//Stack Using Arrays
#include<stdio.h>
#include<stdlib.h>
int size; 
int *stack;
int top = -1;
bool empty(){}
bool full(){}
void push(int val){}
void pull(){}
void peek(){}
int main(){
  printf("Enter Size:");
  scanf("%d",&size);
  stack = (int*)malloc(size* sizeof(int));
  return 0;
}
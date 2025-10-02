#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int size;
int *queue;
bool full(){}
bool empty(){}
void enqueue(int val){}
void dequeue(){}
void peek(){}
int search(int val){}
void display(){}
int main(){
    printf("_____Queue Using Array_____");
    int choice,value;
    printf("Enter Size:");
    scanf("%d",&size);
    queue = (int*)malloc(size*(sizeof(int)));
    printf("_________MENU________");
    printf("1.Enqueue\n" "2.Dequeue\n"
            "3.Check Overflow\n"
            "4.check Underflow\n"
            "5.Peek Element\n"
            "6.Search\n" "7.Display\n"
            "8.Exit\n");
    while(1){
        printf("Enter Choice:");
        scanf("%d \n",&choice);
        switch(choice){
            case 1: printf("Enter value:");
                    scanf("%d \n",&value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: full()? printf("Queue Overflow") :printf("Queue is not filled completely");
                    break;
            case 4: empty()? printf("Queue Underflow") :printf("Queue has some elements");
                    break;
            case 5: peek();
                    break;
            case 6: printf("Enter value:");
                    scanf("%d \n",&value);
                    int found = search(value);
                    found == -1? printf("ELement Not Found.\n") : printf("Element Found at %d Position",found+1);
                    break;
            case 7: display();
                    break;
            case 8: exit(0);
                    break;
            default: printf("Invalid Operation.\n");
        }
    }
}
#include<stdio.h>
int main(){
    int choice,value,key,position;
    printf("Single linked list");
    printf("Operations that can be performed:\n");
    printf("_________MENU_________\n");
    printf("1.Insert At Beginning\n"  "2.Insert At End \n"
        "3.Insert Next to specific key \n "
        "4.Insert at the position from beginning\n"
        "5.Insert at the position from end \n "
        "6.Delete First Node\n" "7.Delete Last NOde\n"
        "8.Delete key\n 9.Delete key wrt Position\n"
        "10.Search key\n "
        "11.Traverse(Display elements)\n"
        "12.Exit\n");
    while(1){
    printf("Select Your Choice:");
    scanf("%d",&choice);
    switch(choice){
       case 1: printf("Insert At Beginning\n");
               printf("ENter value to insert:\n");
               scanf("%d",&value);
               insertAtBeginning(value);
               break;
        case 2:printf("Insert At End\n");
               printf("ENter value to insert:\n");
               scanf("%d",&value);
               insertAtEnd(value);
               break;
        case 3: printf("Insert Next to specific key\n");
               printf("ENter value to insert:\n");
               scanf("%d",&value);
               printf("Enter key:");
               scanf("%d",&key);
               insertKey(value,key);
               break;
        case 4: printf("Insert at the position from beginning:\n");
               printf("ENter value to insert:\n");
               scanf("%d",&value);
               printf("Enter position:");
               scanf("%d",&position);
               insertPosB(value,position);
               break; 
        case 5:printf("Insert at the position from End:\n");
               printf("ENter value to insert:\n");
               scanf("%d",&value);
               printf("Enter position:\n");
               scanf("%d",&position);
               insertPosE(value,position);
               break;
        case 6: printf("Delete first Node\n");
                 deleteFirst();
                 break;
        case 7: printf("Delete last Node\n");
                deleteEnd();
                break;
        case 8: printf("Delete key\n");
               printf("Enter key:\n");
               scanf("%d",&key);
               deleteKey(key);
               break;
        case 9: printf("Delete key wrt position\n");
               printf("Enter position:\n");
               scanf("%d",&position);
               deletePos(position);
               break;
        case 10: printf("Search Key\n");
                printf("Enter key:\n");
                scanf("%d",&key);
                search(key);
                break;
        case 11: printf("Display Elements\n");
                 display();
                 break;
        case 12: printf("Exiting code...\n");
                 exit(0);
                 break;
        default: printf("Invalid Opearion:");
    }
    }    
    return 0;
}

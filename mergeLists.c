#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node* next;
};
struct node* createNode(int v){
 struct node* newNode = (struct node*)malloc(sizeof(struct node));
 newNode->value = v;
 newNode->next = NULL;
 return newNode;
}
struct node* insertNode(int val,struct node* head){
    struct node* newNode = createNode(val);
    if(head==NULL){
        head = newNode;
    }
    else{
        struct node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
     return head;
}
struct node* createList(int size){
    printf("New List of size :%d\n",size);
    struct node* head =NULL;
    int i=0;
    while(i<size){
        int value;
        printf("Enter %d value:\n",i+1);
        scanf("%d",&value);
        head = insertNode(value,head);
        i++;
    }
    return head;
}
void printList(struct node* temp) {
    while (temp != NULL) {
        printf("%d ", temp-> value);
        temp = temp->next;
    }
    printf("\n");
}
/*struct node* mergeList(struct node* ll1,struct node* ll2){
    struct node* temp1 =ll1;
    struct node* temp2 =ll2;
    while(temp1->next != NULL ||temp2->next != NULL){
        if(temp1->value < temp2->value){
            temp1 = temp1->next;
        }
        else{
            temp2->next = temp1->next;
            temp1 = temp2;
        }
}
}*/ 
int main() {
    int t;
    printf("Enter No.Of TestCases:\n");
    scanf("%d",&t);
    while(t>0){
        int s1,s2;
        printf("Enter size of LL1 and LL2:\n");
        scanf("%d %d",&s1,&s2);
        struct node* l1 = createList(s1);
        struct node* l2 = createList(s2);
        printf("List 1: ");
        printList(l1);
        printf("List 2: ");
        printList(l2);
        //mergeList(l1,l2);
        t--;
    }
    return 0;
}
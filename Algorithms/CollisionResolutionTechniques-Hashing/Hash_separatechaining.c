#include<stdio.h>
#include<stdlib.h>
# define SIZE 5
struct Node{
    int data;
    struct Node* next;
};
struct Node* hash_tb[SIZE];
struct Node* hast_init(){
  for(int i=0;i<SIZE;i++)
     hash_tb[i]=NULL;
}
struct Node* create(int v){
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = v;
   newNode->next = NULL;
 return newNode;
}
int hash_func(int key){
    return (key%SIZE);
}
struct Node* insert(int key){
    int ind = hash_func(key);
    struct Node* newNode = create(key);
    newNode->next = hash_tb[ind];
    hash_tb[ind] = newNode;
}
void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hash_tb[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    hash_init();
    insert(10);
    insert(20);
    insert(23);
    insert(33);
    display();
    return 0;
}

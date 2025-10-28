#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
struct Node* insert(struct Node* root,int val){
    if(root==NULL)
      return createNode(val);
    if(val < root->data)
      root->left = insert(root->left,val);
    else if(val > root->data)
       root->right = insert(root->right,val);

    return root;
}
bool search(struct Node* root,int val){
    if(root==NULL)
      return false;
    if(root->data == val)
      return true;
    if(val < root->data)
       return search(root->left,val);
    else
       return search(root->right,val);
}
void preOrder(struct Node* root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void postOrder(struct Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
struct Node* min(struct Node* root){
    while(root && root->left != NULL)
       root = root->left;
    return root;
}
struct Node* deleteNode(struct Node* root,int val){
    if(root==NULL)
        return root;
    if(val < root->data)
        root->left = deleteNode(root->left,val);
    else if(val > root->data)
        root->right = deleteNode(root->right,val);
    else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node* temp =root->left;
            free(root);
            return temp;
        }
        else{
        struct Node* temp = min(root->right);
        root->data=temp->data;
        root->right = deleteNode(root->right,temp->data);
        }
    }
      return root;
    }
int main(){
    struct Node* root =NULL;
        printf("\n======= BINARY SEARCH TREE MENU =======");
        printf("\n1. Insert Node");
        printf("\n2. Search Node");
        printf("\n3. Delete Node");
        printf("\n4. Preorder Traversal");
        printf("\n5. Inorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\n7. Exit");
        printf("\n---------------------------------------");
        while(1){
            int choice,value;
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice){
              case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted successfully!\n");
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Value found in BST.\n");
                else
                    printf("Value not found!\n");
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Node deleted successfully (if it existed).\n");
                break;
            case 4:
                if (root == NULL) printf("BST is empty.\n");
                else {
                    printf("Preorder Traversal: ");
                    preOrder(root);
                    printf("\n");
                }
                break;
            case 5:
                if (root == NULL) printf("BST is empty.\n");
                else {
                    printf("Inorder Traversal: ");
                    inOrder(root);
                    printf("\n");
                }
                break;
            case 6:
                if (root == NULL) printf("BST is empty.\n");
                else {
                    printf("Postorder Traversal: ");
                    postOrder(root);
                    printf("\n");
                }
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }  
            }
        }


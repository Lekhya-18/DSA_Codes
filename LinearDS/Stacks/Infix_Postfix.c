#include<stdio.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c){
    stack[++top] = c;
}
char pop(){
    return stack[top--];
}
char peek(){
    return stack[top];
}
int precedence(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}
void infix_postfix(int len, char exp[]){
    char res[MAX];
    int j = 0;
    for(int i=0;i<len;i++){
        if(isalnum(exp[i])){
            res[j++] = exp[i];
        }
        else if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            while(peek()!='('){
                res[j++] = pop();
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(peek()) >= precedence(exp[i])){
                res[j++] = pop();
            }
            push(exp[i]);
        }
    }

    while(top!=-1){
        res[j++] = pop();
    }

    res[j] = '\0';

    printf("Infix: %s\n", exp);
    printf("Postfix: %s\n", res);
}

int main(){
    int len;
    printf("Enter Length of Expression: ");
    scanf("%d", &len);
    char exp[len];
    printf("Enter Expression: ");
    scanf("%s", exp);
    infix_postfix(len, exp);
}

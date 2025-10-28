//QUADRATIC PROBING
#include <stdio.h>
#define N 5
int hashtable[N];
void init(){
    for(int i=0;i<N;i++){ 
        hashtable[i]= -1;
    }
}
int hashfunction(int value){
    return (value%N);  
}
int insert(int value){
    int base = hashfunction(value);
    for(int i=0;i<N;i++){
    int ind = (base + (i*i))%N;
    if(hashtable[ind]== -1 ||hashtable[ind]== -2){
       printf("Key %d inserted \n",value);
       hashtable[ind]=value;
       break;
    }
}}
void delete_val(int value){
    int base = hashfunction(value);
    for(int i=0;i<N;i++){
    int ind = (base + (i*i))%N;
    if(hashtable[ind]== value){
       hashtable[ind]= -2;
       printf("Value is deleted\n");
       break;
    }
    } 
}
void search(int value){
    int base = hashfunction(value),found=0;
    for(int i=0;i<N;i++){
    int ind = (base + (i*i))%N;
    if(hashtable[ind]== value){
       printf("Value found at %d\n",ind);
       found =1;
       break;
    }}
    if(found==0){
         printf("NOt found\n");
        }
}
void show(){
   for(int i=0;i<N;i++){
       printf("%d \n",hashtable[i]);
    } 
}
int main() {
    init();
    insert(56); insert(47); insert(55); insert(23);insert(87); show(); search(55);
    delete_val(55); delete_val(47); search(55); 
    show(); insert(553); show();
    return 0;
}
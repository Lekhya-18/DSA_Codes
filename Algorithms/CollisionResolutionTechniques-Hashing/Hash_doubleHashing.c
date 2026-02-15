//DOUBLE HASHING 
//To check how revert works 
#include <stdio.h>
#define N 5
#define PRIME 5
int hashtable[N];
void init(){
    for(int i=0;i<N;i++){ 
        hashtable[i]= -1; 
    }
}
int hashf1(int value){ 
    return (value%N);
 }
int hashf2(int value){  
    int step = PRIME - (value%PRIME); 
    if(step == 0) step = 1; 
    return step;
}
int insert(int value){
    int base1 = hashf1(value);
    int base2 = hashf2(value);
    for(int i=0;i<N;i++){
    int ind = (base1+(i*base2))%N;
    if(hashtable[ind]== -1 ||hashtable[ind]== -2){
       printf("Key %d inserted \n",value);
       hashtable[ind]=value;
       break;
    }
}}
void delete_val(int value){
    int base1 = hashf1(value);
    int base2 = hashf2(value);
    for(int i=0;i<N;i++){
    int ind = (base1+(i*base2))%N;
    if(hashtable[ind]== value){
       hashtable[ind]= -2;
       printf("Value is deleted\n");
       break;
    }
} }
void search(int value){
    int base1 = hashf1(value),found=0;
    int base2 = hashf2(value);
    for(int i=0;i<N;i++){
    int ind = (base1+(i*base2))%N;
    if(hashtable[ind]== value){
       printf("Value found at %d\n",ind);
       found =1;
       break;
    }}
    if(found==0){ printf("NOt found\n"); }
}
void show(){
   for(int i=0;i<N;i++){
       printf("%d \n",hashtable[i]);
    } }
int main() {
    printf("To check how revert works.");
init();
insert(56); insert(47); insert(55); insert(23);insert(87); 
show();search(55);
delete_val(55); delete_val(47); search(55); show();  
    return 0;
}



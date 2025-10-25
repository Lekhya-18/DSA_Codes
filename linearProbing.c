//LINEAR PROBING
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
    int ind = hashfunction(value);
    int start = ind;
    while(ind<N){
    if(hashtable[ind]== -1 || hashtable[ind]== -2){
       printf("Key %d inserted \n",value);
       hashtable[ind]=value;
       break;
    }
    ind = (ind+1)%N;
     if(ind==start){
         break; 
    }
    }
}
int delete_val(int value){
    int ind = hashfunction(value);
    int start = ind;
    while(ind<N){
    if(hashtable[ind]== value){
       hashtable[ind]= -2;
       break;
    }
    ind = (ind+1)%N;
      if(ind==start){break;}   
    }
}
void search(int value){
   int ind = hashfunction(value);
   int start = ind,found =0;
    while(ind<N){
    if(hashtable[ind]== value){
      printf("Element found at %d\n",ind);
      found =1;
      break;
    }
    ind = (ind+1)%N;
    if(ind==start){break;}   
    }
    if(found==0){printf("Element not found\n"); }
}
void show(){
   for(int i=0;i<N;i++){
       printf("%d \n",hashtable[i]);
    } 
}
int main() {
    init();
    insert(56); insert(47); insert(55); insert(23); insert(87); 
    show(); search(55);
    delete_val(55); delete_val(47); search(55);
    insert(55);
    show();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000

struct list{
    int *arr; //declare pointer for dynamic allocate (array can't change it's size)
    int count;
};

struct list create(){
    struct list l = {NULL,0};
    l.arr = (int*)malloc(sizeof(int)*MAXSIZE);
    return l;
}

int insert(struct list *l, int v, int p){
    if (l->count==MAXSIZE){ //list is full
        return 0;
    }
    if (p<0 || p>MAXSIZE-1){ //index out of range
        return 0;
    }
    if (p<l->count){ //shift right
        for (int i=l->count;i>p;i--){
            l->arr[i] = l->arr[i-1];
        }
        l->arr[p] = v;
    }
    else{ //insert at the end of list
        l->arr[l->count] = v;
    }
    l->count++;
    return 1;
}

int deleted(struct list *l, int p){
    if (p<l->count){
        for (int i=p;i<l->count;i++){ // be replaced by right
            l->arr[i] = l->arr[i+1];
        }
        l->count--;
        return 1;
    }
    else{
        return 0;
    }
}

int find(struct list *l,int v){
    for (int i=0;i<l->count;i++){
        if (l->arr[i]==v){
            return i;
        }
    }
    return -1;
}

int main(){
    struct list l = create();
    insert(&l,10,0); //pass by reference because if finish function then the value will kill itself.
    //deleted(&l,0);
    insert(&l,5,0);
    printf("%d\n",find(&l,0));
    printf("%d %d",l.arr[0],l.arr[1]);
    return 0;
}

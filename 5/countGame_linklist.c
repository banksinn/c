#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int knock;
    int count;
    int name;
    struct node* next;
}node_t;

node_t* New(int value){
    node_t *node;
    node = (node_t*)malloc(sizeof(node_t));
    node->knock = value;
    node->count = 0;
    node->name = 0;
    node->next = NULL;
    return node;
}

node_t* append(node_t* index, int value){
    node_t *node,*keep;
    node = New(value);
    if (index==NULL){
        index = node;
        return index;
    }
    else{
        keep = index;
        while (keep->next!=NULL){
            keep = keep->next;
        }
        keep->next = node;
        return index;
    }
}

int component (int run, int k){
    int keep;
    while (run>0){
        keep = run%10;
        if (keep==k){
            return 1;
        }
        run /= 10;
    }
    return 0;
}

int main(){
    node_t *player,*first,*tmp,*keep;
    int n,k,value,run=1,check=1;
    player = NULL;
    keep = NULL;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",&value);
        player = append(player,value);
    }
    first = player;
    while (player->next!=NULL){ //Circular linklist
        player->name = check;
        //printf("%p\n",player);
        //printf("%d %d\n",player->name,player->knock);
        player = player->next;
        check++;
    }
    //printf("%p\n",player);
    player->name = check;
    //printf("%d %d\n",player->name,player->knock);
    player->next = first;
    while (check>0){
        tmp = player;
        player = player->next;
        if (check==1){
            printf("%d",player->name);
            break;
        }
        if (run%k==0 || component(run,k)){
            player->count++;
            if (player->count>player->knock){
                //printf("%p\n",tmp);
                //printf("count=%d knock=%d\n",player->count,player->knock);
                keep = player;
                tmp->next = player->next;
                player = tmp;
                free(keep);
                check--;
            }
        }
        run++;
        //printf("#%d %d count=%d component=%d run=%d\n",check,player->name,player->count,component(run,k),run);
    }
    return 0;
}

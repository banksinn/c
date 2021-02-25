#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node_t;

node_t* New(int value){
    node_t *node;
    node = (node_t*)malloc(sizeof(node_t));
    node->data = value;
    node->next = NULL;
    return node;
}

node_t* append(node_t *index){
    node_t *node,*keep;
    int value;
    scanf("%d",&value);
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

void get(node_t *index){
    int i,input;
    scanf("%d",&input);
    if (input==0){
        printf("%d\n",index->data);
    }
    else{
        for (i=0;i<input;i++){
            index=index->next;
        }
        printf("%d\n",index->data);
    }
}

void show(node_t *index){
    if (index==NULL){
        printf("\n");
    }
    else{
        while(index->next!=NULL){
            printf("%d ",index->data);
            index=index->next;
        }
        if (index->next==NULL){
            printf("%d\n",index->data);
        }
    }
}

node_t* reverse(node_t *index){
    node_t *prev,*keep,*next;
    prev = NULL;
    keep = NULL;
    next = NULL;
    while (index->next!=NULL){
        next = index->next;
        index->next = prev;
        prev = index;
        index = next;
    }
    if (index->next==NULL){
        index->next = prev;
    }
    keep = index;
    while (index->next!=NULL){
        index = index->next;
    }
    return keep;
}

node_t* cut(node_t *index){
    node_t *keep;
    int start,end,count=0;
    keep = NULL;
    scanf("%d %d",&start,&end);
    while (index->next!=NULL){
        if (count==start && count==end){
            keep = index;
            index->next = NULL;
            break;
        }
        else if (count==start){
            keep = index;
        }
        else if (count==end){
            index->next = NULL;
            break;
        }
        index = index->next;
        count++;
    }
    if (index->next==NULL && start==end){
        keep = index;
    }
    return keep;
}
int main(){
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&command);
        switch (command){
            case 'A':
                startNode = append(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                startNode = cut(startNode);
                break;
            default:
                break;
        }
    }
    return 0;
}

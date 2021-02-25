#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node_t;

typedef node_t queue_t;

queue_t* enqueue(queue_t* q, int value){
    queue_t *node,*keep;
    keep = q;
    node = (queue_t*)malloc(sizeof(queue_t));
    node->data = value;
    node->next = NULL;
    if (q==NULL){
        q = node;
        return q;
    }
    else{
        while (q->next!=NULL){
            q = q->next;
        }
        q->next = node;
        return keep;
    }
}

queue_t* dequeue(queue_t* q){
    queue_t *tmp,*keep;
    keep = q;
    tmp = NULL;
    if (q==NULL){
        printf("Queue is empty.\n");
        return NULL;
    }
    else{
        tmp = q;
        q = q->next;
        printf("%d\n",tmp->data);
        free(tmp);
        return q;
    }
}

void show(queue_t* q){
    if (q==NULL){
        printf("Queue is empty.\n");
    }
    else{
        while (q!=NULL){
            printf("%d ",q->data);
            q = q->next;
        }
        printf("\n");
    }
}

void empty(queue_t* q){
    if (q==NULL){
        printf("Queue is empty.\n");
    }
    else{
        printf("Queue is not empty.\n");
    }

}

void size(queue_t* q){
    int count = 0;
    while (q!=NULL){
        count++;
        q = q->next;
    }
    printf("%d\n",count);
}

int main(){
    queue_t *q;
    q = NULL;
    int n,i,command,value;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&command);
        switch (command){
            case 1:
                scanf("%d",&value);
                q = enqueue(q,value);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                show(q);
                break;
            case 4:
                empty(q);
                break;
            case 5:
                size(q);
                break;
        }
    }
    return 0;
}

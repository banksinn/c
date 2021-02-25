#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    double data;
    struct queue *next;
}queue_t;

queue_t* enqueue(queue_t *q, double value){
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

queue_t* dequeue(queue_t *s){
    if (s==NULL){
        return NULL;
    }
    queue_t *tmp;
    tmp = s;
    s = s->next;
    free(tmp);
    return s;
}

void show(queue_t *s){
    while (s!=NULL){
        printf("%.2lf ",s->data);
        s = s->next;
    }
    printf("\n");
}

int main(){
    int i,j,n,count=-2;
    double sum=0,first,second,change;
    char input;
    queue_t *lst,*keep,*again;
    lst = NULL;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&input);
        change = (double)input-'0';
        keep = lst;
        again = lst;
        if (input=='+' || input=='-' || input=='*' || input=='/'){
            if (input=='+'){
                for (j=0;j<count;j++){
                    keep = keep->next;
                }
                first = keep->data;
                keep = keep->next;
                second = keep->data;
                //printf("first = %.2lf, second = %.2lf ",first,second);
                sum = first+second;
                //printf("sum = %.2lf \n",sum);
                if (count>0){
                    for (j=0;j<count-1;j++){
                        again = again->next;
                    }
                    again->next = NULL;
                }
                else{
                    lst = dequeue(lst);
                    lst = dequeue(lst);
                }
                lst = enqueue(lst, sum);
                count--;
            }
            else if (input=='-'){
                for (j=0;j<count;j++){
                    keep = keep->next;
                }
                first = keep->data;
                keep = keep->next;
                second = keep->data;
                //printf("first = %.2lf, second = %.2lf ",first,second);
                sum = first-second;
                //printf("sum = %.2lf \n",sum);
                if (count>0){
                    for (j=0;j<count-1;j++){
                        again = again->next;
                    }
                    again->next = NULL;
                }
                else{
                    lst = dequeue(lst);
                    lst = dequeue(lst);
                }
                lst = enqueue(lst, sum);
                count--;
            }
            else if (input=='*'){
                for (j=0;j<count;j++){
                    keep = keep->next;
                }
                first = keep->data;
                keep = keep->next;
                second = keep->data;
                //printf("first = %.2lf, second = %.2lf ",first,second);
                sum = first*second;
                //printf("sum = %.2lf \n",sum);
                if (count>0){
                    for (j=0;j<count-1;j++){
                        again = again->next;
                    }
                    again->next = NULL;
                }
                else{
                    lst = dequeue(lst);
                    lst = dequeue(lst);
                }
                lst = enqueue(lst, sum);
                count--;
            }
            else if (input=='/'){
                for (j=0;j<count;j++){
                    keep = keep->next;
                }
                first = keep->data;
                keep = keep->next;
                second = keep->data;
                //printf("first = %.2lf, second = %.2lf ",first,second);
                sum = first/second;
                //printf("sum = %.2lf \n",sum);
                if (count>0){
                    for (j=0;j<count-1;j++){
                        again = again->next;
                    }
                    again->next = NULL;
                }
                else{
                    lst = dequeue(lst);
                    lst = dequeue(lst);
                }
                lst = enqueue(lst, sum);
                count--;
            }
        }
        else{
            lst = enqueue(lst, change);
            count++;
        }
        //show(lst);
        //printf("count = %d\n",count);
    }
    printf("%.2lf",lst->data);
    return 0;
}

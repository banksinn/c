#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int input;
    int data1;
    double data2;
    char data3[10];
    struct node *next;
}node_t;

node_t* New0(int value, int inpt){
    node_t *node;
    node = (node_t*)malloc(sizeof(node_t));
    node->input = inpt;
    node->data1 = value;
    node->next = NULL;
    return node;
}

node_t* New1(double valuef, int inpt){
    node_t *node;
    node = (node_t*)malloc(sizeof(node_t));
    node->input = inpt;
    node->data2 = valuef;
    node->next = NULL;
    return node;
}

node_t* New2(char *text, int inpt){
    int i;
    node_t *node;
    node = (node_t*)malloc(sizeof(node_t));
    node->input = inpt;
    strcpy(node->data3,text);
    node->next = NULL;
    return node;
}

node_t* append(node_t *index){
    node_t *node,*keep;
    int value1,input;
    double value2;
    char *text;
    text = (char*)malloc(sizeof(char)*10);
    scanf("%d",&input);
    switch (input){
        case 0:
            scanf("%d",&value1);
            node = New0(value1,input);
            break;
        case 1:
            scanf("%lf",&value2);
            node = New1(value2,input);
            break;
        case 2:
            scanf("%s",text);
            node = New2(text,input);
            break;
    }
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
        switch (index->input){
            case 0:printf("%d\n",index->data1);break;
            case 1:printf("%lf\n",index->data2);break;
            case 2:printf("%s\n",index->data3);break;
        }
    }
    else{
        for (i=0;i<input;i++){
            index=index->next;
        }
        switch (index->input){
            case 0:printf("%d\n",index->data1);break;
            case 1:printf("%lf\n",index->data2);break;
            case 2:printf("%s\n",index->data3);break;
        }
    }
}

void show(node_t *index){
    if (index==NULL){
        printf("\n");
    }
    else{
        while(index!=NULL){
            switch (index->input){
                case 0:printf("%d ",index->data1);break;
                case 1:printf("%lf ",index->data2);break;
                case 2:printf("%s ",index->data3);break;
            }
            index=index->next;
        }
        printf("\n");
    }
}

node_t* reverse(node_t *index){
    node_t *prev1,*prev2,*next1,*next2,*keep;
    prev1 = NULL;
    prev2 = NULL;
    next1 = NULL;
    next2 = NULL;
    keep = NULL;
    while (index->next!=NULL){
        next1 = index->next;
        index->next = prev1;
        prev1 = index;
        index = next1;
    }
    if (index->next==NULL){
        index->next = prev1;
    }
    keep=index;
    while (keep!=NULL){
        switch (keep->input){
            case 0:printf("%d ",keep->data1); break;
            case 1:printf("%lf ",keep->data2);break;
            case 2:printf("%s ",keep->data3);break;
        }
        keep = keep->next;
    }
    printf("\n");
    while (index->next!=NULL){
        next2 = index->next;
        index->next = prev2;
        prev2 = index;
        index = next2;
    }
    if (index->next==NULL){
        index->next = prev2;
    }
    return index;
}

node_t* Delete(node_t* index){
    node_t *keep,*connect1,*connect2;;
    int i,inp,count=0;
    keep = index;
    connect1 = NULL;
    connect2 = NULL;
    scanf("%d",&inp);
    if (inp==0){
        return index->next;
    }
    else{
        while (index!=NULL){
            if (count==inp-1){
                connect1 = index;
            }
            else if (count==inp){
                connect2 = index->next;
            }
            index = index->next;
            count++;
        }
        connect1->next = connect2;
        return keep;
    }
}

node_t* insert(node_t *index){
    int inp,input,value1,count=0;
    double value2;
    char *text;
    node_t *node,*keep;
    keep = index;
    text = (char*)malloc(sizeof(char)*10);
    node = (node_t*)malloc(sizeof(node_t));
    scanf("%d",&inp);
    scanf("%d",&input);
    switch (input){
        case 0:
            scanf("%d",&value1);
            node = New0(value1,input);
            break;
        case 1:
            scanf("%lf",&value2);
            node = New1(value2,input);
            break;
        case 2:
            scanf("%s",text);
            node = New2(text,input);
            break;
    }
    while (index->next!=NULL){
        if (count==inp){
            node->next = index->next;
            index->next = node;
            break;
        }
        index = index->next;
        count++;
    }
    if (index->next==NULL){
        index->next = node;
    }
    return keep;
}

node_t* cut(node_t *index){
    int inp,input,value1,count=0;
    double value2;
    char *text;
    node_t *node,*keep,*first;
    text = (char*)malloc(sizeof(char));
    keep = NULL;
    first = index;
    scanf("%d",&inp);
    scanf("%d",&input);
    switch (input){
        case 0:
            scanf("%d",&value1);
            node = New0(value1,input);
            break;
        case 1:
            scanf("%lf",&value2);
            node = New1(value2,input);
            break;
        case 2:
            scanf("%s",text);
            node = New2(text,input);
            break;
    }
    if (inp==0){
        node->next = index->next;
        return node;
    }
    else{
        while (index->next!=NULL){
            if (count==inp-1){
                keep = index;
            }
            else if (count==inp){
                node->next = index->next;
                keep->next = node;
                break;
            }
            index = index->next;
            count++;
        }
        if (index->next==NULL){
            keep->next = node;
        }
        return first;
    }
}

void empty(node_t *index){
    int count = 0;
    while (index!=NULL){
        index = index->next;
        count++;
    }
    if (count==0){
        printf("Empty\n");
    }
    else{
        printf("Not Empty\n");
    }
}

void length(node_t *index){
    int count = 0;
    while (index!=NULL){
        index = index->next;
        count++;
    }
    printf("%d\n",count);
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
            case 'D':
                startNode = Delete(startNode);
                break;
            case 'I':
                startNode = insert(startNode);
                break;
            case 'C':
                startNode = cut(startNode);
                break;
            case 'E':
                empty(startNode);
                break;
            case 'L':
                length(startNode);
                break;
            default:
                break;
        }
    }
    return 0;
}

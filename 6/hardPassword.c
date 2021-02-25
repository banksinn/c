#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    char data;
    struct stack *next;
}stack_t;

stack_t* push(stack_t *s, char value){
    stack_t *node;
    node = (stack_t*)malloc(sizeof(stack_t));
    node->data = value;
    node->next = NULL;
    node->next = s;
    s = node;
    return s;
}

stack_t* pop(stack_t *s){
    if (s==NULL){
        return NULL;
    }
    stack_t *tmp;
    tmp = s;
    s = s->next;
    free(tmp);
    return s;
}

void show(stack_t *s){
    while (s!=NULL){
        printf("%c ",s->data);
        s = s->next;
    }
    printf("\n");
}

int main(){
    stack_t *s;
    s = NULL;
    char input;
    while(1){
        input = getchar();
        if (input=='x'){
            break;
        }
        s = push(s,input);
        //show(s);
    }
    while(1){
        input = getchar();
        if (input=='y'){
            break;
        }
        if (s->data==input){
            s = pop(s);
        }
        //show(s);
    }
    if (s==NULL){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}

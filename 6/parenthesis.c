#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    char data;
    struct stack *next;
}stack_t;

stack_t* push(stack_t *s, char operand){
    stack_t *node;
    node = (stack_t*)malloc(sizeof(stack_t));
    node->data = operand;
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
    while(s!=NULL){
        printf("%c ",s->data);
        s = s->next;
    }
    printf("\n");
}

int main(){
    int i,n;
    char operand;
    stack_t *input,*tmp;
    input = NULL;
    tmp = NULL;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&operand);
        if (operand=='(' || operand=='[' || operand=='{'){
            input = push(input,operand);
            tmp = input;
        }
        if (operand==')' && tmp==NULL){
            continue;
        }
        if (operand==']' && tmp==NULL){
            continue;
        }
        if (operand=='}' && tmp==NULL){
            continue;
        }
        if (operand==')' && tmp->data=='('){
            input = pop(input);
            tmp = input;
        }
        if (operand==']' && tmp->data=='['){
            input = pop(input);
            tmp = input;
        }
        if (operand=='}' && tmp->data=='{'){
            input = pop(input);
            tmp = input;
        }
        //show(input);
    }
    if (input==NULL){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}

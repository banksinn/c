#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct code{
    int freq;
    char word[16];
    struct code *left;
    struct code *right;
}code_t;

typedef struct heap{
    struct code **data;
    int last_index;
}heap_t;

heap_t* init_heap(int n){
    int i;
    heap_t *heap;
    code_t *keep;
    heap = (heap_t*)malloc(sizeof(heap_t));
    heap->data = (code_t**)malloc(sizeof(code_t*)*n+1);
    keep = (code_t*)malloc(sizeof(code_t));
    keep->freq = 0;
    keep->left = NULL;
    keep->right = NULL;
    heap->data[0] = keep;
    for (i=1;i<n+1;i++){
        heap->data[i] = NULL;
    }
    heap->last_index = 0;
    return heap;
}

code_t* getnode(){
    code_t *group;
    group = (code_t*)malloc(sizeof(code_t));
    group->left = NULL;
    group->right = NULL;
    scanf("%s",group->word);
    scanf("%d",&group->freq);
    return group;
}

void insert(heap_t *lst, code_t* group){
    int check;
    code_t *keep;
    lst->data[lst->last_index+1] = group;
    lst->last_index++;
    check = lst->last_index;
    while (check!=0){
        if (lst->data[check/2]->freq>lst->data[check]->freq){
            keep = lst->data[check/2];
            lst->data[check/2] = lst->data[check];
            lst->data[check] = keep;
            check /= 2;
        }
        else{
            break;
        }
    }
}

code_t* delete_min(heap_t *lst){
    int parent,child1,child2;
    code_t *keep,*first;
    first = lst->data[1];
    lst->data[1] = lst->data[lst->last_index];
    if (lst->last_index==2){
        lst->last_index--;
    }
    else{
        lst->last_index--;
        parent = 1;
        while (parent<=lst->last_index){
            child1 = 2*parent;
            child2 = 2*parent+1;
            if (child1>lst->last_index && child2>lst->last_index){
                break;
            }
            if (lst->data[parent]->freq<=lst->data[child1]->freq && lst->data[parent]->freq<=lst->data[child2]->freq){
                break;
            }
            if (lst->data[child1]->freq<=lst->data[child2]->freq){
                keep = lst->data[parent];
                lst->data[parent] = lst->data[child1];
                lst->data[child1] = keep;
                parent = child1;
            }
            else{
                keep = lst->data[parent];
                lst->data[parent] = lst->data[child2];
                lst->data[child2] = keep;
                parent = child2;
            }
        }
    }
    return first;
}

code_t *gettree(code_t *first, code_t *second){
    code_t *node;
    node = (code_t*)malloc(sizeof(code_t));
    node->freq = first->freq + second->freq;
    node->left = first;
    node->right = second;
    return node;
}

void dfs(code_t *lst){
    if (lst==NULL){
        return NULL;
    }
    printf("%s %d\n",lst->word,lst->freq);
    dfs(lst->left);
    dfs(lst->right);
}

void search(code_t *lst, char text[]){
    char a[16];
    strcpy(a,text);
    if (lst==NULL){
        return NULL;
    }
    if (lst->left==NULL && lst->right==NULL){
        printf("%s : %s\n",lst->word,text);
    }
    search(lst->left,strcat(a,"0"));
    strcpy(a,text);
    search(lst->right,strcat(a,"1"));
}

int main(){
    heap_t *min_heap = NULL;
    code_t *group,*first,*second,*sum = NULL;
    int i,n;
    scanf("%d",&n);
    min_heap = init_heap(n);
    for (i=1;i<n+1;i++){
        group = getnode();
        insert(min_heap,group);
    }
    sum = init_heap(n);
    while(min_heap->last_index>1){
        first = delete_min(min_heap);
        second = delete_min(min_heap);
        /*printf("first:\n");
        dfs(first);
        printf("second:\n");
        dfs(second);*/
        sum = gettree(first,second);
        //printf("sum:\n");
        //dfs(sum);
        insert(min_heap,sum);
        /*for (i=1;i<min_heap->last_index;i++){
            printf("element[%d] = %s %d\t",i,min_heap->data[i]->word,min_heap->data[i]->freq);
        }
        printf("\nlast data:\n");
        dfs(min_heap->data[min_heap->last_index]);
        printf("\n-----------\n");*/
    }
    /*for (i=1;i<min_heap->last_index+1;i++){
        printf("%s %d\n",min_heap->data[i]->word,min_heap->data[i]->freq);
    }
    printf("%d\n",min_heap->last_index);*/
    search(min_heap->data[1],"");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct code{
    int freq;
    char *word;
}code_t;

typedef struct heap{
    struct code *data;
    int last_index;
}heap_t;

heap_t* init_heap(int n){
    int i;
    heap_t *start;
    start = (heap_t*)malloc(sizeof(heap_t));
    start->data = (code_t*)malloc(sizeof(code_t)*n+1);
    start->data[0].freq = -1;
    for (i=0;i<n+1;i++){
        start->data[i].word = (char*)malloc(sizeof(char)*16);
    }
    start->last_index = 0;
    return start;
}

void change_order(heap_t *lst){
    int check,keep_check;
    heap_t *keep;
    check = lst->last_index;
    keep_check = check;
    while (keep_check>=1){
        while (check!=0){
            if (lst->data[check/2].freq>lst->data[check].freq){
                keep->data[check/2] = lst->data[check/2];
                lst->data[check/2] = lst->data[check];
                lst->data[check] = keep->data[check/2];
                check /= 2;
            }
            else{
                break;
            }
        }
        keep_check--;
        check = keep_check;
    }
}

void delete_min(heap_t *lst){
    int parent,child1,child2;
    heap_t *keep,*del;
    //del->data[1] = lst->data[1];
    //printf("%s %d\n",del->data[1].word,del->data[1].freq);
    lst->data[1] = lst->data[lst->last_index];
    /*printf("%s %d\n",lst->data[1].word,lst->data[1].freq);
    printf("%s %d\n",lst->data[2].word,lst->data[2].freq);
    printf("%s %d\n",lst->data[3].word,lst->data[3].freq);
    printf("%s %d\n",lst->data[4].word,lst->data[4].freq);*/
    if (lst->last_index==2){
        lst->last_index--;
    }
    else{
        lst->last_index--;
        parent = 1;
        while (parent<=lst->last_index){
            child1 = 2*parent;
            child2 = 2*parent+1;
            if (child1>lst->last_index || child2>lst->last_index){
                break;
            }
            if (lst->data[parent].freq<=lst->data[child1].freq && lst->data[parent].freq<=lst->data[child2].freq){
                break;
            }
            if (lst->data[child1].freq<=lst->data[child2].freq){
                printf("pass");
                keep->data[parent] = lst->data[parent];
                printf("%s %d\n",keep->data[parent].word,keep->data[parent].freq);
                lst->data[parent] = lst->data[child1];
                printf("%s %d\n",lst->data[parent].word,lst->data[parent].freq);
                lst->data[child1] = keep->data[parent];
                printf("%s %d\n",lst->data[child1].word,lst->data[child1].freq);
                parent = child1;
            }
            else{
                keep->data[parent] = lst->data[parent];
                lst->data[parent] = lst->data[child2];
                lst->data[child2] = keep->data[parent];
                parent = child2;
            }
        }
    }
    //return del;
}

int main(){
    int n,i,f;
    char **text;
    heap_t *min_heap = NULL;
    heap_t *del1,*del2;
    scanf("%d",&n);
    text = (char**)malloc(sizeof(char*)*n+1);
    for (i=0;i<n+1;i++){
        text[i] = (char*)malloc(sizeof(char)*16);
    }
    min_heap = init_heap(n);
    for (i=1;i<n+1;i++){
        scanf("%s %d",text[i],&f);
        min_heap->data[i].freq = f;
        min_heap->data[i].word = text[i];
        min_heap->last_index++;
    }
    change_order(min_heap);
    printf("\n");
    /*for (i=1;i<min_heap->last_index+1;i++){
        printf("%s %d\n",min_heap->data[i].word,min_heap->data[i].freq);
    }
    printf("%d",min_heap->last_index);
    printf("\n");*/
    delete_min(min_heap);
    for (i=1;i<min_heap->last_index+1;i++){
        printf("%s %d\n",min_heap->data[i].word,min_heap->data[i].freq);
    }
    printf("%d\n\n",min_heap->last_index);
    delete_min(min_heap);
    for (i=1;i<min_heap->last_index+1;i++){
        printf("%s %d\n",min_heap->data[i].word,min_heap->data[i].freq);
    }
    printf("%d\n\n",min_heap->last_index);
    //printf("%s %d\n",del1->data[1].word,del1->data[1].freq);
    //printf("%s %d",del2->data[1].word,del2->data[1].freq);
    return 0;
}

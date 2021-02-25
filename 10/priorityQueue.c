#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
    int *data;
    int last_index;
}heap_t;

heap_t* init_heap(int m){
    heap_t *start;
    start = (heap_t*)malloc(sizeof(heap_t));
    start->data = (int*)malloc(sizeof(int)*m+1);
    start->data[0] = 100001;
    start->last_index = 0;
    return start;
}

void insert(heap_t *lst, int value){
    int check,keep;
    lst->data[lst->last_index+1] = value;
    lst->last_index++;
    check = lst->last_index;
    while (check!=0){
        if (lst->data[check/2]<lst->data[check]){
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

void delete_max(heap_t *lst){
    int parent,child1,child2,keep;
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
            if (child1>lst->last_index || child2>lst->last_index){
                break;
            }
            if (lst->data[child1]>=lst->data[child2]){
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
}

int find_max(heap_t *lst){
    if (lst->last_index<=0){
        return -1;
    }
    return lst->data[1];
}

void update_key(heap_t *lst, int old_key, int new_key){
    int i,check,keep;
    for (i=1;i<lst->last_index+1;i++){
        if (lst->data[i]==old_key){
            lst->data[i] = new_key;
            check = i;
            break;
        }
    }
    while (check!=0){
        if (lst->data[check/2]<lst->data[check]){
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

void bfs(heap_t *lst){
    int i;
    for (i=1;i<lst->last_index+1;i++){
        printf("%d ",lst->data[i]);
    }
    printf("\n");
}

int main(){
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;
    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i=0;i<n;i++){
        scanf("%d",&command);
        switch (command){
            case 1:
                scanf("%d", &data);
                insert(max_heap, data);
                break;
            case 2:
                delete_max(max_heap);
                break;
            case 3:
                printf("%d\n", find_max(max_heap));
                break;
            case 4:
                scanf("%d %d", &old_key, &new_key);
                update_key(max_heap, old_key, new_key);
                break;
            case 5:
                bfs(max_heap);
                break;
        }
    }
    return 0;
}

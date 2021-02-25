#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *parent;
    struct node *next_sibling;
    struct node *first_child;
}tree_t;

typedef struct stack{
    int value;
    struct stack *next;
}stack_t;

typedef stack_t queue_t;

tree_t* search_node(tree_t *index, int v){
    tree_t *pos;
    if (index == NULL || index->value == v){ //if index = NULL and has not index->value So let index == NULL first
        return index;
    }
    pos = search_node(index->first_child,v);
    if (pos != NULL){
        return pos;
    }
    else{
        return search_node(index->next_sibling,v);
    }
}

stack_t *push(stack_t *index, int v){
    stack_t *node;
    node = (stack_t*)malloc(sizeof(stack_t));
    node->value = v;
    node->next = NULL;
    if (index==NULL){
        index = node;
        return index;
    }
    else{
        node->next = index;
        return node;
    }
}

queue_t *enqueue(queue_t *index, int v){
    queue_t *node,*keep;
    node = (queue_t*)malloc(sizeof(queue_t));
    node->value = v;
    node->next = NULL;
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

queue_t *dequeue(queue_t *index){
    if (index==NULL){
        return NULL;
    }
    else{
        queue_t *tmp;
        tmp = index;
        index = index->next;
        free(tmp);
        return index;
    }
}

tree_t* attach(tree_t *index, int p, int c){
    tree_t *node,*pos,*tmp;
    node = (tree_t*)malloc(sizeof(tree_t));
    node->value = c;
    node->parent = NULL;
    node->next_sibling = NULL;
    node->first_child = NULL;
    pos = search_node(index,p);
    tmp = pos;
    if (p==-1){
        return node;
    }
    if (pos->first_child == NULL){
        pos->first_child = node;
        node->parent = pos;
    }
    else{
        pos = pos->first_child;
        while (pos->next_sibling!=NULL){
            pos = pos->next_sibling;
        }
        pos->next_sibling = node;
        node->parent = tmp;
    }
    return index;
}

tree_t* detach(tree_t *index, int v){
    tree_t *pos,*keep,*tmp;
    pos = search_node(index,v);
    tmp = pos;
    keep = pos->parent;
    if (keep->first_child == pos){
        keep->first_child = pos->next_sibling;
    }
    else{
        keep = keep->first_child;
        while (keep->next_sibling!=pos){
            keep = keep->next_sibling;
        }
        keep->next_sibling = pos->next_sibling;
        free(tmp);
    }
    return index;
}

int search(tree_t* index, int v){
    tree_t *keep;
    keep = search_node(index,v);
    if (keep == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

int degree(tree_t *index, int v){
    int count=0;
    tree_t *pos;
    pos = search_node(index,v);
    if (pos->first_child == NULL){
        return 0;
    }
    else{
        pos = pos->first_child;
        count++;
        while (pos->next_sibling!=NULL){
            pos = pos->next_sibling;
            count++;
        }
        return count;
    }
}

int is_root(tree_t *index, int v){
    if (v==index->value){
        return 1;
    }
    else{
        return 0;
    }
}

int is_leaf(tree_t *index, int v){
    tree_t *pos;
    pos = search_node(index,v);
    if (pos->first_child==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void siblings(tree_t *index, int v){
    tree_t *pos,*keep;
    pos = search_node(index,v);
    keep = pos->parent;
    if (keep==NULL){
        printf("\n");
    }
    else{
        keep = keep->first_child;
        while (keep!=NULL){
            if (keep->value==v){
                keep = keep->next_sibling;
                continue;
            }
            else{
                printf("%d ",keep->value);
            }
            keep = keep->next_sibling;
        }
        printf("\n");
    }
}

int depth(tree_t *index, int v){
    int count=0;
    tree_t *pos,*keep;
    pos = search_node(index,v);
    keep = pos->parent;
    if (keep == NULL){
        return 0;
    }
    else{
        while (1){
            if (keep==NULL){
                break;
            }
            pos = search_node(index,keep->value);
            keep = pos->parent;
            count++;
        }
        return count;
    }
}

void print_path(tree_t *index, int start, int end){
    tree_t *pos,*keep;
    pos = search_node(index,end);
    keep = pos->parent;
    if (start==end){
        printf("%d\n",start);
    }
    else{
        stack_t *tmp;
        tmp = NULL;
        while (1){
            tmp = push(tmp,pos->value);
            if (keep->value==start){
                tmp = push(tmp,keep->value);
                break;
            }
            pos = search_node(index,keep->value);
            keep = pos->parent;
        }
        while (tmp!=NULL){
            printf("%d ",tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int path_length(tree_t *index, int start, int end){
    int count = 0;
    tree_t *pos,*keep;
    pos = search_node(index,end);
    keep = pos->parent;
    if (start==end){
        return 1;
    }
    else{
        stack_t *tmp;
        tmp = NULL;
        while (1){
            tmp = push(tmp,pos->value);
            if (keep->value==start){
                tmp = push(tmp,keep->value);
                break;
            }
            pos = search_node(index,keep->value);
            keep = pos->parent;
        }
        while (tmp!=NULL){
            count++;
            tmp = tmp->next;
        }
        return count;
    }
}

void ancestor(tree_t *index, int v){
    tree_t *pos,*keep;
    pos = search_node(index,v);
    keep = pos->parent;
    if (keep==NULL){
        printf("%d\n",pos->value);
    }
    else{
        stack_t *tmp;
        tmp = NULL;
        tmp = push(tmp,pos->value);
        tmp = push(tmp,keep->value);
        while (1){
            if (keep->value==index->value){
                break;
            }
            pos = search_node(index,keep->value);
            keep = pos->parent;
            tmp = push(tmp,keep->value);
        }
        while (tmp!=NULL){
            printf("%d ",tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void bfs(tree_t *index){
    int node;
    queue_t *keep=NULL;
    tree_t *tmp=NULL;
    keep = enqueue(keep,index->value);
    while (keep!=NULL){
        node = keep->value;
        keep = dequeue(keep);
        printf("%d ",node);
        tmp = search_node(index,node);
        tmp = tmp->first_child;
        while (tmp!=NULL){
            keep = enqueue(keep,tmp->value);
            tmp = tmp->next_sibling;
        }
    }
    printf("\n");
}

void descendant(tree_t *index, int v){
    tree_t *keep;
    keep = search_node(index,v);
    bfs(keep);
}

void dfs(tree_t *index){
    int node;
    if (index==NULL){
        return NULL;
    }
    node = index->value;
    printf("%d ",node);
    dfs(index->first_child);
    dfs(index->next_sibling);
}

int root(tree_t *index){
    if (index==NULL){
        return -1;
    }
    if (index->parent==NULL){
        return 0;
    }
    return root(index->parent)+1;
}

void print_tree(tree_t *index){
    int i,n;
    if (index==NULL){
        return NULL;
    }
    n = root(index);
    for (i=0;i<n;i++){
        printf("    ");
    }
    printf("%d\n",index->value);
    print_tree(index->first_child);
    print_tree(index->next_sibling);
}

int main(){
    tree_t *t = NULL;
    int n,i,command;
    int parent,child,node,start,end;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&command);
        switch (command){
            case 1:
                scanf("%d %d",&parent,&child);
                t = attach(t,parent,child);
                break;
            case 2:
                scanf("%d",&node);
                t = detach(t,node);
                break;
            case 3:
                scanf("%d",&node);
                printf("%d\n",search(t,node));
                break;
            case 4:
                scanf("%d",&node);
                printf("%d\n",degree(t,node));
                break;
            case 5:
                scanf("%d",&node);
                printf("%d\n",is_root(t,node));
                break;
            case 6:
                scanf("%d",&node);
                printf("%d\n",is_leaf(t,node));
                break;
            case 7:
                scanf("%d",&node);
                siblings(t,node);
                break;
            case 8:
                scanf("%d",&node);
                printf("%d\n",depth(t,node));
                break;
            case 9:
                scanf("%d %d",&start,&end);
                print_path(t,start,end);
                break;
            case 10:
                scanf("%d %d",&start,&end);
                printf("%d\n",path_length(t,start,end));
                break;
            case 11:
                scanf("%d",&node);
                ancestor(t,node);
                break;
            case 12:
                scanf("%d",&node);
                descendant(t,node);
                break;
            case 13:
                bfs(t);
                break;
            case 14:
                dfs(t);
                break;
            case 15:
                print_tree(t);
                break;
        }
    }
    return 0;
}

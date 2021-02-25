#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;

typedef node_t bst_t;

bst_t* insert(bst_t *index, int value){
    bst_t *keep;
    keep = (bst_t*)malloc(sizeof(bst_t));
    keep->data = value;
    keep->left = NULL;
    keep->right = NULL;
    if (index==NULL){
        return keep;
    }
    if (value>index->data){
        index->right = insert(index->right, value);
    }
    else{
        index->left = insert(index->left, value);
    }
    return index;
}

bst_t* delete(bst_t *index, int value){
    if (index->data==value){
        if (index->left!=NULL && index->right!=NULL){
            int min;
            min = find_min(index->right);
            index->data = min;
            index->right = delete(index->right, min);
            return index;
        }
        else if (index->left!=NULL){
            return index->left;
        }
        else if (index->right!=NULL){
            return index->right;
        }
        else{
            return NULL;
        }
    }
    if (value>index->data){
        index->right = delete(index->right, value);
    }
    else if (value<index->data){
        index->left = delete(index->left, value);
    }
    return index;
}

int find(bst_t *index, int value){
    if (index==NULL){
        return 0;
    }
    if (index->data==value){
        return 1;
    }
    if (value>index->data){
        return find(index->right, value);
    }
    else{
        return find(index->left, value);
    }
}

int find_min(bst_t *index){
    if (index->left==NULL){
        return index->data;
    }
    return find_min(index->left);
}

int find_max(bst_t *index){
    if (index->right==NULL){
        return index->data;
    }
    return find_max(index->right);
}

int main(){
    bst_t *t = NULL;
    int n, i;
    int command, data;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&command);
        switch (command){
            case 1:
                scanf("%d",&data);
                t = insert(t ,data);
                break;
            case 2:
                scanf("%d",&data);
                t = delete(t, data);
                break;
            case 3:
                scanf("%d",&data);
                printf("%d\n",find(t, data));
                break;
            case 4:
                printf("%d\n",find_min(t));
                break;
            case 5:
                printf("%d\n",find_max(t));
                break;
        }
    }
    return 0;
}

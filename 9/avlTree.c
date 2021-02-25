#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node{
    int data;
    int height;
    struct node *left;
    struct node *right;
}node_t;

typedef node_t avl_t;
#endif // __avl_tree__

int height(avl_t *index){
    int hl,hr;
    if (index==NULL){
        return -1;
    }
    hl = height(index->left);
    hr = height(index->right);
    return (hl>hr)? hl+1:hr+1;
}

int check_rotation(avl_t *index){
    int hl,hr,hll,hlr,hrl,hrr;
    hl = height(index->left);
    hr = height(index->right);
    if (hl>hr){
        hll = height(index->left->left);
        hlr = height(index->left->right);
        if (hll>hlr){
            return 1; //right rotation
        }
        else if (hlr>hll){
            return 2; //left-right rotation
        }
    }
    else if (hr>hl){
        hrl = height(index->right->left);
        hrr = height(index->right->right);
        if (hrl>hrr){
            return 3; //right-left rotation
        }
        else if (hrr>hrl){
            return 4; //left rotation
        }
    }
}

avl_t* right_rotation(avl_t *index){
    avl_t *keep;
    keep = index->left;
    index->left = keep->right;
    keep->right = index;
    return keep;
}

avl_t* left_rotation(avl_t *index){
    avl_t *keep;
    keep = index->right;
    index->right = keep->left;
    keep->left = index;
    return keep;
}

avl_t *left_right_rotation(avl_t *index){
    index->left = left_rotation(index->left);
    index = right_rotation(index);
    return index;
}

avl_t *right_left_rotation(avl_t *index){
    index->right = right_rotation(index->right);
    index = left_rotation(index);
    return index;
}

avl_t* insert(avl_t *index, int value){
    avl_t *keep;
    keep = (avl_t*)malloc(sizeof(avl_t));
    keep->data = value;
    keep->height = 0;
    keep->left = NULL;
    keep->right = NULL;
    if (index==NULL){
        return keep;
    }
    if (value>index->data){
        index->right = insert(index->right, value);
        index->height = index->right->height+1;
    }
    else{
        index->left = insert(index->left, value);
        index->height = index->left->height+1;
    }
    int h,hl,hr,check;
    hl = height(index->left);
    hr = height(index->right);
    h = hl-hr;
    if (h<0){
        h *= -1;
    }
    if (h>1){
        check = check_rotation(index);
        switch (check){
            case 1:
                index = right_rotation(index);
                index->right->height = index->height-1;
                break;
            case 2:
                index = left_right_rotation(index);
                index->height++;
                index->left->height = index->height-1;
                index->right->height = index->height-1;
                break;
            case 3:
                index = right_left_rotation(index);
                index->height++;
                index->left->height = index->height-1;
                index->right->height = index->height-1;
                break;
            case 4:
                index = left_rotation(index);
                index->left->height = index->height-1;
                break;
        }
    }
    return index;
}

int find_min(avl_t *index){
    if (index->left==NULL){
        return index->data;
    }
    return find_min(index->left);
}

avl_t* delete(avl_t *index, int value){
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
        if (index->right==NULL){
            index->height = 0;
        }
        else{
            index->height = index->right->height+1;
        }
    }
    else if (value<index->data){
        index->left = delete(index->left, value);
        if (index->left==NULL){
            index->height = 0;
        }
        else{
            index->height = index->left->height+1;
        }
    }
    int h,hl,hr,check;
    hl = height(index->left);
    hr = height(index->right);
    h = hl-hr;
    if (h<0){
        h *= -1;
    }
    if (h>1){
        check = check_rotation(index);
        switch (check){
            case 1:
                index = right_rotation(index);
                index->right->height = index->height-1;
                break;
            case 2:
                index = left_right_rotation(index);
                index->height++;
                index->left->height = index->height-1;
                index->right->height = index->height-1;
                break;
            case 3:
                index = right_left_rotation(index);
                index->height++;
                index->left->height = index->height-1;
                index->right->height = index->height-1;
                break;
            case 4:
                index = left_rotation(index);
                index->left->height = index->height-1;
                break;
        }
    }
    return index;
}

int main(){
    avl_t *t = NULL;
    int n, i;
    int command, data;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&command);
        switch (command){
            case 1:
                scanf("%d",&data);
                t = insert(t, data);
                break;
            case 2:
                scanf("%d",&data);
                t = delete(t, data);
                break;
            case 3:
                print_tree(t);
                break;
        }
    }
    return 0;
}

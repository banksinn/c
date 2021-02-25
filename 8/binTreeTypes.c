#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;

typedef node_t tree_t;
#endif // __bin_tree__

int is_full(tree_t *index){
    if (index==NULL){
        return 1;
    }
    if (index->left==NULL && index->right==NULL){
        return 1;
    }
    if (index->left!=NULL && index->right!=NULL){
        return is_full(index->left) && is_full(index->right);
    }
    return 0;
}

int size(tree_t *index){
    if (index==NULL){
        return 0;
    }
    return size(index->left)+size(index->right)+1;
}

int height(tree_t *index){
    int hl,hr;
    if (index==NULL){
        return -1;
    }
    hl = height(index->left);
    hr = height(index->right);
    return (hl>hr)? hl+1:hr+1;
}

int is_perfect(tree_t *index){
    int node,h;
    node = size(index);
    h = height(index);
    if (node==(int)pow(2,h+1)-1){
        return 1;
    }
    return 0;
}

int is_complete(tree_t *index){
    int hl,hr;
    if (index==NULL){
        return 1;
    }
    hl = height(index->left);
    hr = height(index->right);
    if (hl<hr){
        return 0;
    }
    else if (hl-hr==1){
        if (is_complete(index->left)==1 && is_perfect(index->right)==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if (hl==hr){
        if (is_perfect(index->left)==1 && is_complete(index->right)==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

int is_degenerate(tree_t *index){
    int node,h;
    node = size(index);
    h = height(index);
    if (node==h+1){
        return 1;
    }
    return 0;
}

int is_skewed(tree_t *index){
    if (index->left!=NULL && index->right==NULL && is_degenerate(index)){
        while (index!=NULL){
            if (index->right!=NULL){
                return 0;
            }
            index = index->left;
        }
    }
    else if (index->right!=NULL && index->left==NULL && is_degenerate(index)){
        while (index!=NULL){
            if (index->left!=NULL){
                return 0;
            }
            index = index->right;
        }
    }
    else {
        return 0;
    }
    return 1;
}

int main(){
    tree_t *t = NULL;
    int n,i;
    int parent,child;
    int branch; //0 root 1 left 2 right
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d %d %d",&parent,&child,&branch);
        t =  attach(t,parent,child,branch);
    }
    printf("%d %d %d %d %d\n",is_full(t),is_perfect(t),is_complete(t),is_degenerate(t),is_skewed(t));
    return 0;
}

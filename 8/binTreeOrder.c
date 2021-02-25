#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;

typedef node_t tree_t;
#endif // _bin_tree_

void print_preorder(tree_t *index){
    if (index==NULL){
        return NULL;
    }
    printf("%d ",index->data);
    print_preorder(index->left);
    print_preorder(index->right);
}

void print_postorder(tree_t *index){
    if (index==NULL){
        return NULL;
    }
    print_postorder(index->left);
    print_postorder(index->right);
    printf("%d ",index->data);
}

void print_inorder(tree_t *index){
    if (index==NULL){
        return NULL;
    }
    print_inorder(index->left);
    printf("%d ",index->data);
    print_inorder(index->right);
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
    print_preorder(t);
    printf("\n");
    print_postorder(t);
    printf("\n");
    print_inorder(t);
    return 0;
}

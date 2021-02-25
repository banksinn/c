#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree{
    int end;
    struct tree *az[26];
}tree_t;

int changetoint(char s){
    return (int)s - 'a';
}

tree_t* New(void){
    int i;
    tree_t *node;
    node = (tree_t*)malloc(sizeof(tree_t));
    node->end = 0;
    for (i=0;i<26;i++){
        node->az[i] = NULL;
    }
    return node;
}

tree_t* attach(tree_t *index, char *text){
    int i,keep,length;
    tree_t *add;
    add = index;
    length = strlen(text);
    for (i=0;i<length;i++){
        keep = changetoint(text[i]);
        if (add->az[keep]==NULL){
            add->az[keep] = New();
        }
        add = add->az[keep];
    }
    add->end = 1;
    return index;
}

int search(tree_t *index, char *text){
    int i,keep,length;
    tree_t *tmp;
    tmp = index;
    length = strlen(text);
    for (i=0;i<length;i++){
        keep = changetoint(text[i]);
        if (tmp->az[keep]==NULL){
            return 0;
        }
        tmp = tmp->az[keep];
    }
    return tmp->end;
}

int main(){
    int i,n,m;
    char *text,*check;
    tree_t *dic;
    text = (char*)malloc(sizeof(char)*100);
    check = (char*)malloc(sizeof(char)*100);
    dic = New();
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++){
        scanf("%s",text);
        dic = attach(dic,text);
    }
    for (i=0;i<m;i++){
        scanf("%s",check);
        printf("%d\n",search(dic,check));
    }
}

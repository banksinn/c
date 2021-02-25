#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item{
    char *text;
    struct item *next;
}item_t;

typedef struct hash{
    item_t **table;
    int size;
    int hash_key;
}hash_t;

hash_t* init_hashtable(int m, int key){
    int i;
    hash_t *hash;
    hash = (hash_t*)malloc(sizeof(hash_t));
    hash->table = (item_t**)malloc(sizeof(item_t*)*m);
    for (i=0;i<m;i++){
        hash->table[i] = NULL;
    }
    hash->size = m;
    hash->hash_key = key;
    return hash;
}

unsigned int f(hash_t *hashtable, char *str, int len){
    if (len==0){
        //printf("text[%d]=%u  ",len,(unsigned int)str[len]);
        return (unsigned int)str[len];
    }
    //printf("text[%d]=%u  ",len,hashtable->hash_key*f(hashtable,str,len-1)+(unsigned int)str[len]);
    return hashtable->hash_key*f(hashtable,str,len-1)+(unsigned int)str[len];
}

unsigned int hash(hash_t *hashtable, char *str){
    int i;
    unsigned int hash_value = 0;
    hash_value = f(hashtable,str,strlen(str)-1);
    return hash_value%hashtable->size;
}

void insert(hash_t *hashtable, char *str){
    int i;
    item_t *item,*keep=NULL;
    item = (item_t*)malloc(sizeof(item_t));
    keep = (item_t*)malloc(sizeof(item_t));
    item->text = (char*)malloc(sizeof(char)*TEXTSIZE);
    for (i=0;i<TEXTSIZE;i++){
        item->text[i] = str[i];
    }
    item->next = NULL;
    if (hashtable->table[hash(hashtable,str)]==NULL){
        hashtable->table[hash(hashtable,str)] = item;
    }
    else{
        //printf("pass ");
        keep = hashtable->table[hash(hashtable,str)];
        hashtable->table[hash(hashtable,str)] = item;
        //printf("%s ",hashtable->table[hash(hashtable,str)]->text);
        item->next = keep;
        //printf("%s\n",hashtable->table[hash(hashtable,str)]->next->text);
    }
}

int search(hash_t *hashtable, char *str){
    if (hashtable->table[hash(hashtable,str)]==NULL){
        return -1;
    }
    else if (hashtable->table[hash(hashtable,str)]!=NULL){
        int i,check;
        item_t *keep;
        keep = hashtable->table[hash(hashtable,str)];
        while (keep!=NULL){
            //printf("str = %s\n",str);
            for (i=0;i<strlen(str);i++){
                if (keep->text[i] == str[i]){
                    check = 1;
                }
                else{
                    check = 0;
                    break;
                }
            }
            if (check==1){
                return hash(hashtable,str);
            }
            if (keep->next==NULL){
                return -1;
            }
            //printf("%s ",keep->text);
            keep = keep->next;
        }
        //printf("\n");
    }
}

int main(){
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;
    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char*)malloc(sizeof(char)*TEXTSIZE);
    for (i=0; i<n; i++){
        scanf("%d %s", &command, text);
        switch (command){
            case 1:
                insert(hashtable, text);
                break;
            case 2:
                printf("%d\n", search(hashtable, text));
                break;
        }
    }
    return 0;
}

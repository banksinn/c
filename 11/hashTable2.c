#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char* item_t;

typedef struct hash{
    item_t *table;
    int size;
    int hash_key;
}hash_t;

hash_t* init_hashtable(int m, int key){
    int i;
    hash_t *hash;
    hash = (hash_t*)malloc(sizeof(hash_t));
    hash->table = (item_t*)malloc(sizeof(item_t)*m);
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
    unsigned int hash_value = 0;
    hash_value = f(hashtable,str,strlen(str)-1);
    return hash_value%hashtable->size;
}

int F(int j){
    return (j+j*j)/2;
}

void insert(hash_t *hashtable, char *str){
    int i,j=1,keep_hash,keep;
    item_t item;
    item = (char*)malloc(sizeof(char)*TEXTSIZE);
    for (i=0;i<TEXTSIZE;i++){
        item[i] = str[i];
    }
    if (hashtable->table[hash(hashtable,str)]==NULL){
        //printf("1\n");
        hashtable->table[hash(hashtable,str)] = item;
    }
    else{
        //printf("2\n");
        keep_hash = hash(hashtable,str);
        keep = keep_hash;
        while (hashtable->table[keep]!=NULL){
            /*if (hashtable->table[keep]==NULL){
                hashtable->table[keep] = item;
            }*/
            keep = keep_hash+F(j);
            j++;
            if (keep>hashtable->size-1){
                //printf("pass\n");
                keep %= hashtable->size;
            }
        }
        if (hashtable->table[keep]==NULL){
            hashtable->table[keep] = item;
        }
    }
}

int search(hash_t *hashtable, char *str){
    int i;
    if (hashtable->table[hash(hashtable,str)]==NULL){
        return -1;
    }
    else{
        int j=1,keep_hash,keep,check;
        keep_hash = hash(hashtable,str);
        keep = keep_hash;
        while (hashtable->table[keep]!=NULL){
            //printf("str = %s, hashtable->table[keep]= %s\n",str,hashtable->table[keep]);
            for (i=0;i<strlen(str);i++){
                if (hashtable->table[keep][i]==str[i]){
                    check = 1;
                }
                else{
                    check = 0;
                    break;
                }
            }
        //printf("check = %d\n",check);
            if (check==1){
                //printf("5555\n");
                return keep;
            }
            else{
                keep = keep_hash+F(j);
                //printf("keep = %d, keep_hash = %d, F(j)=%d\n",keep,keep_hash,F(j));
                j++;
            }
            if (keep>hashtable->size-1){
                //printf("pass\n");
                keep %= hashtable->size;
                //printf("keep = %d",keep);
            }
            if (hashtable->table[keep]==NULL){
                return -1;
            }
        }
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

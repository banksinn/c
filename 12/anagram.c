#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *x, char *y){
    char keep;
    keep = *x;
    *x = *y;
    *y = keep;
}

char** New(char **inp, int n){
    int i;
    inp = (char**)malloc(sizeof(char*)*n);
    for (i=0;i<n;i++){
        inp[i] = (char*)malloc(sizeof(char)*51);
    }
    return inp;
}

char* insertion_sort(char *inp){
    int i,j;
    char *text;
    text = (char*)malloc(sizeof(char)*51);
    for (i=0;i<strlen(inp);i++){
        text[i] = inp[i];
    }
    for (i=1;i<strlen(inp);i++){
        for (j=0;j<i;j++){
            if (inp[j]>inp[i]){
                swap(&inp[j],&inp[i]);
            }
            if (inp[j]>inp[j+1]){
                swap(&inp[j],&inp[j+1]);
            }
        }
    }
    //printf("text = %s",text);
    return text;
}

int main(){
    int i,j,k,m,n;
    char **text=NULL,**anagram=NULL,**keep_text=NULL,**keep_anagram=NULL;
    scanf("%d %d",&m,&n);
    text = New(text,m);
    anagram = New(anagram,n);
    keep_text = New(keep_text,m);
    keep_anagram = New(keep_anagram,n);
    for (i=0;i<m;i++){
        scanf("%s",text[i]);
        keep_text[i] = insertion_sort(text[i]);
        //printf("%s\n",keep_text[i]);
    }
    for (i=0;i<n;i++){
        int check;
        scanf("%s",anagram[i]);
        keep_anagram[i] = insertion_sort(anagram[i]);
        for (j=0;j<m;j++){
            for (k=0;k<50;k++){
                //printf("keep_anagram[%d][%d]=%c, keep_text[%d][%d]=%c\n",i,k,keep_anagram[i][k],j,k,keep_text[j][k]);
                if (anagram[i][k]==text[j][k]){
                    check = 1;
                }
                else{
                    check = 0;
                    break;
                }
            }
            //printf("%d\n",check);
            if (check==1){
                printf("%s ",keep_text[j]);
            }
        }
        printf("\n");
        //printf("%s\n",keep_anagram[i]);
    }
    return 0;
}

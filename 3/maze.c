#include <stdio.h>
#include <string.h>

int traverseMaze(int n,int h,int k,char **table){
    int keep=0;
    if (table[h][k]=='G'){
        return 1;
    }
    if (table[h][k]!='S'){
        table[h][k] = '.';
    }
    if (k>0 && (table[h][k-1]==' ' || table[h][k-1]=='G')){
        keep += traverseMaze(n,h,k-1,table);
    }
    if (k<n-1 && (table[h][k+1]==' ' || table[h][k+1]=='G')){
        keep += traverseMaze(n,h,k+1,table);
    }
    if (h>0 && (table[h-1][k]==' ' || table[h-1][k]=='G')){
        keep += traverseMaze(n,h-1,k,table);
    }
    if (h<n-1 && (table[h+1][k]==' ' || table[h+1][k]=='G')){
        keep += traverseMaze(n,h+1,k,table);
    }
    if (keep==0){
        table[h][k] = ' ';
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int n,h,k;
    char **table;
    scanf("%d\n",&n);
    table = (char**)malloc(sizeof(char*)*n);
    for (int i=0;i<n;i++){
        table[i] = (char*)malloc(sizeof(char)*n);
    }
    for (int i=0;i<n;i++){
        gets(table[i]);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(table[i][j]=='S'){
                h=i;
                k=j;
            }
        }
    }
    traverseMaze(n,h,k,table);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%c",table[i][j]);
        }
        printf("\n");
    }
    return 0;
}

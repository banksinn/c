#include <stdio.h>

int main(){
    int m,p,n,count=0;
    char *text,*check;
    scanf("%d %d %d",&m,&p,&n);
    text = (char*)malloc(sizeof(char)*m);
    check = (char*)malloc(sizeof(char)*p);
    scanf("%s",text);
    scanf("%s",check);
    for (int i=0;i<m;i++){
        for (int j=0;j<p;j++){
            if (text[i+j]==check[j]){
                count++;
            }
        }
        if(count >= p-n && i+p<=m){
            printf("[");
            for (int j=0;j<p;j++){
                if (text[i+j]==check[j]){
                    printf("%c",text[i+j]);
                }
                else{
                    printf("?");
                }
            }
            printf("]");
            i+=(p-1);
        }
        else{
            printf("%c",text[i]);
        }
        count=0;
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(){
    char text[100000],index,count=0;
    gets(text);
    index=strlen(text)-1;
    for (int i=strlen(text)-1;i>=0;i--){
        if (text[i]==' '){
            index = i;
            for (int j=0;j<count;j++){
                printf("%c",text[index+j+1]);
            }
            printf(" ");
            count=0;
        }
        else if (i==0){
            index=i;
            for (int j=0;j<count+1;j++){
                printf("%c",text[index+j]);
            }
        }
        else{
            count++;
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

typedef struct number{
    char plus;
    char keep;
}number_t;

void plus(char x[101], char y[101], number_t *num, int len){
    int keep_x[101],keep_y[101];
    char change_x[101],change_y[101];
    for (int i=len-1;i>=0;i--){
        if ('0'<=y[i-strlen(x)+strlen(y)] && y[i-strlen(x)+strlen(y)]<='9'){
            change_y[i] = y[i-strlen(x)+strlen(y)];
        }
        else{
            change_y[i] = '0';
        }
    }
    for (int i=0;i<len;i++){
        change_x[i] = x[i];
    }
    for (int i=0;i<len;i++){
        keep_x[i]=change_x[i]-'0';
        keep_y[i]=change_y[i]-'0';
    }
    num[len-1].plus=0;
    for (int i=len-1;i>=0;i--){
        if (keep_x[i]+keep_y[i]+num[i].plus>9){
            num[i-1].plus = 1;
            num[i].keep = keep_x[i]+keep_y[i]+num[i].plus-10;
        }
        else{
            num[i-1].plus = 0;
            num[i].keep = keep_x[i]+keep_y[i]+num[i].plus;
        }
        //printf("num[%d].plus = %d, num[%d].keep = %d+%d+%d = %d\n",i,num[i].plus,i,keep_x[i],keep_y[i],num[i].plus,num[i].keep);
    }
    if (keep_x[0]+keep_y[0]+num[0].plus>=10){
        printf("1");
    }
    for (int i=0;i<len;i++){
        printf("%d",num[i].keep);
    }
}

int main(){
    char x[101],y[101];
    int len;
    number_t num[101];
    scanf("%s",x);
    scanf("%s",y);
    if (strlen(x)>=strlen(y)){
        len = strlen(x);
        plus(x,y,num,len);
    }
    else{
        len = strlen(y);
        plus(y,x,num,len);
    }
    return 0;
}
//94354657669743043298785692374893278427348962874678326498779483279234692369487837489267536
//65084675429473847289473894578934758937458973489539887349857984375983745897348957983478947

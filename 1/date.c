#include <stdio.h>
int main(){
    int d,m,y,day[]={31,28,31,30,31,30,31,31,30,31,30,31},today;
    char o1,o2;
    scanf("%d %c %d %c %d",&d,&o1,&m,&o2,&y);
    if (y%4==0 && y%100!=0 || y%400==0){
        day[1] = 29;
    }
    today = d;
    for (int i=0;i<m-1;++i){
        today+=day[i];
    }
    printf("%d",today);
    return 0;
}

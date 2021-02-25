#include <stdio.h>
int main(){
    int x,y,day,wait,come;
    scanf("%d %d",&x,&y);
    day = y/24;
    wait = y%24;
    come = x+wait;
    if(come >= 24){
        come -= 24;
        day++;
    }
    printf("%d %d",day,come);
    return 0;
}

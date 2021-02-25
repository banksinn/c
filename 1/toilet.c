#include <stdio.h>
int main(){
    int L_new,L_old,c,n,l_new,l_old,day=1;
    scanf("%d %d %d %d",&L_new,&L_old,&c,&n);
    l_new=L_new*n+c*1000;
    l_old=L_old*n;
    while(l_new>l_old){
        day++;
        l_new+=L_new*n;
        l_old+=L_old*n;
    }
    printf("%d",day);
    return 0;
}

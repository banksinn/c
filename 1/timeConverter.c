#include <stdio.h>
int main(){
    long long second,day,hour,min;
    scanf("%lli",&second);
    day = second/86400;
    second %= 86400;
    hour = second/3600;
    second %= 3600;
    min = second/60;
    second %= 60;
    printf("%lli %lli %lli %lli",day,hour,min,second);
    return 0;
}

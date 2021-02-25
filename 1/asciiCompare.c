#include <stdio.h>
int main(){
    char a,b;
    int keep;
    scanf("%c %c",&a,&b);
    keep = a-b;
    if(keep<0){
        keep *= -1;
    }
    printf("%d",keep);
    return 0;
}

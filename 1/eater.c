#include <stdio.h>
int main(){
    int x,y,z;
    char status1,status2;
    scanf("%d %d %d\n",&x,&y,&z);
    scanf("%c %c",&status1,&status2);
    if ((status1 == 'Y' || status1 == 'y') && (status2 == 'Y' || status2 == 'y')){
        printf("%d",(x+y)/z+1);
    }
    else if ((status1 == 'Y' || status1 == 'y') && (status2 == 'N' || status2 == 'n')){
        printf("%d",x+y);
    }
    else if ((status1 == 'N' || status1 == 'n') && (status2 == 'Y' || status2 == 'y')){
        printf("%d",x/z+1);
    }
    else if ((status1 == 'N' || status1 == 'n') && (status2 == 'N' || status2 == 'n')){
        printf("%d",x);
    }
    return 0;
}

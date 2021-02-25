#include <stdio.h>
int main(){
    unsigned long long m,n,side1,side2,hypotenuse,keep;
    scanf("%llu %llu",&m,&n);
    side1 = m*m-n*n;
    side2 = 2*m*n;
    hypotenuse = m*m+n*n;
    printf("%llu %llu %llu",side1,side2,hypotenuse);
    return 0;
}

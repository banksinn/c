#include <stdio.h>

int main(){
    long long n,a,b,keep;
    scanf("%lli",&n);
    for (long long i=0;i<n;i++){
        scanf("%lli %lli",&a,&b);
        while (a>0){
            keep = a;
            b %= a;
            a = b;
            b = keep;
            if (a == 0){
                printf("%lli\n",b);
            }
        }
    }
    return 0;
}

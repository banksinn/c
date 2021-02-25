#include <stdio.h>

int euclid(long long a, long long b);

int main(){
    long long a,b,c,gcd,lcm;
    scanf("%lli %lli %lli",&a,&b,&c);
    gcd = euclid(euclid(a,b),c);
    lcm = a*b/euclid(a,b);
    lcm = lcm*c/euclid(lcm,c);
    printf("%lli %lli",gcd,lcm);
    return 0;
}

int euclid(long long a, long long b){
    long long keep;
    while (a>0){
        keep = a;
        b %= a;
        a = b;
        b = keep;
        if (a == 0){
            return b;
        }
    }
}

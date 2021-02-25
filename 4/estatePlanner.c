#include <stdio.h>
#include <math.h>

int estate(int m,int n){
    int exponent=0,min;
    if (m<=n){
        min = m;
    }
    else{
        min = n;
    }
    for (int i=2;i<=min;i*=2){
        exponent++;
    }
    if (m==0 || n==0){
        return 0;
    }
    else if (m==1 && n==1){
        return 1;
    }
    else if (m==1){
        return n;
    }
    else if (n==1){
        return m;
    }
    else if (m==pow(2,exponent) && n==pow(2,exponent)){
        return 1;
    }
    else{
        return estate(pow(2,exponent),pow(2,exponent))+estate(m-pow(2,exponent),n)+estate(n-pow(2,exponent),pow(2,exponent));
    }
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d",estate(m,n));
    return 0;
}

#include <stdio.h>
#include <math.h>

int isPrime(int n){
    int prime;
    if (n<=1){
        return 0;
    }
    if (n==2){
        return 1;
    }
    for (int i=2;i<sqrt(n)+1;i++){
        if (n%i==0){
            prime = 0;
            break;
        }
        else{
            prime = 1;
        }
    }
    if (prime==1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int num;
    scanf("%d",&num);
    printf("%d",isPrime(num));
    return 0;
}

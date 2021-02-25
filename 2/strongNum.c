#include <stdio.h>
#include <stdbool.h>

bool checkstrong(int a);
int factorial(int n);

int main(){
    int n,m,strong=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&m);
        for (int j=m-1;j>=1;j--){
            if (checkstrong(j)){
                printf("%d\n",j);
                break;
            }
        }
    }
    return 0;
}

bool checkstrong(int a){
    int keep=a,sum=0;
    while (a>0){
        sum += factorial(a%10);
        a /= 10;
    }
    if (keep == sum){
        return true;
    }
    else{
        return false;
    }
}

int factorial(int n){
    int sum=1;
    for (int i=1;i<=n;i++){
        sum *= i;
    }
    return sum;
}

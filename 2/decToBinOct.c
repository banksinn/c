#include <stdio.h>

int main(){
    long long num1,num2,ans1=0,ans2=0,i=0,j=0;
    scanf("%lli",&num1);
    num2 = num1;
    while(num1>0){
        ans1 += pow(10,i)*(num1%2);
        num1 /= 2;
        i++;
    }
    printf("%lli\n",ans1);
    while(num2>0){
        ans2 += pow(10,j)*(num2%8);
        num2 /= 8;
        j++;
    }
    printf("%lli",ans2);
    return 0;
}

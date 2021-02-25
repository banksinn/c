#include <stdio.h>

int main(){
    int n,num[100000],repeat[100],max;
    for (int i=0;i<100;i++){
        repeat[i] = 0;
    }
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&num[i]);
        repeat[num[i]-1]++;
    }
    max = repeat[0];
    for (int i=0;i<100;i++){
        if (repeat[i]>max){
            max = repeat[i];
        }
    }
    for (int i=0;i<100;i++){
        if (repeat[i]==max){
            printf("%d ",i+1);
        }
    }
    return 0;
}

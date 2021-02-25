#include <stdio.h>
#include <stdlib.h>

void findStats(int n,int* nums,double* avg,int* maxi,int* mini){
    *avg = 0;
    for (int i=0;i<n;i++){
        *avg += nums[i];
    }
    *avg /= n;
    *maxi = nums[0];
    for (int i=0;i<n;i++){
        if (nums[i]>*maxi){
            *maxi = nums[i];
        }
    }
    *mini = nums[0];
    for (int i=0;i<n;i++){
        if (nums[i]<*mini){
            *mini = nums[i];
        }
    }
}

int main(){
    int n,maxi,mini;
    double avg;
    int* nums;
    scanf("%d",&n);
    nums = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",nums+i);
    }
    findStats(n,nums,&avg,&maxi,&mini);
    printf("%.2f %d %d",avg,maxi,mini);
    return 0;
}

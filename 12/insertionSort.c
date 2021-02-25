#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int keep;
    keep = *x;
    *x = *y;
    *y = keep;
}

int main(){
    int i,j,n,*data;
    scanf("%d",&n);
    data = (int*)malloc(sizeof(int)*n);
    for (i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    for (i=1;i<n;i++){
        for (j=0;j<i;j++){
            if (data[j]>data[i]){
                swap(&data[j],&data[i]);
            }
            if (data[j]>data[j+1]){
                swap(&data[j],&data[j+1]);
            }
        }
        for (j=0;j<n;j++){
            printf("%d ",data[j]);
        }
        printf("\n");
    }
    return 0;
}

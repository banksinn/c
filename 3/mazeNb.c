#include <stdio.h>

void Pattern1(int n){
    int matrix[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            matrix[j][i] = i*n+j+1;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void Pattern2(int n){
    int matrix[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            matrix[j][i] = i*n+j+1;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (j%2==0){
                printf("%d ",matrix[i][j]);
            }
            else{
                printf("%d ",matrix[n-i-1][j]);
            }
        }
        printf("\n");
    }
}

void Pattern3(int n){
    int matrix[n][n],h1,k1=0,h2=0,k2,factor1=-1,factor2=1;
    h1=n-1;
    matrix[n-1][0] = 1;
    for (int i=2;i<=n*(n+1)/2;i++){
        if (k1+factor1 == -1){
            matrix[h1+factor1][k1] = i;
            h1 += factor1;
            factor1 *= -1;
        }
        else if (h1+factor1 == n){
            matrix[h1][k1+factor1] = i;
            k1 += factor1;
            factor1 *= -1;
        }
        else{
            matrix[h1+factor1][k1+factor1] = i;
            h1 += factor1;
            k1 += factor1;
        }
        //printf("[h=%d] [k=%d] [factor=%d] matrix[h][k]=%d\n",h1,k1,factor1,matrix[h1][k1]);
    }
    k2=n-1;
    matrix[0][n-1] = n*n;
    for (int i=n*n-1;i>n*(n+1)/2;i--){
        if (k2+factor2 == n){
            matrix[h2+factor2][k2] = i;
            h2 += factor2;
            factor2 *= -1;
        }
        else if (h2+factor2 == -1){
            matrix[h2][k2+factor2] = i;
            k2 += factor2;
            factor2 *= -1;
        }
        else{
            matrix[h2+factor2][k2+factor2] = i;
            h2 += factor2;
            k2 += factor2;
        }
        //printf("[h=%d] [k=%d] [factor=%d] matrix[h][k]=%d\n",h2,k2,factor2,matrix[h2][k2]);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void Pattern4(int n){
    int matrix[n][n],check[n][n],h=0,k=0,factor=1,Case=0;
    matrix[0][0]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            check[i][j] = 0;
        }
    }
    check[0][0]=1;
    for (int i=2;i<=n*n;i++){
        if (Case%4==0){
            if (h+factor==n || check[h+factor][k]==1){
                Case++;
                matrix[h][k+factor]=i;
                check[h][k+factor]=1;
                k += factor;
            }
            else{
                matrix[h+factor][k]=i;
                check[h+factor][k]=1;
                h += factor;
            }
        }
        else if (Case%4==1){
            if (k+factor==n || check[h][k+factor]==1){
                Case++;
                matrix[h-factor][k]=i;
                check[h-factor][k]=1;
                h -= factor;
            }
            else{
                matrix[h][k+factor]=i;
                check[h][k+factor]=1;
                k += factor;
            }
        }
        else if (Case%4==2){
            if (h-factor==-1 || check[h-factor][k]==1){
                Case++;
                matrix[h][k-factor]=i;
                check[h][k-factor]=1;
                k -= factor;
            }
            else{
                matrix[h-factor][k]=i;
                check[h-factor][k]=1;
                h -= factor;
            }
        }
        else if (Case%4==3){
            if (k-factor==-1 || check[h][k-factor]==1){
                Case++;
                matrix[h+factor][k]=i;
                check[h+factor][k]=1;
                h += factor;
            }
            else{
                matrix[h][k-factor]=i;
                check[h][k-factor]=1;
                k -= factor;
            }
        }
        //printf("[h=%d] [k=%d] [factor=%d] matrix[h][k]=%d check[h][k]=%d\n",h,k,factor,matrix[h][k],check[h][k]);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    if (p==1){
        Pattern1(n);
    }
    else if (p==2){
        Pattern2(n);
    }
    else if (p==3){
        Pattern3(n);
    }
    else if (p==4){
        Pattern4(n);
    }
    return 0;
}

#include <stdio.h>

int main(){
    int A[3][2],B[2][3],C[2][2],D[2][2],B_T[3][2],sum[3][2],square_C[2][2],dif[2][2],ans[3][2],all1=0,all2=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<2;j++){
            printf("A[%d][%d]: ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<3;j++){
            printf("B[%d][%d]: ",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            printf("C[%d][%d]: ",i,j);
            scanf("%d",&C[i][j]);
        }
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            printf("D[%d][%d]: ",i,j);
            scanf("%d",&D[i][j]);
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<2;j++){
            B_T[i][j] = B[j][i];
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<2;j++){
            sum[i][j] = A[i][j] + B_T[i][j];
        }
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                all1 += C[i][k] * C[k][j];
            }
            square_C[i][j] = all1;
            all1 = 0;
        }
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            dif[i][j] = square_C[i][j] - D[i][j];
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                all2 += sum[i][k] * dif[k][j];
            }
            ans[i][j] = all2;
            all2 = 0;
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<2;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

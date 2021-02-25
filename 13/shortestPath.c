#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,k,n,m,p,u,v,w,s,t;
    int **table=NULL;
    scanf("%d %d %d",&n,&m,&p);
    table = (int**)malloc(sizeof(int*)*n);
    for (i=0;i<n;i++){
        table[i] = (int*)malloc(sizeof(int)*n);
    }
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (i==j){
                table[i][j] = 0;
            }
            else{
                table[i][j] = 101;
            }
        }
    }
    for (i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        table[u][v] = w;
        table[v][u] = w;
    }
    /*for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }*/
    printf("\n");
    //table[0][0] = table[1][0] + table[0][1];
    for (k=0;k<n;k++){ //floyd warshall
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                if (table[i][j] > table[i][k] + table[k][j]){
                    //printf("table[%d][%d] = %d, table[%d][%d] = %d, table[%d][%d] = %d\n",i,j,table[i][j],i,k,table[i][k],k,j,table[k][j]);
                    table[i][j] = table[i][k] + table[k][j];
                    //printf("table[%d][%d] = %d\n",i,j,table[i][j]);
                }
            }
        }
    }
    /*for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }*/
    for (i=0;i<p;i++){
        scanf("%d %d",&s,&t);
        if (table[s][t]==101){
            printf("-1\n");
        }
        else{
            printf("%d\n",table[s][t]);
        }
    }
    return 0;
}

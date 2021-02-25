#include <stdio.h>

int main(){
    int n,m,x,y,direction,h,k,count=0;
    int **table;
    scanf("%d %d %d %d %d",&n,&m,&x,&y,&direction);
    table = (int**)malloc(sizeof(int*)*n);
    for (int i=0;i<n;i++){
        table[i] = (int*)malloc(sizeof(int)*m);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            table[i][j] = 0;
        }
    }
    h=x;
    k=y;
    while (1){
        if (table[h][k]==10){
            break;
        }
        if (direction==0){
            if (x==0){
                table[x][y]++;
                x++;
                direction=4;
            }
            else{
                table[x][y]++;
                x--;
            }
        }
        else if (direction==1){
            if (x==0 && y==m-1){
                table[x][y]++;
                x++;
                y--;
                direction=5;
            }
            else if (x==0){
                table[x][y]++;
                x++;
                y++;
                direction=3;
            }
            else if (y==m-1){
                x--;
                y--;
                direction=7;
            }
            else{
                table[x][y]++;
                x--;
                y++;
            }
        }
        else if (direction==2){
            if (y==m-1){
                table[x][y]++;
                y--;
                direction=6;
            }
            else{
                table[x][y]++;
                y++;
            }
        }
        else if (direction==3){
            if (x==n-1 && y==m-1){
                table[x][y]++;
                x--;
                y--;
                direction=7;
            }
            else if (y==m-1){
                table[x][y]++;
                x++;
                y--;
                direction=5;
            }
            else if (x==n-1){
                table[x][y]++;
                x--;
                y++;
                direction=1;
            }
            else{
                table[x][y]++;
                x++;
                y++;
            }
        }
        else if (direction==4){
            if (x==n-1){
                table[x][y]++;
                x--;
                direction=0;
            }
            else{
                table[x][y]++;
                x++;
            }
        }
        else if (direction==5){
            if (x==n-1 && y==0){
                table[x][y]++;
                x--;
                y++;
                direction=1;
            }
            else if (x==n-1){
                table[x][y]++;
                x--;
                y--;
                direction=7;
            }
            else if (y==0){
                table[x][y]++;
                x++;
                y++;
                direction=3;
            }
            else{
                table[x][y]++;
                x++;
                y--;
            }
        }
        else if (direction==6){
            if (y==0){
                table[x][y]++;
                y++;
                direction=2;
            }
            else{
                table[x][y]++;
                y--;
            }
        }
        else if (direction==7){
            if (x==0 && y==0){
                table[x][y]++;
                x++;
                y++;
                direction=3;
            }
            else if (y==0){
                table[x][y]++;
                x--;
                y++;
                direction=1;
            }
            else if (x==0){
                table[x][y]++;
                x++;
                y--;
                direction=5;
            }
            else{
                table[x][y]++;
                x--;
                y--;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (table[i][j]!=0){
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}

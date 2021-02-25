#include <stdio.h>

void allowNorth(int n);
void allowSouth(int n);
void allowEast(int n);
void allowWest(int n);

int main(){
    char direction;
    int n;
    scanf("%c %d",&direction,&n);
    if (direction == 'N'){
        allowNorth(n);
    }
    else if (direction == 'S'){
        allowSouth(n);
    }
    else if (direction == 'E'){
        allowEast(n);
    }
    else if (direction == 'W'){
        allowWest(n);
    }
    return 0;
}

void allowNorth(int n){
    for (int i=0;i<n+1;i++){
        for (int j=0;j<n-i;j++){
            printf(" ");
        }
        for (int k=0;k<2*i+1;k++){
            printf("#");
        }
        printf("\n");
    }
    for (int i=0;i<n+1;i++){
        printf(" ");
        for (int j=0;j<2*n-1;j++){
            printf("#");
        }
        printf("\n");
    }
}

void allowSouth(int n){
    for (int i=0;i<n+1;i++){
        printf(" ");
        for (int j=0;j<2*n-1;j++){
            printf("#");
        }
        printf("\n");
    }
    for (int i=n+1;i>0;i--){
        for (int j=0;j<n+1-i;j++){
            printf(" ");
        }
        for (int k=2*i-1;k>0;k--){
            printf("#");
        }
        printf("\n");
    }
}

void allowEast(int n){
    for (int i=0;i<2*n+1;i++){
        if (i==0 || i==2*n){
            for (int j=0;j<n+1;j++){
                printf(" ");
            }
        }
        else{
            for (int j=0;j<n+1;j++){
                printf("#");
            }
        }
        if (i<=n){
            for (int k=0;k<i+1;k++){
                printf("#");
            }
        }
        else{
            for (int k=i-n;k<n+1;k++){
                printf("#");
            }
        }
        printf("\n");
    }
}

void allowWest(int n){
    for (int i=0;i<2*n+1;i++){
        if (i<=n){
            for (int j=n;j>i;j--){
                printf(" ");
            }
            if (i!=0){
                for (int k=0;k<n+1;k++){
                    printf("#");
                }
            }
            for (int k=0;k<i+1;k++){
                printf("#");
            }
            printf("\n");
        }
        else{
            for (int j=0;j<i-n;j++){
                printf(" ");
            }
            if (i!= 2*n){
                for (int k=0;k<n+1;k++){
                    printf("#");
                }
            }
            for (int k=i-n;k<n+1;k++){
                printf("#");
            }
            printf("\n");
        }
    }
}

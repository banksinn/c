#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkdirection(int start, char change);

int main(){
    int n,start=0,direction[]={0,0,0,0},side1,side2; // E,S,W,N
    float distance;
    char keep;
    scanf("%d\n",&n);
    for (int i=0;i<n;i++){
        scanf("%c",&keep);
        start = checkdirection(start,keep);
        if (keep == 'F'){
            direction[start]++;
        }
    }
    side1 = abs(direction[0]-direction[2]);
    side2 = abs(direction[1]-direction[3]);
    distance = sqrt(pow(side1,2)+pow(side2,2));
    printf("%.4f",distance);
    return 0;
}

int checkdirection(int start, char change){
    if (change == 'R'){
        start++;
        if (start == 4){
            return 0;
        }
        else{
            return start;
        }
    }
    else if (change == 'L'){
        start--;
        if (start == -1){
            return 3;
        }
        else{
            return start;
        }
    }
    else if (change == 'F'){
        return start;
    }
}

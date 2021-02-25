#include <stdio.h>
#include <math.h>

double factorial(int n);

int main(){
    int degree;
    double sin=0,cos,tan,rad;
    scanf("%d",&degree);
    rad = degree*M_PI/180;
    for (int i=1,j=0;i<20,j<10;i+=2,j++){
        if (j%2 == 0){
            sin += pow(rad,i)/factorial(i);
        }
        else{
            sin -= pow(rad,i)/factorial(i);
        }
    }
    cos = sqrt(1-pow(sin,2));
    tan = sin/cos;
    printf("%.14lf %.14lf %.14lf",sin,cos,tan);
    return 0;
}

double factorial(int n){
    double sum = 1;
    for (int i=1;i<=n;i++){
        sum *= i;
    }
    return sum;
}

#include <stdio.h>
#include <math.h>

int main(){
    int n;
    double a,b,A,B,h,ans=0;
    scanf("%lf %lf %lf %lf %d",&a,&b,&A,&B,&n);
    h = (b-a)/n;
    for (int i=0;i<n;i++){
        ans += 0.5*h*(A*sin(M_PI*a/B)+A*sin(M_PI*(a+h)/B));
        a += h;
    }
    printf("%.5lf",ans);
    return 0;
}

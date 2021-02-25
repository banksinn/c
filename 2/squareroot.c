#include <stdio.h>
#include <math.h>

int main(){
    double n,lg,cg;
    scanf("%lf %lf",&n,&lg);
    cg = 0.5*(lg+n/lg);
    while (fabs(cg-lg)>=1e-10){
        printf("%.10lf %.10lf %.10lf\n",cg,lg,fabs(cg-lg));
        lg = cg;
        cg = 0.5*(lg+n/lg);
    }
    printf("%.10lf %.10lf %.10lf\n",cg,lg,fabs(cg-lg));
    printf("%.10lf",cg);
    return 0;
}

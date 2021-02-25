#include <stdio.h>
int main(){
    int length,width;
    double area,time;
    printf("length(m.): ");
    scanf("%d",&length);
    printf("width(m.): ");
    scanf("%d",&width);
    area = (length*3.28084)*(width*3.28084);
    time = area/2;
    printf("Use %.5lf seconds.",time);
    return 0;
}

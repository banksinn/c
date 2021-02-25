#include <stdio.h>
int main(){
    int a,b,h;
    float area;
    printf("a: ");
    scanf("%d",&a);
    printf("b: ");
    scanf("%d",&b);
    printf("h: ");
    scanf("%d",&h);
    area = 0.5*(a+b)*h;
    printf("area : %.1f",area);
    return 0;
}

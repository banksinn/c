#include <stdio.h>
int main(){
    char o;
    int a,b;
    scanf("%d %c %d",&a,&o,&b);
    if (o == '+'){
        printf("%d",a+b);
    }
    else if (o == '-'){
        printf("%d",a-b);
    }
    else if (o == '*'){
        printf("%d",a*b);
    }
    else if (o == '/'){
        float c=a,d=b;
        printf("%.2f",c/d);
    }
    else if (o == '%'){
        printf("%d",a%b);
    }
    else{
        printf("Unknown Operator");
    }
    return 0;
}

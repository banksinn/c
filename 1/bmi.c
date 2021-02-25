#include <stdio.h>
int main(){
    float weight,height,high,bmi;
    scanf("%f %f",&weight,&height);
    high = height/100;
    bmi = weight/(high*high);
    printf("BMI: %.4f ",bmi);
    printf("and you are ");
    if (bmi>=30){
        printf("obese");
    }
    else if (bmi>=25){
        printf("overweight");
    }
    else if (bmi>=18.6){
        printf("healthy");
    }
    else{
        printf("underweight");
    }
    return 0;
}

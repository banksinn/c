#include <stdio.h>
#include <math.h>

void roman(int n, int count);

int main(){
    int n,count=-1,num,keep,rest;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&num);
        keep = num;
        while(keep>0){
            keep /= 10;
            count++;
        }
        while(num>0){
            rest = num/pow(10,count);
            roman(rest,count);
            num %= (int)pow(10,count); // % can only use in int
            count--;
        }
        printf("\n");
    }
    return 0;
}

void roman(int n, int count){
    int amount;
    amount = n*pow(10,count);
    switch (amount){
        case 3000: printf("MMM");break;
        case 2000: printf("MM");break;
        case 1000: printf("M");break;
        case 900: printf("CM");break;
        case 800: printf("DCCC");break;
        case 700: printf("DCC");break;
        case 600: printf("DC");break;
        case 500: printf("D");break;
        case 400: printf("CD");break;
        case 300: printf("CCC");break;
        case 200: printf("CC");break;
        case 100: printf("C");break;
        case 90: printf("XC");break;
        case 80: printf("LXXX");break;
        case 70: printf("LXX");break;
        case 60: printf("LX");break;
        case 50: printf("L");break;
        case 40: printf("XL");break;
        case 30: printf("XXX");break;
        case 20: printf("XX");break;
        case 10: printf("X");break;
        case 9: printf("IX");break;
        case 8: printf("VIII");break;
        case 7: printf("VII");break;
        case 6: printf("VI");break;
        case 5: printf("V");break;
        case 4: printf("IV");break;
        case 3: printf("III");break;
        case 2: printf("II");break;
        case 1: printf("I");break;
    }
}

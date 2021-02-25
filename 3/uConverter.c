#include <stdio.h>
#include <string.h>

int ChangetoInt(char num){
    if ('0'<=num && num<='9'){
        return num - '0';
    }
    else if ('A'<=num && num<='T'){
        return num - '7';
    }
}

char ChangetoString(int num){
    if (0<=num && num<=9){
        return num + '0';
    }
    else if (10<=num && num<=29){
        return num + '7';
    }
}

int main(){
    int m,n,exponent,dec=0,keep,count=0,frac[20],index;
    char num[20];
    scanf("%d %d",&m,&n);
    scanf("%s",num);
    exponent = strlen(num)-1;
    for (int i=0;i<strlen(num);i++){
        dec += ChangetoInt(num[i])*pow(m,exponent);
        exponent--;
    }
    keep = dec;
    while (keep>0){
        count++;
        keep /= n;
    }
    index = count-1;
    while (dec>0){
        frac[index] = ChangetoString(dec%n);
        dec /= n;
        index--;
    }
    for (int i=0;i<count;i++){
        printf("%c",frac[i]);
    }
    return 0;
}

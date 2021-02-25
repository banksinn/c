#include <stdio.h>
#include <stdbool.h>

void calendar(int year, int month);
bool isLeapyear(int year);

int main(){
    int year,month;
    printf("Enter year: ");
    scanf("%d",&year);
    printf("Enter month: ");
    scanf("%d",&month);
    calendar(year,month);
    return 0;
}

void calendar(int year, int month){
    int day=1,start=1,last;
    printf("====================\n");
    switch (month){
        case 1:printf("January %d\n",year);break;
        case 2:printf("February %d\n",year);break;
        case 3:printf("March %d\n",year);break;
        case 4:printf("April %d\n",year);break;
        case 5:printf("May %d\n",year);break;
        case 6:printf("June %d\n",year);break;
        case 7:printf("July %d\n",year);break;
        case 8:printf("August %d\n",year);break;
        case 9:printf("September %d\n",year);break;
        case 10:printf("October %d\n",year);break;
        case 11:printf("November %d\n",year);break;
        case 12:printf("December %d\n",year);break;
    }
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i=1990;i<=year;i++){
        for (int j=1;j<=12;j++){
            if (i == year && j == month){
                break;
            }
            if (j==1){
                day+=31;
            }
            else if (j==2){
                if (isLeapyear(i)){
                    day+=29;
                }
                else{
                    day+=28;
                }
            }
            else{
                switch (j){
                    case 3:day+=31;break;
                    case 4:day+=30;break;
                    case 5:day+=31;break;
                    case 6:day+=30;break;
                    case 7:day+=31;break;
                    case 8:day+=31;break;
                    case 9:day+=30;break;
                    case 10:day+=31;break;
                    case 11:day+=30;break;
                    case 12:day+=31;break;
                }
            }
        }
    }
    if (month==1){
        last=31;
    }
    else if (month==2){
        if (isLeapyear(year)){
            last=29;
        }
        else{
            last=28;
        }
    }
    switch (month){
        case 3:last=31;break;
        case 4:last=30;break;
        case 5:last=31;break;
        case 6:last=30;break;
        case 7:last=31;break;
        case 8:last=31;break;
        case 9:last=30;break;
        case 10:last=31;break;
        case 11:last=30;break;
        case 12:last=31;break;
    }
    for (int i=0;i<day%7;i++){
        printf("    ");
    }
    for (int i=day%7;i<7;i++){
        printf("%3d",start);
        start++;
        if (start == last+1){
            break;
        }
        if (i == 6){
            printf("\n");
            i=-1;
        }
        else{
            printf(" ");
        }
    }
}

bool isLeapyear(int year){
    if (year%4==0 && year%100!=0 || year%400==0){
        return true;
    }
    else{
        return false;
    }
}

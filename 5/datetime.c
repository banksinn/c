#include <stdio.h>

typedef struct{
    int date; //1-31
    int month; //1-12
    int year; //1970++
    int dayOfWeek; //0-6
    int hour; //0-23
    int minute; //0-59
    int second; //0-59
}date;

date createDate(int times){
    date now;
    int year=1970,day,sec,keep_day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    day = times/86400;
    now.dayOfWeek = day%7;
    while (day>0){
        if (day<=365){
            day++;
            break;
        }
        if ((year%4==0 && year%100!=0 || year%400==0) && day>=366){
            day-=366;
            year++;
        }
        else{
            day-=365;
            year++;
        }
    }
    if (year%4==0 && year%100!=0 || year%400==0){
        keep_day[1]++;
    }
    for (int i=0;i<12;i++){
        if (day>=keep_day[i]){
            day-=keep_day[i];
        }
        else{
            now.month = i+1;
            now.date = day;
            break;
        }
    }
    now.year = year;
    if (times<86400){
        now.date++;
    }
    sec = times%86400;
    now.hour = sec/3600;
    sec %= 3600;
    now.minute = sec/60;
    now.second = sec%60;
    return now;
}

void printDate(date input){
    switch (input.dayOfWeek){
        case 0:printf("Thu ");break;
        case 1:printf("Fri ");break;
        case 2:printf("Sat ");break;
        case 3:printf("Sun ");break;
        case 4:printf("Mon ");break;
        case 5:printf("Tue ");break;
        case 6:printf("Wed ");break;
    }
    printf("%d ",input.date);
    switch (input.month){
        case 1:printf("JAN ");break;
        case 2:printf("FEB ");break;
        case 3:printf("MAR ");break;
        case 4:printf("APR ");break;
        case 5:printf("MAY ");break;
        case 6:printf("JUN ");break;
        case 7:printf("JUL ");break;
        case 8:printf("AUG ");break;
        case 9:printf("SEP ");break;
        case 10:printf("OCT ");break;
        case 11:printf("NOV ");break;
        case 12:printf("DEC ");break;
    }
    printf("%d ",input.year);
    printf("%02d:%02d:%02d",input.hour,input.minute,input.second);
}

int main(){
    date inputDate;
    int timestamp;
    scanf("%d",&timestamp);
    inputDate = createDate(timestamp);
    //printf("%d %d %d %d %d %d %d",inputDate.date,inputDate.month,inputDate.year,inputDate.dayOfWeek,inputDate.hour,inputDate.minute,inputDate.second);
    printDate(inputDate);
    return 0;
}

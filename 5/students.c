#include <stdio.h>
#include <math.h>

typedef struct student{
    char name[30];
    int score;
}student_t;

void inputStudent(student_t *students, int n){ //students[i].name = variable
    for (int i=0;i<n;i++){
        scanf("%s %d",students[i].name,&students[i].score);
    }
}

void showStudentGrade(student_t *students, int n){
    double mean=0,sd=0;
    for (int i=0;i<n;i++){
        mean += students[i].score;
    }
    mean /= n;
    for (int i=0;i<n;i++){
        sd += pow(students[i].score - mean,2);
    }
    sd /= (n-1);
    sd = sqrt(sd);
    for (int i=0;i<n;i++){
        if (students[i].score>=mean+(1.5*sd)){
            printf("%s A\n",students[i].name);
        }
        else if (students[i].score<mean+(1.5*sd) && students[i].score>=mean+sd){
            printf("%s B\n",students[i].name);
        }
        else if (students[i].score<mean+sd && students[i].score>=mean-sd){
            printf("%s C\n",students[i].name);
        }
        else if (students[i].score<mean-sd && students[i].score>=mean-(1.5*sd)){
            printf("%s D\n",students[i].name);
        }
        else if (students[i].score<mean-(1.5*sd)){
            printf("%s F\n",students[i].name);
        }
    }
}

int main(){
    student_t students[1000];
    int n;
    scanf("%d",&n);
    inputStudent(students,n);
    showStudentGrade(students,n);
    return 0;
}

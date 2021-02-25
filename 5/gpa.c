#include <stdio.h>
#include <stdlib.h>

typedef struct subject{
    int student;
    int index;
    int count;
    float score;
    struct subject *next;
}subject_t;

typedef struct student{
    int subject;
    int index;
    int count;
    float score;
    struct student *next;
}student_t;

float grade(float score){
    if (score>=80){
        return 4;
    }
    else if (score>=75){
        return 3.5;
    }
    else if (score>=70){
        return 3;
    }
    else if (score>=65){
        return 2.5;
    }
    else if (score>=60){
        return 2;
    }
    else if (score>=55){
        return 1.5;
    }
    else if (score>=50){
        return 1;
    }
    else{
        return 0;
    }
}

subject_t* New_sj(int b, float c){
    subject_t* create=NULL;
    create = (subject_t*)malloc(sizeof(subject_t));
    create->student = b;
    create->score = c;
    create->next = NULL;
    return create;
}

student_t* New_st(int a, float c){
    student_t* create=NULL;
    create = (student_t*)malloc(sizeof(student_t));
    create->subject = a;
    create->score = grade(c);
    create->next = NULL;
    return create;
}

subject_t* insert_sj(subject_t *index, int a , int b, float c){
    subject_t *node,*keep,*tmp;
    node = New_sj(b,c);
    if (index[a].next==NULL){
        index[a].next = node;
        index[a].count++;
        index[a].score += c;
        return index;
    }
    else{
        keep = &index[a];
        tmp = keep;
        keep = keep->next;
        while (keep!=NULL){
            if (keep->student > b){
                break;
            }
            tmp = keep;
            keep = keep->next;
        }
        node->next = keep;
        tmp->next = node;
        index[a].count++;
        index[a].score += c;
        return index;
    }
}

student_t* insert_st(student_t *index, int b, int a, float c){
    student_t *node,*keep,*tmp;
    node = New_st(a,c);
    if (index[b].next==NULL){
        index[b].next = node;
        index[b].count++;
        index[b].score += grade(c);
        return index;
    }
    else{
        keep = &index[b];
        tmp = keep;
        keep = keep->next;
        while (keep!=NULL){
            if (keep->subject > a){
                break;
            }
            tmp = keep;
            keep = keep->next;
        }
        node->next = keep;
        tmp->next = node;
        index[b].count++;
        index[b].score += grade(c);
        return index;
    }
}

int main(){
    int i,n,x,y,a,b,c;
    subject_t *sj = NULL;
    student_t *st = NULL;
    scanf("%d",&n);
    scanf("%d %d",&x,&y);
    sj = (subject_t*)malloc(sizeof(subject_t)*x);
    st = (student_t*)malloc(sizeof(student_t)*y);
    for (i=0;i<x;i++){
        sj[i].student = 0;
        sj[i].index = 0;
        sj[i].count = 0;
        sj[i].score = 0;
        sj[i].next = NULL;
    }
    for (i=0;i<y;i++){
        st[i].subject = 0;
        st[i].index = 0;
        st[i].count = 0;
        st[i].score = 0;
        st[i].next = NULL;
    }
    for (i=0;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        sj = insert_sj(sj,a-1,b,c);
        st = insert_st(st,b-1,a,c);
    }
    for (i=0;i<x;i++){
        if (sj[i].count>0){
            printf("subject%d: %.2f\n",i+1,(float)sj[i].score/sj[i].count);
            subject_t *keep_sj = &sj[i];
            keep_sj = keep_sj->next;
            while (keep_sj!=NULL){
                printf("    std%d: %.2f\n",keep_sj->student,keep_sj->score);
                keep_sj = keep_sj->next;
            }
        }
    }
    printf("--------------------\n");
    for (i=0;i<y;i++){
        if (st[i].count>0){
            printf("student%d: %.2f\n",i+1,(float)st[i].score/st[i].count);
            student_t *keep_st = &st[i];
            keep_st = keep_st->next;
            while (keep_st!=NULL){
                printf("    sub%d: %.2f\n",keep_st->subject,keep_st->score);
                keep_st = keep_st->next;
            }
        }
    }
    return 0;
}

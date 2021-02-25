#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int input;
    int add;
    struct node *next;
}node_t;

node_t* append(node_t *index, int value){
    node_t *node,*keep;
    keep = index;
    node = (node_t*)malloc(sizeof(node_t));
    node->input = value;
    node->add = 0;
    node->next = NULL;
    if (index==NULL){
        index = node;
        return index;
    }
    else{
        while (index->next!=NULL){
            index=index->next;
        }
        index->next=node;
        return keep;
    }
}

node_t* reverse(node_t *index){
    node_t *prev,*keep,*next;
    prev = NULL;
    keep = NULL;
    next = NULL;
    while (index->next!=NULL){
        next = index->next;
        index->next = prev;
        prev = index;
        index = next;
    }
    if (index->next==NULL){
        index->next = prev;
    }
    keep = index;
    while (index->next!=NULL){
        index = index->next;
    }
    return keep;
}

void printList(node_t *index){
    while (index!=NULL){
        printf("%c",(char)index->input+'0');
        index=index->next;
    }
    printf("\n");
}

int main(){
    int count1=0,count2=0,keep;
    node_t *number1,*number2,*number_r1,*number_r2,*ans,*ans_r;
    number1 = NULL;
    number2 = NULL;
    number_r1 = NULL;
    number_r2 = NULL;
    ans = NULL;
    ans_r = NULL;
    char inp;
    while (1){
        inp = getchar();
        if (inp=='\n'){
            break;
        }
        number1 = append(number1,(int)inp-'0');
        count1++;
    }
    number_r1 = reverse(number1);
    while (1){
        inp = getchar();
        if (inp=='\n'){
            break;
        }
        number2 = append(number2,(int)inp-'0');
        count2++;
    }
    number_r2 = reverse(number2);
    if (count1>=count2){
        count1=0;
        while(number_r2!=NULL){
            if (count1==0){
                keep = number_r1->input+number_r2->input;
            }
            else{
                keep = number_r1->input+number_r2->input+ans->add;
            }
            if (keep>=10){
                ans = append(ans,keep-10);
                ans->add = 1;
            }
            else{
                ans = append(ans,keep);
                ans->add = 0;
            }
            number_r1 = number_r1->next;
            number_r2 = number_r2->next;
            count1++;
        }
        while(number_r1!=NULL){
            keep = number_r1->input+ans->add;
            if (keep>=10){
                ans = append(ans,keep-10);
                ans->add = 1;
            }
            else{
                ans = append(ans,keep);
                ans->add = 0;
            }
            number_r1 = number_r1->next;
        }
        if (ans->add==1){
            ans = append(ans,1);
        }
    }
    else{
        count2=0;
        while(number_r1!=NULL){
            if (count2==0){
                keep = number_r1->input+number_r2->input;
            }
            else{
                keep = number_r1->input+number_r2->input+ans->add;
            }
            if (keep>=10){
                ans = append(ans,keep-10);
                ans->add = 1;
            }
            else{
                ans = append(ans,keep);
                ans->add = 0;
            }
            number_r1 = number_r1->next;
            number_r2 = number_r2->next;
            count2++;
        }
        while(number_r2!=NULL){
            keep = number_r2->input+ans->add;
            if (keep>=10){
                ans = append(ans,keep-10);
                ans->add = 1;
            }
            else{
                ans = append(ans,keep);
                ans->add = 0;
            }
            number_r2 = number_r2->next;
        }
        if (ans->add==1){
            ans = append(ans,1);
        }
    }
    ans_r = reverse(ans);
    printList(ans_r);
    return 0;
}
//94354657669743043298785692374893278427348962874678326498779483279234692369487837489267536
//65084675429473847289473894578934758937458973489539887349857984375983745897348957983478947

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void print_list(struct node *head){

    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }

}

void main() {
    
    struct node *head;
    struct node *one=NULL;
    struct node *two=NULL;
    struct node *three=NULL;
    struct node *four=NULL;

    one=malloc(sizeof(struct node));
    two=malloc(sizeof(struct node));
    three=malloc(sizeof(struct node));
    four=malloc(sizeof(struct node));

    one->data=1;
    two->data=2;
    three->data=3;
    four->data=4;

    one->next=two;
    two->next=three;
    three->next=four;
    four->next=NULL;

    head=one;

    print_list(head);
}
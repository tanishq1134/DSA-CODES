#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct node {
    int data;
    struct node *next;
};

struct node *f=NULL;
struct node *r=NULL;


void enqueue(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    
    if (f == NULL && r == NULL) {
        f = new;
        r = new;
        return;
    }

    
    if (data <= f->data) {
        new->next = f;
        f = new;
        return;
    }

    
    struct node *temp = f;
    struct node *prev = NULL;

    while (temp != NULL && temp->data <= data) {
        prev = temp;
        temp = temp->next;
    }

    new->next = temp;
    prev->next = new;

    
    if (temp == NULL) {
        r = new;
    }
}


void dequeue(){
    struct node *temp1;
    if(f==NULL){
        printf("the queue id empty\n");
        return;
    }

    else if(f==r){
        temp1=f;
        f=NULL;
        r=NULL;
        free(temp1);
        return;
    }

    else{
        temp1=f;
        f=f->next;
        free(temp1);
    }
}

void display(){
    struct node *temp=f;

    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
}


int main () {

    

    enqueue(2);
    enqueue(10);
    enqueue(5);
    enqueue(7);
    enqueue(9);
    
    display();
    dequeue();
    dequeue();
    display();


    return 0;
}
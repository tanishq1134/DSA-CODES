#include<stdio.h>
#include<stdlib.h>

struct node {
    int coef;
    int exp;
    struct node *nxt;
};

struct node *p1= NULL;
struct node *p2= NULL;
struct node *p3= NULL;

void insert_p1(){
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the data of the new node:");
    scanf("%d", &(new->coef));
    scanf("%d", &(new->exp));
    new->nxt=NULL;

    if(p1==NULL){
        p1=new;
        return;
    }

    struct node *temp;
    temp=p1;
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }

    temp->nxt=new;

}
void insert_p2(){
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the data of the new node:");
    scanf("%d", &(new->coef));
    scanf("%d", &(new->exp));
    new->nxt=NULL;

    if(p2==NULL){
        p2=new;
        return;
    }

    struct node *temp;
    temp=p2;
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }

    temp->nxt=new;

}


void insert_p3(int coef1, int exp1){
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->coef=coef1;
    new->exp=exp1;
    new->nxt=NULL;

    if(p3==NULL){
        p3=new;
        return;
    }

    struct node *temp;
    temp=p3;
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }

    temp->nxt=new;
}


void addition(){

    struct node *temp1=p1;
    struct node *temp2=p2;

    
    while(temp1!=NULL && temp2!=NULL){
        int coef1;
        int exp1;
        if(temp1->exp>temp2->exp){
            exp1=temp1->exp;
            coef1=temp1->coef;
            temp1=temp1->nxt;
        }
        else if(temp1->exp<temp2->exp){
            exp1=temp2->exp;
            coef1=temp2->coef;
            temp2=temp2->nxt;
        }
        else{
            coef1= temp1->coef + temp2->coef;
            exp1=temp1->exp;
            temp1=temp1->nxt;
            temp2=temp2->nxt;
        }


        insert_p3(coef1,exp1);


    }

    while(temp1!=NULL){
        int coef1,exp1;
        exp1=temp1->exp;
            coef1=temp1->coef;
            temp1=temp1->nxt;
            insert_p3(coef1,exp1);
    }

    while(temp2!=NULL){
        int coef1,exp1;
        exp1=temp2->exp;
            coef1=temp2->coef;
            temp2=temp2->nxt;
            insert_p3(coef1,exp1);

    }

}

void display(){
    struct node *temp1=p1;
    while(temp1!=NULL){

        
        printf("%dk%d + ",temp1->coef,temp1->exp);
        temp1=temp1->nxt;
    }

    printf("\n");

    struct node *temp2=p2;
    while(temp2!=NULL){

        printf("%dk%d + ",temp2->coef,temp2->exp);
        temp2=temp2->nxt;
    }

    printf("\n\n");

    struct node *temp3=p3;
    while(temp3!=NULL){

        
        printf("%dk%d + ",temp3->coef,temp3->exp);
        temp3=temp3->nxt;
    }


}


int main (){

    int n1,n2;

    printf("enter the number of terms in both polynomials:\n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    printf("enter thee data of first polynomial:\n");
    for(int i=1;i<=n1;i++){
        insert_p1();
    }

    printf("\nenter thee data of first polynomial 2:\n");
    for(int i=1;i<=n2;i++){
        insert_p2();
    }
    printf("\n\n");
    addition();
    display();

}

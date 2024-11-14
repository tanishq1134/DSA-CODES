#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *head=NULL;

//to get height of node
int height(struct node *n){
    if (n==NULL){
        return 0;
    }
    return n->height;
}

//maximum number
int max(int a, int b){
    return (a>b)? a : b;
}

//for creating new node
struct node* newNode(int key){
    struct node *new=malloc(sizeof(struct node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return(new);
}

struct node *rightRotate(struct node *y){
    struct node *x=y->left;
    struct node *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height= max(height(y->left), height(y->right))+1;
    x->height= max(height(x->left),height(x->right))+1;

    return x;

}

struct node *leftRotate(struct node *x){

    struct node *y= x->right;
    struct node *t2= 
}





void main (){

}
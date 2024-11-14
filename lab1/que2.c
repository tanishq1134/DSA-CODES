#include <stdio.h>
#include <stdlib.h>


struct node {
    int coef;
    int exp;
    struct node *nxt;
};

struct node *poly = NULL; 


struct node* createNode(int coef, int exp) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->nxt = NULL;
    return newNode;
}


void appendSorted(int coef, int exp) {
    struct node *newNode = createNode(coef, exp);

   
    if (poly == NULL || poly->exp < exp) {
        newNode->nxt = poly;
        poly = newNode;
        return;
    }

    struct node *temp = poly;
    while (temp->nxt != NULL && temp->nxt->exp > exp) {
        temp = temp->nxt;
    }

    if (temp->nxt != NULL && temp->nxt->exp == exp) {
        temp->nxt->coef += coef;
        free(newNode);
        if (temp->nxt->coef == 0) {
            struct node *toDelete = temp->nxt;
            temp->nxt = temp->nxt->nxt;
            free(toDelete);
        }
    } else {
        newNode->nxt = temp->nxt;
        temp->nxt = newNode;
    }
}


void insertPolynomial() {
    int n;
    printf("Enter the number of terms in the polynomial:\n");
    scanf("%d", &n);
    printf("Enter the data of the polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        int coef, exp;
        scanf("%d %d", &coef, &exp);
        if (coef != 0) {
            appendSorted(coef, exp);
        }
    }
}


void display() {
    struct node *temp = poly;
    if (temp == NULL) {
        printf("The polynomial is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%dx^%d ", temp->coef, temp->exp);
        if (temp->nxt != NULL && temp->nxt->coef >= 0) {
            printf("+ ");
        }
        temp = temp->nxt;
    }
    printf("\n");
}


int main() {
    printf("Enter the data of the first polynomial:\n");
    insertPolynomial();

    printf("Enter the data of the second polynomial:\n");
    insertPolynomial();

    printf("The resulting polynomial is:\n");
    display();

   
    struct node *current;
    while (poly != NULL) {
        current = poly;
        poly = poly->nxt;
        free(current);
    }

    return 0;
}

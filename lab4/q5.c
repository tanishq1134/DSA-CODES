#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head, float coeff, int expo) {
    struct node* temp;
    struct node* newp = malloc(sizeof(struct node));
    newp->coeff = coeff;
    newp->expo = expo;
    newp->link = NULL;
    if (head == NULL || expo > head->expo) {
        newp->link = head;
        head = newp;
    } else if (expo == head->expo) {
        head->coeff += coeff;
        free(newp);
    } else {
        temp = head;
        while (temp->link != NULL && temp->link->expo > expo)
            temp = temp->link;


            
        if (temp->link != NULL && temp->link->expo == expo) {
            temp->link->coeff += coeff;
            free(newp);
        } else {
            newp->link = temp->link;
            temp->link = newp;
        }
    }
    return head;
}

struct node* create(struct node* head) {
    int n;
    float coeff;
    int expo;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

void print(struct node* head) {
    if (head == NULL)
        printf("No polynomial...\n");
    else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("%.1fX^%d", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

struct node* polymul(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* head3 = NULL;
    while (ptr1 != NULL) {
        struct node* ptr2 = head2;
        while (ptr2 != NULL) {
            float coeff = ptr1->coeff * ptr2->coeff;
            int expo = ptr1->expo + ptr2->expo;
            head3 = insert(head3, coeff, expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
    return head3;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    
    printf("Enter the polynomial A \n");
    head1 = create(head1);
    printf("Enter the polynomial B \n");
    head2 = create(head2);
    
    printf("Polynomial A: ");
    print(head1);
    printf("Polynomial B: ");
    print(head2);
    
    head3 = polymul(head1, head2);
    printf("The polynomial after multiplication: ");
    print(head3);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct node* insertAtEnd(struct node* head, int data) {
    struct node* newnode = createnode(data);
    if (head == NULL) {
        return newnode;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newnode = createnode(data);
    newnode->next = head;
    head = newnode;
    return head;
}
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
struct node* addNumbers(struct node* list1, struct node* list2) {
    struct node* list3 = NULL;
    int carry = 0;
    while (list1 != NULL || list2 != NULL || carry != 0) {
        int num1 = 0, num2 = 0;
        int sum = 0;
        if (list1 != NULL) {
            num1 = list1->data;
            list1 = list1->next;
        }
        if (list2 != NULL) {
            num2 = list2->data;
            list2 = list2->next;
        }
        sum = num1 + num2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        list3 = insertAtBeginning(list3, sum);
    }
    return list3;
}
struct node* convertToList(int num) {
    struct node* head = NULL;
    if (num == 0) {
        return createnode(0);
    }
    while (num > 0) {
        int digit = num % 10;
        head = insertAtEnd(head, digit);
        num /= 10;
    }
    return head;
}
int main() {

    int num1, num2;
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    struct node* list3 = NULL;

    printf("Num1: ");
    scanf("%d", &num1);
    printf("Num2: ");
    scanf("%d", &num2);
    
    list1 = convertToList(num1);
    list2 = convertToList(num2);
    list3 = addNumbers(list1, list2);
    printf("\nSum of given numbers: ");
    printList(list3);

    return 0;
}
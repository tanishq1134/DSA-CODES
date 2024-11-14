#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int digit;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the linked list
void insertAtHead(Node** head, int digit) {
    Node* newNode = createNode(digit);
    newNode->next = *head;
    *head = newNode;
}

// Function to add two numbers represented by linked lists
Node* add(Node* num1, Node* num2) {
    Node* result = NULL;
    int carry = 0, sum;

    while (num1 != NULL || num2 != NULL || carry > 0) {
        int digit1 = (num1 != NULL) ? num1->digit : 0;
        int digit2 = (num2 != NULL) ? num2->digit : 0;

        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        insertAtHead(&result, sum % 10);

        if (num1 != NULL) num1 = num1->next;
        if (num2 != NULL) num2 = num2->next;
    }

    return result;
}

// Function to multiply two numbers represented by linked lists
Node* multiply(Node* num1, Node* num2) {
    Node* result = NULL;
    Node *temp1 = num1, *temp2 = num2;
    int carry, product;

    for (int i = 0; temp2 != NULL; i++) {
        carry = 0;
        Node* currentResult = NULL;
        temp1 = num1;

        // Add zeros at the beginning for the current position
        for (int j = 0; j < i; j++) {
            insertAtHead(&currentResult, 0);
        }

        // Multiply the current digit of num2 with all digits of num1
        while (temp1 != NULL) {
            product = temp1->digit * temp2->digit + carry;
            carry = product / 10;
            insertAtHead(&currentResult, product % 10);
            temp1 = temp1->next;
        }

        // If there is any remaining carry, add it as a new node
        if (carry > 0) {
            insertAtHead(&currentResult, carry);
        }

        // Add current result to the total result
        result = add(result, currentResult);
        temp2 = temp2->next;
    }

    return result;
}

// Function to print the number stored in the linked list
void printNumber(Node* head) {
    if (head == NULL) return;
    printNumber(head->next);
    printf("%d", head->digit);
}

// Function to free the linked list memory
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* num1 = NULL;
    Node* num2 = NULL;

    // Example: Let's multiply 123 and 456
    insertAtHead(&num1, 6);
    insertAtHead(&num1, 5);
    insertAtHead(&num1, 4);
    insertAtHead(&num1, 5);
    insertAtHead(&num1, 6);

    
    insertAtHead(&num2, 3);
    insertAtHead(&num2, 5);
    insertAtHead(&num2, 6);

    Node* result = multiply(num1, num2);

    printf("Result: ");
    printNumber(result);
    printf("\n");

    // Free allocated memory
    freeList(num1);
    freeList(num2);
    freeList(result);

    return 0;
}

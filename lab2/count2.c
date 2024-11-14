#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void display(Node* head) {
    while (head != NULL) {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to get the length of the linked list
int getLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to perform counting sort on the linked list based on a specific digit
void countSort(int exp, Node** head) {
    int max = 0;
    Node* temp = *head;
    while (temp != NULL) {
        int digit = (temp->data / exp) % 10;
        if (digit > max) {
            max = digit;
        }
        temp = temp->next;
    }

    int* count = (int*)calloc(max + 1, sizeof(int));
    temp = *head;
    while (temp != NULL) {
        count[(temp->data / exp) % 10]++;
        temp = temp->next;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    Node** output = (Node**)malloc(getLength(*head) * sizeof(Node*));
    temp = *head;
    while (temp != NULL) {
        int index = (temp->data / exp) % 10;
        output[count[index] - 1] = temp;
        count[index]--;
        temp = temp->next;
    }

    temp = *head;
    for (int i = 0; i < getLength(*head); i++) {
        temp->data = output[i]->data;
        temp = temp->next;
    }

    free(count);
    free(output);

    if (max >= 10) { // Check if we need to process higher digits
        countSort(exp * 10, head);
    }
}

// Main function
int main() {
    int elements;
    printf("Enter the number of elements: ");
    scanf("%d", &elements);

    Node* head = NULL;

    printf("Enter each element one by one:\n");
    for (int i = 0; i < elements; i++) {
        int value;
        scanf("%d", &value);
        append(&head, value);
    }

    // Perform radix sort
    countSort(1, &head);

    printf("Sorted list:\n");
    display(head);

    // Free the linked list
    Node* current;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }

    return 0;
}

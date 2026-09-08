#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Iterative Reversal: O(n) Time, O(1) Space */
Node *reverseIterative(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Store next
        current->next = prev;  // Reverse pointer
        prev = current;        // Move prev forward
        current = next;        // Move current forward
    }
    return prev; // New head
}

/* Recursive Reversal: O(n) Time, O(n) Call Stack Space */
Node *reverseRecursive(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

void displayList(Node *head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    
    printf("=== Singly Linked List - Reversal ===\n\n");
    
    for (int i = 1; i <= 5; i++) {
        insertAtEnd(&head, i * 10);
    }
    
    printf("Original List:\n");
    displayList(head);
    
    printf("\n1. Reversing Iteratively:\n");
    head = reverseIterative(head);
    displayList(head);
    
    printf("\n2. Reversing Recursively (back to original order):\n");
    head = reverseRecursive(head);
    displayList(head);
    
    freeList(head);
    return 0;
}

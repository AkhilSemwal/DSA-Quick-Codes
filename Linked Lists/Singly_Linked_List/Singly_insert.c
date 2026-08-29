#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(Node **head, int data, int position) {
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    
    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node *head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    
    printf("=== Singly Linked List - Insertion ===\n");
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("After adding 10, 30, 40: ");
    display(head);
    
    insertAtBeginning(&head, 5);
    printf("After inserting 5 at beginning: ");
    display(head);
    
    insertAtPosition(&head, 20, 3);
    printf("After inserting 20 at position 3: ");
    display(head);
    
    return 0;
}

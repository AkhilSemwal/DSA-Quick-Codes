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

/* Iterative Search: O(n) */
int searchIterative(Node *head, int key) {
    int position = 1;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

/* Recursive Search: O(n) */
int searchRecursive(Node *head, int key, int position) {
    if (head == NULL) return -1;
    if (head->data == key) return position;
    return searchRecursive(head->next, key, position + 1);
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
    
    printf("=== Singly Linked List - Search ===\n\n");
    
    int data[] = {15, 28, 42, 67, 89, 104};
    for (int i = 0; i < 6; i++) {
        insertAtEnd(&head, data[i]);
    }
    displayList(head);
    
    int keysToSearch[] = {42, 104, 99};
    for (int i = 0; i < 3; i++) {
        int key = keysToSearch[i];
        int posIter = searchIterative(head, key);
        int posRec = searchRecursive(head, key, 1);
        
        printf("\nSearching for key %d:\n", key);
        if (posIter != -1) {
            printf("  - Iterative search: Found at position %d (1-indexed)\n", posIter);
            printf("  - Recursive search: Found at position %d\n", posRec);
        } else {
            printf("  - Element %d not found in list.\n", key);
        }
    }
    
    freeList(head);
    return 0;
}

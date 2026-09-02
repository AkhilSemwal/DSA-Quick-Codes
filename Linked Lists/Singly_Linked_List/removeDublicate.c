#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};

typedef struct Node SN;

SN *insert(SN *start)
{
    SN *newnode;
    newnode = (SN *)malloc(sizeof(SN));

    printf("Enter value: ");
    scanf("%d", &newnode->info);

    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        SN *temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    return start;
}

SN *remove_duplicate(SN *start)
{
    SN *P1;
    P1 = (SN *)malloc(sizeof(SN));

    if (start == NULL)
    {
        printf("Linked List is empty");
        return 0;
    }
    else
    {
        SN *P1 = start;

        while (P1->next != NULL)
        {
            SN *P2 = P1;
            P1 = P1->next;

            if (P1->info == P2->info)
            {
                P2->next = P1->next;
                P1 = P2;
            }
        }

        return start;
    }
}

int main()
{
    SN *start = NULL;
    SN *temp;
    int choice;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Remove Duplicate");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = insert(start);
            break;

        case 2:
            start = remove_duplicate(start);
            break;

        case 3:
            temp = start;

            while (temp != NULL)
            {
                printf("%d ", temp->info);
                temp = temp->next;
            }

            printf("\n");
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice");
        }
    }
}
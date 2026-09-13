#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int value) {
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD");
}

int main() {
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);
        insertEnd(value);
    }

    printf("\nCircular Linked List:\n");
    display();

    return 0;
}

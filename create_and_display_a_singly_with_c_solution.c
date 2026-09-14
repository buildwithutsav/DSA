#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        printf("Enter value: ");
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        }
        else {

            temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL) {

        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}
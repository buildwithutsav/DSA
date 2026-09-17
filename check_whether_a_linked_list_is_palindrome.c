#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value) {

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void checkPalindrome() {

    int arr[100];
    int n = 0;

    struct Node *temp = head;

    while(temp != NULL) {

        arr[n] = temp->data;
        n++;

        temp = temp->next;
    }

    int i = 0;
    int j = n - 1;

    while(i < j) {

        if(arr[i] != arr[j]) {

            printf("Not Palindrome\n");
            return;
        }

        i++;
        j--;
    }

    printf("Palindrome\n");
}

int main() {

    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(2);
    insertEnd(1);

    checkPalindrome();

    return 0;
}
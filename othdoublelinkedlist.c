#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        struct Node* last = (*head)->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    do {
        printf("Address: %p, Data: %d\n", current, current->data);
        current = current->next;
    } while (current != head);
}

void sortList(struct Node* head) {
    
}

int main() {
    struct Node* head = NULL;
    int N;
    printf("Masukkan jumlah data: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int data;
        printf("Masukkan data ke-%d: ", i + 1);
        scanf("%d", &data);
        addNode(&head, data);
    }

    printf("List sebelum pengurutan:\n");
    displayList(head);

    sortList(head);

    printf("List setelah pengurutan:\n");
    displayList(head);

    return 0;
}
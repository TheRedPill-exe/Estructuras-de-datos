#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *next;
};

void printLinkedList(struct node *head){
    struct node *current = head;
    while(current != NULL){
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}

struct node *insertInAscendentLinkedList(struct node *head, int n){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = n;
    newNode->next = NULL;

    if(head == NULL || newNode->key <= head->key){
        newNode->next = head;
        return newNode;
    }
    
    struct node *previous = head;
    struct node *current = head->next;
    
    while(current != NULL && n > current->key){
        previous = current;
        current = current->next;
    }

    newNode->next = current;
    previous->next = newNode;

    return head;
}

int main(){
    int n, operation;
    struct node *head = NULL;

    while(scanf("%d %d", &operation, &n) != EOF){
        if(operation == 1){
            head = insertInAscendentLinkedList(head, n);
            printLinkedList(head);
        }
    }

    return 0;
}

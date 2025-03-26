#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *next;
};

struct node *makeLinkedList(int n){
    struct node *head = NULL, *newNode;
    while(n >= 1){
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->key = n;
        newNode->next = head;
        head = newNode;
        n--;
    }
    return head;
}

void printLinkedList(struct node *head){
    struct node *current = head;
    while(current != NULL){
        printf("%d -> ", current->key);
        current = current->next;
    }
}

struct node *deleteLinkedList(struct node *head){
    struct node *current;
    while(head != NULL){
        current = head;
        head = head->next;
        free(current);
    }
    return head;
}

int main(){
    struct node *head;
    int n = 100;

    head = makeLinkedList(n);
    printLinkedList(head);
    head = deleteLinkedList(head);
    printLinkedList(head);
    
    printf("NULL \n");
    
    return 0;
}

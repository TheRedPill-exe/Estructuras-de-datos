#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define counterClockWise -1
#define ClockWise 1

struct node {
    struct node *prev;    
    int key;
    struct node *next;
};

struct node *InsertElementInCircularDoublyLinkedList(struct node *tail, int element) {
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node)); 
    newNode->key = element;
    
    if (tail == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else {
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next->prev = newNode;
        tail = newNode;
    }
    
    return tail;
}

struct node *DeleteFirstNodeOfCircularDoublyLinkedList(struct node *tail) {
    struct node *firstNode;
    
    if (tail == NULL)
        printf("The circular doubly linked list is empty.\n");
    else {
        if(tail == tail->next) {
            free(tail);
            tail = NULL;
        }
        else {
            firstNode = tail->next;
            tail->next = firstNode->next;
            firstNode->next->prev = tail;
            free(firstNode);
        }
    }
    
    return tail;
}

int solver(int size, int jump) {
    struct node *tail = NULL, *current, *turn;
    int direction = ClockWise, winner;
    int i;  // variable for loops

    // Create circular doubly linked list from 1 to size.
    for (i = 1; i <= size; i++)
        tail = InsertElementInCircularDoublyLinkedList(tail, i);
        
    // Initialize current pointer to the first element.
    current = tail->next;

    // Process elimination until only one node remains.
    while (size > 1) {
        if (direction == ClockWise) {
            for (i = 1; i < jump; i++)
                current = current->next;
            
            // Save the next node where we'll continue.
            turn = current->next;

            // Remove the current node from the list.
            current->prev->next = current->next;
            current->next->prev = current->prev;
            // Update tail if needed.
            if (current == tail)
                tail = current->prev;
            free(current);

            // Continue from the next node.
            current = turn;
            direction = counterClockWise;
        }
        else { // direction == counterClockWise
            for (i = 1; i < jump; i++)
                current = current->prev;
            
            // Save the previous node for next iteration.
            turn = current->prev;

            // Remove the current node from the list.
            current->prev->next = current->next;
            current->next->prev = current->prev;
            // Update tail if needed.
            if (current == tail)
                tail = current->next;
            free(current);

            // Continue from the previous node.
            current = turn;
            direction = ClockWise;
        }
        size--;      
    }
    
    winner = tail->key;
    free(tail);    
    return winner;
}

int main() {
    int n, k;
    
    while (scanf("%d %d", &n, &k) && (n > 0) && (k > 0)) {        
        printf("%d\n", solver(n, k));
    }
        
    return 0;
}

#include <stdio.h>
#define size 10
int queue[size];
int front = -1, rear = -1; // Initialize front and rear to -1

int isFull() {
    if ((rear + 1) % size == front) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (front == -1 && rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(int val) {
    if (isFull()) {
        printf("Sorry, cannot enqueue as the queue is full\n");
    } else {
        if (isEmpty()) {
            front = 0; // If the queue is empty, update front to 0
        }
        rear = (rear + 1) % size;
        queue[rear] = val;
        printf("Successfully enqueued!\n");
    }
}

int dequeue() {
    int val;
    if (isEmpty()) {
        printf("Cannot dequeue as the queue is empty\n");
        // return some default or error value
        return -1;
    } else if (front == rear) {
        val = queue[front];
        front = rear = -1; // Reset front and rear when the queue becomes empty
    } else {
        val = queue[front];
        front = (front + 1) % size;
    }
    return val;
}

int main() {
    enqueue(45);
    enqueue(5);
    enqueue(565);
    enqueue(78);
    enqueue(45);
    enqueue(5);

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());

    return 0;
}


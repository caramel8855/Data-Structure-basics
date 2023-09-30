#include<stdio.h>
#include <stdlib.h>

//declare global variables
int queue[10]; 
int front=-1, rear=-1;

int isfull(){
    if(rear == 9){
        return 1;
    }else{
        return 0;
    }
}

int isempty(){
    if(front ==-1 && rear==-1){
        return 1;
    }
    else {
        return 0;
    }
}

//function for enqueue
void enqueue(int val){
    if(isfull()){
        printf("Cannot enqueue as its full.\n");
    }
    if(isempty()){
        front = rear = 0;
    } else{
        rear++;
    }
    queue[rear] = val;
    printf("Enqueued\n");
}
//function for dequeue
int dequeue (){
    int val;
    if(isempty()){
        printf("Cannot dequeue cz queue is empty\n");
    }
    else if(front==rear){
        val = queue[front];
        front = rear = -1;
    } else {
        val = queue[front];
        front++;
    }
    return val;
}

int main(){
    enqueue(34);
    enqueue(45);
    enqueue(29);
    enqueue(30);

    printf("%d", dequeue());

return 0;
}
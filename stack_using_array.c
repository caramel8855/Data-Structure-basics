#include <stdio.h>
#include <stdlib.h>

int stack[10], top = -1; //declare a global variable 

int isFull(){
if(top ==9){
    return 1;
}
else {
    return 0;
}
}

int isEmpty(){
    if(top ==-1){
        return 1;
    }
    else{
        return 0;
    }

}

void push (int val){
if(isFull()){
    printf("Stack is full\n");
}
else{
    top = top+1;
    stack[top] = val;
}
}

int pop (){
    int val;
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else {
        val = stack[top];
        top = top-1;
        return val;
    }

}

int peek (){
    int val;
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else {
        val = stack[top];

        return val;
    }

}
int main (){
    push(34);
    push(45);
    push(67);
    push(23);
    push(31);
   

    printf("%d", pop());

return 0;
}

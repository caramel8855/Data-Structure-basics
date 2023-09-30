
#include <stdio.h>
#include <stdlib.h>

//structure creation
struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;

//traverse the stack 
void Traversal(struct node *tp){
    while (tp!=NULL){
    printf("%d\n", tp->data);
    tp = tp->link;
   }
}

// Function to check if the stack is Empty. Returns a boolean value
int isEmpty(struct node *tp){
    if(tp==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

//This isFull part is unnecessary cz linked list stack wont  
//be overflow untill hip memory fails to allocate memory.
int isFull(){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p ==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

struct node *push (struct node *tp, int x){
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->data = x;
    q->link = tp;
    tp = q;
    return tp;
}



int pop (struct node *tp){
    struct node *p = tp;
    top = top->link;
    int x = p ->data;
    free(p);
    return x;
}

int peek(struct node *tp){
    return top->data;
    }


int main (){
    top  = push(top, 45);
    top  = push(top, 564);
    top  = push(top, 34);
    top  = push(top, 213);

   if(isEmpty(top)){
    printf("The stack is Empty bitch, Push something first");
   }
   else{
   printf("Nice stack man. I can peek, the top is %d\n", peek(top));
   }
   Traversal(top);
  printf("%d\n", pop(top));
   printf("%d\n", pop(top));
    printf("%d", pop(top));



   
}
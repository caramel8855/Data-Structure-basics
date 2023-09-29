#include <stdio.h>
#include <stdlib.h>

//create a struct 
struct node{
    int data;
    struct node *link;
};

int main(){
    //declare pointers of struct node
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;

    //allocate the memories
    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));

    //start creating and linking 
    head->data = 7;
    head->link = second;
    second->data = 73;
    second->link = third;
    third->data = 45;
    third->link = forth;
    forth->data = 67;
    forth->link = NULL;   

    return 0;
}

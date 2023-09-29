#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;
 
    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));
   
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

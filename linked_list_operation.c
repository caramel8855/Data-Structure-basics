#include<stdio.h>
#include <stdlib.h>

//struct node
struct node {
int data;
struct node *link;
};

//function for traversal
void traversal (struct node *ptr){
while (ptr!=NULL){
printf("Element : %d\n",ptr->data);
ptr = ptr->link;
} 
}

//function for insert at first 
struct node *insertatfirst(struct node *ptr, int data){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->link= ptr;
    head->data = data;
return head;
}

//function for insert at index
struct node *insertatindex(struct node *head, int data, int index){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int  i =0 ;
   
    while (i != index -1){
        p = p->link;
        i++;
    }
    new->link = p->link; 
    new->data = data;
    p->link = new;
    return head;
};

//function to insert at end 
struct node *insertend(struct node *head, int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *p  =  head;

    while (p->link != NULL){
        p = p->link;
    }
    p->link = new;
    new->data = data;
    new->link = NULL;
    return head;
}

//function to delete first node
struct node *deleteatfirst(struct node *head){
    struct node *ptr = head;
    head = head->link;
    free(ptr);
    return head;
}

//function for deleting at specific index
struct node *deleteatindex(struct node *head, int index){
struct node *p = head;
int i =0 ;
while(i != index-1){
    p = p->link;
    i++;
}

struct node *q = p->link;
p->link = q->link;
free(q);
return head;
}

//function to delete last element 
struct node *deletelast(struct node *head){
    struct node *p = head;
    struct node *q = head->link;

    while(q->link != NULL){
        p = p->link;
        q = q->link;
    }
    p->link = NULL;
    free(q);
    return head;
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
 
    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));
   
    head->data = 7;
    head->link = second;
    second->data = 73;
    second->link = third;
    third->data = 45;
    third->link = NULL;   

traversal(head);

//now just call the functions to do operations , one is done.
head = deleteatindex(head, 2);
printf("After deletion at given index: \n");
traversal(head);

}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *first, *previous;
    int i, n;
    printf("Enter the number the elements: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        head = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &head->data);
        head->next = NULL;

        if (i == 0)
        {
            first = head;
            previous = head;
        }
        else
        {
            previous->next = head;
            previous = head;
        }
    }

    //creating an additional pointer to hold the first node
    struct node *h1 = first; 

    //displaying the elements(traversal of a linkedlist)
    printf("Displaying elements:\n");
    while(h1!=NULL){
        printf("%d\n", h1->data);
        h1 = h1->next;
    }

    return 0 ;
}

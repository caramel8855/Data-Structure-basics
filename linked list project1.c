#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char item[20];
    int price;
    struct node *link;
};

void removeitem(struct node **head, char *itemname)
{
    struct node *current = *head;
    struct node *previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->item, itemname) == 0)
        {
            if (previous == NULL) {
                *head = current->link;
            }
            else {
                previous->link = current->link;
            }
            free(current);
            printf("Item \"%s\" removed from the basket.\n", itemname);
            return;
        }

        previous = current;
        current = current->link;
    }

    printf("Item \"%s\" was not found in the basket!\n", itemname);
}


int main()
{
    int choice, created = 0;
    do
    {
        printf("___________________________\n");
        printf("\n1.Add an item\n2.Remove an item\n3.Display items\n4.Exit the programme\nEnter your choice:\n");
        printf("___________________________\n");

        scanf("%d", &choice);

        struct node *first, *previous, *head;

        if (choice == 1)
        {
            int n, i;
            printf("how many items to add?");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                head = (struct node *)malloc(sizeof(struct node));

                printf("Item %d name : ", i);
                scanf("%s", head->item);
                printf("Item %d price : ", i);
                scanf("%d", &head->price);
                head->link = NULL;

                if (i == 1)
                {
                    first = head;
                    previous = head;
                }
                else
                {
                    previous->link = head;
                    previous = head;
                }
                printf("!Item added to basket!\n");
            }
            created = 1;
        }

        else if (choice == 2)
        {
            struct node *h2 = first;
            if (created != 1)
            {
                printf("Basket is Empty");
            }
            else
            {
                char itemname[20];
                printf("Type item name that u want to remove: \n");
                scanf("%s", itemname);
                removeitem(&first, itemname);
            }
        }

        else if (choice == 3)
        {
            struct node *h1 = first;
            if (created != 1)
            {
                printf("Basket is Empty\n");
            }
            else
            {
                printf("--Shopping basket menu--\n");
                int j = 1;
                while (h1 != NULL)
                {
                    printf("Item %d : %s\n Price : %d\n", j, h1->item, h1->price);
                    h1 = h1->link;
                    j++;
                }
            }
        }
    } while (choice != 4);

    if(choice ==4){
        printf("Programme closed successfully\n");
    }
}

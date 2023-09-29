#include <stdio.h>
#include <stdlib.h>


//creating code for linked list by user input 
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
    // pointing the first node of linked list with different pointers
    struct node *h1 = first;
    struct node *h2 = first;
    struct node *h3 = first;
    struct node *h4 = first;
    struct node *h5 = first;
    struct node *h6 = first;

    // question 1. code for sum of all elemnts (used h1)
    int sum = 0;
    while (h1 != NULL)
    {
        sum = sum + h1->data;
        h1 = h1->next;
    }
    printf("The sum of the elements are  : %d\n", sum);

    // 2.count the numbers of Even and odd elements (used h2)
    int even = 0, odd = 0;
    while (h2 != NULL)
    {
        if ((h2->data) % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
        h2 = h2->next;
    }
    printf("The number of even numbers in the list is : %d\n", even);
    printf("The number of odd numbers in the list is : %d\n", odd);

    // 3and4 . find the largest element (used h3)
    int largest = h3->data, smallest = h3->data;
    while (h3 != NULL)
    {
        if (h3->data > largest)
        {
            largest = h3->data;
        }
        else if (h3->data < smallest)
        {
            smallest = h3->data;
        }
        h3 = h3->next;
    }
    printf("The largest element is %d and smallest is %d\n", largest, smallest);

    // 5.average of all elements(used h4)
    int sumforavg = 0, average;
    while (h4 != NULL)
    {
        sumforavg = sumforavg + h4->data;
        h4 = h4->next;
    }
    average = sumforavg / n;
    printf("The average of all elements in the linked list is %d\n", average);

    // 6.find second largest (used h5)
    int lar = h5->data;
    int secondlargest;
    while (h5 != NULL)
    {
        if (h5->data > lar)
        {
            secondlargest = lar;
            lar = h5->data;
        }
        else if (h5->data > secondlargest && h5->data != lar)
        {
            secondlargest = h5->data;
        }
        h5 = h5->next;
    }
    printf("The second largest element of the linked list is %d\n", secondlargest);

    // 7.find second smallest
    int sma = h6->data;
    int secondsmallest;
    while (h6 != NULL)
    {
        if (h6->data < sma)
        {
            secondsmallest = sma;
            sma = h6->data;
        }
        else if (h6->data < secondsmallest && h6->data != smallest)
        {
            secondsmallest = h6->data;
        }
        h6 = h6->next;
    }
    printf("The second smallest element of this linkd list is %d\n", secondsmallest);

    return 0;
}
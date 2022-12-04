#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int x)
{
    struct node *new1;
    new1 = (struct node *)malloc(sizeof(struct node));
    new1->data = x;
    if (top == NULL)
    {
        new1->next = NULL;
    }
    else
    {
        new1->next = top;
        top = new1;
        printf("Node inserted successfully\n");
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct node *temp;
        temp = top;
        top = top->next;
        free(temp);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("The stack is \n");
        struct node *temp = top;
        while (temp->next == NULL)
        {
            printf("The elements are %d", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int x, choice;
    printf("\nImplementation of Stack using Linked List\n");
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value you want to insert: ");
            scanf("%d", &x);
            push(x);
            printf("\nElement inserted \n\n");
            break;
        case 2:
            pop();
            printf("\nThe element is poped.\n");
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}

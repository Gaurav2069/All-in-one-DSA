#include <stdio.h>

#define size 50

int front = -1, rear = -1;
int arr[size];

void insert()
{
    int x;
    printf("Enter the element you want to insert\n");
    scanf("%d", &x);
    if (rear == size - 1)
    {
        printf("\nOverflow\n");
    }

    else
    {

        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
    }
    arr[rear] = x;
    printf("\nElement inserted ");
}

void delete ()
{
    if(front==-1 && rear==-1){
        printf("\nUnderflow\n");
    }
    else{
        if(rear==front){
            rear=-1;
            front=-1;
        }
        else{
            front=front+1;
        }
    }
     printf("\nValue deleted ");  
}

void display(){
    if(rear==-1 && front==-1){
        printf("\nEmpty Queue\n");
    }
    else{
         printf("\nThe values of queue are:\n");
         for(int i=front;i<=rear;i++){
            printf("\n%d\n",arr[i]);
         }
    }
}
int main(){
    
    while(1){
        int choice;
		printf("\nOperations performed by Stack");
		printf("\n1.Insert the element\n2.Delete the element\n3.Display\n4.End");
		printf("\n\nEnter the choice:");
		scanf("%d", &choice);

        switch (choice)
		{
		case 1:
			insert();
			break;
		case 2:
			delete();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);

		default:
			printf("\nInvalid choice!!");
		}
    }

    return 0;
}
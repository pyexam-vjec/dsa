#include <stdio.h>
int queue[50],rear=-1,front=-1,size;
void enqueue()
{
    int item;
    if(rear == size-1)
        printf("Queue Overflow \n");
    else
    {
        printf("Input element in queue : ");
        scanf("%d", &item);
        if(front==-1 && rear==-1)
        {
            front = 0;
            rear=0;
        }
        else
            rear=rear+1;
        queue[rear]=item;
    }
}

void dequeue()
{
    if (front==-1)
        printf("Queue Underflow \n");
    else
    {
        printf("Element deleted from queue is : %d\n", queue[front]);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
            front=front+1;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

void main()
{
    int choice;
    printf("Enter the size of Queue\n");
    scanf("%d",&size);
    do
    {
        printf("1.Insert element to queue \n2.Delete element from queue \n3.Display all elements of queue \n4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXITED ");
                break;
            default:
                printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
    }
    while(choice!=4);
}

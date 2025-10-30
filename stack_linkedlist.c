#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};

struct node*top=NULL;
struct node*new;
struct node*temp;
struct node*ptr;
int item;

void push()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nENTER THE ITEM TO BE PUSHED\n");
    scanf("%d",&item);
    new->data=item;
    new->link=NULL;

    if(top==NULL)
    {
        top=new;
    }
    else
    {
        new->link=top;
        top=new;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("\nDELETION NOT POSSIBLE\n");
    }
    else
    {
        temp=top;
        printf("\nDELETED ITEM IS: %d \n",top->data);
        top=top->link;
        free(temp);
    }
}

void display()
{
    if(top==NULL)
    {
        printf("\nSTACK IS EMPTY\n");
    }
    else
    {
        ptr=top;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
    }
}

void main()
{
    int ch;
    do
    {
        printf("\nENTER YOUR CHOICE \n1:PUSH()\n2:POP()\n3:DISPLAY()\n4:EXIT\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                push();
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nEXITING FROM STACK\n");
                break;
            default:
                printf("\nPLEASE ENTER YOUR CHOICE BETWEEN 1 AND 4\n");
                break;
        }
    }while(ch!=4);
}

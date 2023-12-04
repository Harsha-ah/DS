#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX 5

int queue [MAX];
int front=-1;
int rear=-1;

bool isFull()
{
    if(rear==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isEmpty()
{
    if(rear==-1 || front==MAX-1 || rear==front)
    {
        return 1;
    }
    else {
        return 0;
    }
}

bool isEnd()
{
    if(isFull())
    {
        if(front==rear)
        {
            return 1;
        }
    }
    return 0;
}

void reset()
{
    front=-1;
    rear=-1;
}

void enqueue()
{
    int value;
    printf("enter the number:");
    scanf("%d",&value);
    if(isEnd())
    {
        reset();
        reset=rear+1; 
        queue[rear]=value;
    }
    else if (isFull())
    {
        printf("queue is full\n");
    }
    else
    {
        rear=rear+1;
        queue[rear]=value;
    }
    
}

void dequeue()
{
    int=i;
    if(isEmpty())
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("%d is dequeue \n",queue[front+1]);
        front=front+1;
    }
}

void display()
{
    int i;
    if(isEmpty())
    {
        printf("queue is empty\n");
    }
    else
    {
        for(i=front+1;i<=rear;i++)
        {
            printf("queue [%d]is:%d\n",i+1,queue[i]);
        }
    }
}

int main()
{
    int opt;
    do
    {
        printf("\n.........\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("\n......\n");
        printf("choose your option:");
        scanf("%d",&opt);
        switch(opt)
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
                 printf("exiting...\n");
                 break;
            default :
                 printf("invalid option...\n");
        }
    }
    while(opt!=4);
    return 0;
}
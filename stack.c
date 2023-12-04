#include<stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top=-1;
void push (int value)
{
    if(top>=MAX_SIZE-1)
    {
        printf("stack overflow");
    }
    else
    {
        stack[++top]=value;
        printf("%d pushed into stack \n",value);
    }
}
void pop()
{
    if(top<0)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("%d poped \n",stack[top--]);
    }
}
int peek()
{
    if (top<0)
    {
        printf("stack empty\n");
        return -1;
    }
    else{
        return stack[top];
    }
}
void display()
{
    if(top<0)
    {
        printf("stack empty\n");
    }
    else{
        printf("stack elements:");
        for (int i=0;i<=top;i++)
        {
            printf("%d",stack[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice,value;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter value to push:");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                 pop();
                 break;
            case 3:
                 value=peek();
                 if(value!=-1)
                 {
                     printf("top of stack:%d \n",value);
                     
                 }
                 break;
            case 4:
                 display();
                 break;
            case 5:
                 printf("existing the program\n");
                 return 0;
            default :
                 printf("invalid choice \n");
        }
    }
    return 0;
}
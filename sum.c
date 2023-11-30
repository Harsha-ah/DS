#include<stdio.h>
int main()
{
    int a,b;
    printf("\n enter two numbers:");
    scanf("%d%d",&a,&b);
    add(a,b);
    return 0;
}
void add(int a,int b)
{
    int c;
    c=a+b;
    printf("the sum:%d",c);
}
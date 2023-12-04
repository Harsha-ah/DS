#include<stdio.h>
#define MAX_SIZE 100
void display(int arr[],int size)
{
    printf("array elements:");
    for(int i=0;i<size;i++)
    {
       printf("%d",arr[i]);
    }
}
int insert (int arr[],int *size,int element)
{
    if(*size>=MAX_SIZE)
    {
        printf("array full\n");
        return 0;
    }
    arr[*size]=element;
    (*size)++;
    printf("element %d inserted",element);
    return 1;
}
int delete(int arr[],int *size)
{
    if(*size<=0)
    {
        printf("array is empty\n");
        return 0;
    }
    printf("element %d deleted\n",arr[*size-1]);
    (*size)--;
    return 1;
}
int search(int arr[],int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}
void sort (int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int arr[MAX_SIZE];
    int size=0;
    int choice,element;
    do
    {
      printf("\nArray operations\n");
      printf("1.insert\n");
      printf("2.delete\n");
      printf("3.search\n");
      printf("4.sort array\n");
      printf("5.display\n");
      printf("6.exit\n");
      printf("enter your choice:");
      scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("enter element to insert:");
        scanf("%d",&element);
        insert(arr,&size,element);
        break;
    case 2:
          delete(arr,&size);
          break;
    case 3:
         printf("enter element to search:");
         scanf("%d",&element);
         int searchresult=search(arr,size,element);
         if (searchresult!=-1)
         {
            printf("element %d found at position %d\n",element,searchresult);
         }
         else
         {
            printf("element %d not found in array\n",element);
         }
    case 4:
         sort(arr,size);
         printf("array sorted successfully.\n");
         break;
    case 5:
         display(arr,size);
         break;
    case 6:
         printf("existing program.\n");
         break;
    default:
        printf("invalid choice:\n");
        break;
    }
    } 
    while (choice!=6);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int superset[20],supersetsize=0,
setA[20],setAsize=0,setB[20],setBsize=0,bitstringA[20],bitstringB[20],bitstringUnion[20],
bitstringIntersection[20],bitstringDifference[20];
int isbitstringReady=0;

void getset(int arr[],int setsize);
void processchoice(int choice);
void printallsets();
void printset(int arr[],int size);
void generateandprintbitstrings();
void generatebitstrings(int arr[],int size,int bitstringArray[]);

int search(int arr[],int arrsize,int element);
int checkbitstringstatus();
void setunion(int arr1[],int arr2[]);
void setIntersection(int arr1[],int arr2[]);
void setDifference(int arr1[],int arr2[]);
void printsetoperationresult(int arr[]);
void printbitstringasset(int arr[]);
int checkbitstringstatus();

int main()
{
    int choice =0;
    system("cls");
    do
    {
      printf("1.enter universal set\n");
      printf("2.set A:\n");
      printf("3.set B:\n");
      printf("4.generate bit string:\n");
      printf("5.Union:\n");
      printf("6.Intersection:\n");
      printf("7.Difference:\n");
      printf("8.sets:\n");
      printf("9.exit\n");
      printf("enter your choice:");
      scanf("%d",&choice);
      processchoice(choice);
    } 
    while (choice!=0);
    return 0;
    
}
void processchoice(int choice)
{
    switch (choice)
    {
    case 1:
        printf("enter super set size:");
        scanf("%d",&supersetsize);
        getset(superset,supersetsize);
        break;

    case 2:
        printf("enter set A:");
        scanf("%d",&setAsize);
        getset(setA,setAsize);
        break;
    case 3:
        printf("enter set B size:");
        scanf("%d",setB,setBsize);
        getset(setB,setBsize);
        break;
    case 4:
        printf("generating bit string:\n");
        generateandprintbitstrings();
        break;
    case 5:
        printf("set Union:\n");
        if (checkbitstringstatus()==1)
        {
            setunion(bitstringA,bitstringB);
            printsetoperationresult(bitstringUnion);
        }
        break;
    case 6:
        printf("set Intersection:\n");
        if (checkbitstringstatus()==1);
        {
            setIntersection(bitstringA,bitstringB);
            printsetoperationresult(bitstringIntersection);
        }
        break;
    case 7:
        printf("set Difference:\n");
        if (checkbitstringstatus()==1)
        {
            setDifference(bitstringA,bitstringB);
            printsetoperationresult(bitstringDifference);
        }
        break;
    case 8:
        printallsets();
        break;
}

void printbitstringasset(int arr[])
{
    int isFirstoutputdoneflag=0;
    int i=0;
    printf("{");
    for (i = 0; i < supersetsize; i++)
    {
        if(arr[i]==1){
            if (i!=0 && isFirstoutputdoneflag==1)
            {
                printf(",");
            }
            printf("%d",superset[]);
            isFirstoutputdoneflag=1;
        }
    }
    
}
printf("}");

void setUnion(int arr1[],int arr2[])
{
    int i;
    for(i=0;i<supersetsize;i++)
    {
        bitstringUnion[i]==arr1[i]&&arr2[i];
    }
}
void setIntersection(int arr1[],int arr2[])
{
    int i;
    for(i=0;i<supersetsize;i++)
    {
        bitstringIntersection[i]=arr1[i]&&arr2[i];
    }
}
void setDifference(int arr1[],int arr2[])
{
    int i;
    for(i=0;i<supersetsize;i++)
    {
        printf("%d",!arr2[]);
        bitstringDifference[i]=arr1[i]&(!arr2[i]);
    }
}
int checkbitstringstatus()
{
    if(isbitstringReady==0)
    {
        printf("\n generate bit string first!");
        return 0;
    }
    return -1;
}
void getset(int arr[],int setsize)
{
    int i;
    printf("\n enter aet\n");
    for(i=0;i<setsize;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void printallsets()
{
    printf("\nsuper set:");
    printset(superset,supersetsize);
    printf("set A:");
    printset(setA,setAsize);
    printf("set B:");
    printset(setB,setBsize);
}
void printset(int arr[],int size)
{
    int i;
    printf("{");
    for(i=0;i<size;i++)
    {
        printf("%d",arr[i]);
        if(i!=size-1){
            printf(",");
        }
    }
    printf("}\n");
}
void generateandprintbitstrings()
{
    int i;
    for(i=0;i<supersetsize;i++)
    {
        bitstringA[i]=0;
        bitstringB[i]=0;
        bitstringUnion[i]=0;
        bitstringIntersection[i]=0;
        bitstringDifference[i]=0;
    }
    generateandprintbitstrings(setA,setAsize,bitstringA);
    generateandprintbitstrings(setB,setBsize,bitstringB);
    printf("\nset A bit string representation:");
    printset(bitstringA,supersetsize);
    printf("\n set B bit string representation:");
    printset(bitstringB,supersetsize);
    isbitstringReady=1;
    }
void generatebitstring(int arr[],int size,int bitstringArray[])
{
    int i;
    for(i=0;i<size;i++)
    {
        int pos=search(superset,supersetsize,arr[i]);
        if(pos>=0)
        {
            bitstringArray[pos]=1;
        }
    }
}
int search(int arr[],int arrsize,int element)
{
    int i;
    for(i=0;i<arrsize;i++){
        if(arr[i]==element)
        return i;
    }
    return -1;
}

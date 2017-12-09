#include<stdio.h>
void search(int a[],int num, int f,int l)
{
    if(f>l)
    {
        printf("number not found\n");
        return;
    }
    int mid;
    mid=(f+l)/2;
    if(num==a[mid])
        printf("number found at %d",mid+1);
    else if(num>a[mid])
        search(a,num,mid+1,l);
    else if(num<a[mid])
        search(a,num,f,mid-1);
}
void main()
{
    int n=0;
    printf("enter size of array\n");
    scanf("%d",&n);
    int a[n];
    int f=0,l=n-1,i=0,num;
    printf("enter elements of array in ascending order\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter number to search\n");
    scanf("%d",&num);
    search(a,num,f,l);
    return;
}

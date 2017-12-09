#include<stdio.h>
#define size 10
int f=-1,r=-1;
int q[size];
int count=0;
void insert(int item)
{
	if(count==size)
	{
		printf("CQ overflow\n");
		return;
	}
	if(count==0)
		f=r=0;
	else
		r=(r+1)%size;
	q[r]=item;
	count++;		
	return;
}
void delete()
{
	if(count==0)
	{
		printf("CQ underflow\n");
		return;
	}
	printf("Deleted item is %d\n",q[f]);
	if(f==r)
		f=r=-1;
	else
		f=(f+1)%size;
	count--;
	return;
}
void display()
{
	if(count==0)
	{
		printf("CQ empty\n");
		return;
	}
	int i=f,temp=count;
	for(i=f;temp!=0;i++)
	{
		printf("%d\t",q[i]);
		temp--;
	}
	printf("\n");
	return;
}
void main()
{
	int ch,item;
	for(;;)
	{
		printf("menu\n1.insert\n2.delete\n3.display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter item\n");
				scanf("%d",&item);
				insert(item);
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: return;
			default: printf("invalid choice\n");		
		}
	}
}


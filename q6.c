#include<stdio.h>
#define size 10
int f=-1,r=-1;
int q[size];
void insert(int item)
{
	if(r==size-1)
	{
		printf("LQ overflow\n");
		return;
	}
	if(f==-1)
		f++;
	q[++r]=item;		
	return;
}
void delete()
{
	if(f==-1)
	{
		printf("LQ underflow\n");
		return;
	}
	printf("Deleted item is %d\n",q[f]);
	if(f==r)
		f=r=-1;
	else
		f++;
	return;
}
void display()
{
	if(f==-1)
	{
		printf("LQ empty\n");
		return;
	}
	int i=f;
	for(i=f;i<=r;i++)
	{
		printf("%d\t",q[i]);
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


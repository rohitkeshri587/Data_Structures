#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node* link;
}node;
node* last=NULL;
void insert_beg(int item)
{
	node* nn=(node*)malloc(sizeof(node));
	nn->info=item;
	if(last==NULL)
	{
		last=nn;
		last->link=last;
		printf("Node Inserted\n");
		return;
	}
	nn->link=last->link;
	last->link=nn;
	printf("Node Inserted\n");
	return;
}
void del_beg()
{
	if(last==NULL)
	{
		printf("Stack Underflow\n");
		return;
	}
	if(last->link==last)
	{
		printf("Deleted Node is %d\n",last->info);
		free(last);
		last=NULL;
		return;
	}
	node* temp=last->link;
	last->link=temp->link;
	printf("Deleted Node is %d\n",temp->info);
	free(temp);
	return;
}		
void display()
{
	if(last==NULL)
	{
		printf("Stack Empty\n");
		return;
	}
	node* temp=last->link;
	while(temp!=last)
	{
		printf("%d\t",temp->info);
		temp=temp->link;
	}
	printf("%d\n",temp->info);
	return;
}
void main()
{
	int ch,item,pos;
	for(;;)
	{
		printf("menu\n1.push\n2.pop\n3.display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter Item\n");
				scanf("%d",&item);
				insert_beg(item);
				break;
			}
			case 2:
			{
				del_beg();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			case 4: return;
			default : printf("invalid choice\n");
		}
	}
}

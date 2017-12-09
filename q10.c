#include<stdio.h>
typedef struct node
{
	int info;
	struct node* link;
}node;
node* last=NULL;
void insert_pos(int item, int pos)
{
	node* nn=(node*)malloc(sizeof(node));
	nn->info=item;
	if(last==NULL)
	{
		if(pos==1)
		{
			last=nn;
			last->link=last;
			printf("Node Inserted\n");
			return;
		}
		printf("Invalid Position\n");
		return;
	}
	if(pos==1)
	{
		nn->link=last->link;
		last->link=nn;
		printf("Node Inserted\n");
		return;
	}
	node* temp= last->link;
	int c=1;
	while(temp!=last)
	{
		if(c+1==pos)
		{
			nn->link=temp->link;
			temp->link=nn;
			printf("Node Inserted\n");
			return;
		}
		temp=temp->link;
		c++;
	}
	if(c+1==pos)
	{
		nn->link=last->link;
		last->link=nn;
		last=nn;
		printf("Node Inserted\n");
		return;
	}
	printf("Invalid Position\n");	
	return;
}
void del_end()
{
	if(last==NULL)
	{
		printf("CLL Underflow\n");
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
	while(temp->link!=last)
	{	
		temp=temp->link;
	}
	printf("Deleted Node is %d\n",temp->link->info);
	temp->link=last->link;
	free(last);
	last=temp;
	return;
}
void display()
{
	if(last==NULL)
	{
		printf("CLL Empty\n");
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
		printf("menu\n1.insert at pos\n2.del from end\n3.display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter Item\n");
				scanf("%d",&item);
				printf("Enter Position\n");
				scanf("%d",&pos);
				insert_pos(item,pos);
				break;
			}
			case 2:
			{
				del_end();
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

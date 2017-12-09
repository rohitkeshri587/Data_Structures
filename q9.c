#include<stdio.h>
typedef struct node
{
	int info;
	struct node* link;
}node;
node * start=NULL;
void insert_pos(int item, int pos)
{
	node* nn=(node*)malloc(sizeof(node));
	nn->info=item;
	if(pos==1)
	{
		if(start==NULL)
		{
			start=nn;
			start->link=NULL;
			printf("Node Inserted\n");
			return;
		}
		nn->link=start;
		start=nn;
		printf("Node Inserted\n");
		return;
	}
	node* temp=start;
	int c=1;
	while(temp!=NULL)
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
	printf("Invalid Position\n");
}
void del_end()
{
	if(start==NULL)
	{
		printf("SLL Underflow\n");
		return;
	}
	if(start->link==NULL)
	{
		printf("Deleted Node is %d\n",start->info);
		free(start);
		start=NULL;
		return;
	}
	node* temp=start;
	while(temp->link->link!=NULL)
	{
		temp=temp->link;
	}
	printf("Deleted Node is %d\n",temp->link->info);
	free(temp->link);
	temp->link=NULL;
	return;
}
void display()
{
	if(start==NULL)
	{
		printf("SLL Empty\n");
		return;
	}
	node *temp=start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->link;
	}
	printf("\n");
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
				   				


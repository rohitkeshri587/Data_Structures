#include<stdio.h>
typedef struct node
{
	int info;
	struct node* link;
}node;
node * start=NULL;
void insert_beg(int item)
{
	node* nn=(node*)malloc(sizeof(node));
	nn->info=item;
	if(start==NULL)
	{
		start=nn;
		start->link=NULL;
		printf("node inserted\n");
		return;
	}
	nn->link=start;
	start=nn;
	printf("node inserted\n");
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
void del_pos(int pos)
{	
	if(start==NULL)
	{
		printf("SLL Empty\n");
		return;
	}
	if(pos==1)
	{
		if(start->link==NULL)
		{
			printf("deleted node is %d\n",start->info);
			free(start);
			start=NULL;
			return;
		}
		node* temp=start;
		printf("Deleted node is %d\n",temp->info);
		start=start->link;
		free(temp);
		return;
	}
	node* temp=start;
	int c=1;
	while(temp->link!=NULL)
	{
		if(c+1==pos)
		{
			node* del= temp->link;
			temp->link=del->link;
			printf("Deleted node is %d\n",del->info);
			free(del);
			return;
		}
		temp=temp->link;
		c++;
	}
	printf("Invalid Position\n");
}
void main()
{
	int ch,item,pos;
	for(;;)
	{
		printf("menu\n1.insert at beg\n2.del from desired position\n3.display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("enter item\n");
				scanf("%d",&item);
				insert_beg(item);
				break;
			}
			case 2:
			{
				printf("enter position\n");
				scanf("%d",&pos);
				del_pos(pos);
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
				   				

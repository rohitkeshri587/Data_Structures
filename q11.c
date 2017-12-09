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
void del_pos(int pos)
{
	if(last==NULL)
	{
		printf("CLL Underflow\n");
		return;
	}
	if(last->link==last)
	{
		if(pos==1)
		{
			printf("Deleted Node is %d\n",last->info);
			free(last);
			last=NULL;
			return;
		}
		printf("Invalid Position\n");
		return;
	}
	if(pos==1)
	{
		node* temp=last->link;
		last->link=temp->link;
		printf("Deleted Node is %d\n",temp->info);
		free(temp);
		return;
	}
	int c=1;
	node * temp=last->link;
	while(temp->link!=last)
	{
		if(c+1==pos)
		{
			node* del=temp->link;
			printf("Deleted Node is %d\n",del->info);
			temp->link=del->link;
			free(del);
			return;
		}
		temp=temp->link;
		c++;
	}
	if(c+1==pos)
	{
		printf("Deleted Node is %d\n",temp->link->info);
		temp->link=last->link;
		free(last);
		last=temp;
		return;
	}
	printf("Invalid Position\n");
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
		printf("menu\n1.insert at beg\n2.del from pos\n3.display\n4.exit\n");
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
				printf("Enter Position\n");
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

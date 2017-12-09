#include<stdio.h>
#include<stdlib.h>
typedef struct node
{ 
	int info;
	struct node* left;	
	struct node* right;
}node;
node* start=NULL;
void insert_beg(int item)
{
	node* nn=(node*)malloc(sizeof(node));
	nn->info=item;
	if(start==NULL)
	{
		start=nn;
		start->left=NULL;
		start->right=NULL;
		printf("Node Inserted\n");
		return;
	}
	nn->right=start;
	nn->left=NULL;
	start->left=nn;
	start=nn;
	printf("Node Inserted\n");
	return;
}
void del_pos(int pos)
{
	if(start==NULL)	
	{
		printf("DLL Underflow\n");
		return;
	}
	if(start->right==NULL)
	{
		if(pos==1)
		{
			printf("Deleted Node is %d\n",start->info);
			free(start);
			start=NULL;
			return;
		}
		printf("Invalid Position\n");
		return;
	}
	if(pos==1)
	{
		node* temp=start;
		start=start->right;
		start->left=NULL;
		printf("Deleted Node is %d\n",temp->info);
		free(temp);
		return;
	}
	int c=1;
	node* temp=start;
	while(temp->right!=NULL)
	{
		if(c+1==pos)
		{
			node* del=temp->right;
			temp->right=del->right;
			if(del->right!=NULL)
				del->right->left=temp;
			printf("Deleted Node is %d\n",del->info);
			return;
		}
		temp=temp->right;
		c++;
	}
	printf("Invalid Position\n");
	return;
}
void display()
{
	if(start==NULL)
	{
		printf("DLL Empty\n");
		return;
	}
	node* temp=start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->right;
	}
	printf("\n");
	return;
}
void main()
{
	int ch,item,pos;
	for(;;)
	{
		printf("menu\n1.insert at beg\n2.delete from pos\n3.display\n4.exit\n");
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

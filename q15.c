#include<stdio.h>
#include<stdlib.h>
typedef struct node
{ 
	int info;
	struct node* left;	
	struct node* right;
}node;
node* start=NULL;
void insert_pos(int item, int pos)
{
	node* nn=(node*)malloc(sizeof(node));
	nn->info=item;
	if(start==NULL)
	{
		if(pos==1)
		{
			start=nn;
			start->left=NULL;
			start->right=NULL;
			printf("Node Inserted\n");
			return;
		}
		printf("Invalid POsition\n");
		return;
	}
	if(pos==1)
	{
		nn->right=start;
		nn->left=NULL;
		start->left=nn;
		start=nn;
		printf("Node Inserted\n");
		return;
	}
	int c=1;
	node* temp=start;
	while(temp!=NULL)
	{
		if(c+1==pos)
		{
			nn->right=temp->right;
			nn->left=temp;
			if(temp->right!=NULL)
				temp->right->left=nn;
			temp->right=nn;
			printf("Node Inserted\n");
			return;
		}
		temp=temp->right;
		c++;
	}
	printf("Invalid Position\n");
	return;
}
void del_end()
{
	if(start==NULL)
	{
		printf("DLL Underflow\n");
		return;
	}
	if(start->right==NULL)
	{
		printf("Deleted Node is %d\n",start->info);
		free(start);
		start=NULL;
		return;
	}
	node* temp= start;
	while(temp->right->right!=NULL)
	{
		temp=temp->right;
	}
	printf("Deleted Node id %d\n",temp->right->info);
	free(temp->right);
	temp->right=NULL;
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
		printf("menu\n1.insert at pos\n2.delete from end\n3.display\n4.exit\n");
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

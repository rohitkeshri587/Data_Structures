#include<stdio.h>
#include<stdlib.h>
typedef struct node
{ 
	int info;
	struct node* left;	
	struct node* right;
}node;
node* start=NULL;
void insert(int item)
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
	if(item<start->info)
	{
		nn->right=start;
		nn->left=NULL;
		start->left=nn;
		start=nn;
		printf("Node Inserted\n");
		return;
	}
	node* temp=start;
	while(temp->right!=NULL)
	{
		if(item<temp->right->info)
		{
			nn->right=temp->right;
			nn->left=temp;
			temp->right->left=nn;
			temp->right=nn;
			printf("Node Inserted\n");
			return;
		}
		temp=temp->right;
	}
	temp->right=nn;
	nn->left=temp;
	nn->right=NULL;
	printf("Node Inserted\n");
	return;
}
void del_beg()
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
	node* temp=start;
	start=start->right;
	start->left=NULL;
	printf("Deleted Node is %d\n",temp->info);
	free(temp);
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
		printf("menu\n1.insert\n2.delete from beg\n3.display\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter Item\n");
				scanf("%d",&item);
				insert(item);
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

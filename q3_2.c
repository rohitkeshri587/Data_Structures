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
void main()
{
	int ch,item;
	for(;;)
	{
		printf("menu\n1.insert at beg\n2.display\n3.exit\n");
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
				display();
				break;
			}
			case 3: return;
			default : printf("invalid choice\n");
		}
	}
}
				   				

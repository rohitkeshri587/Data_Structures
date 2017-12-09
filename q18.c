#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
}node;
node* root=NULL;
void BST(int item)
{
	node* nn=(node*)malloc(sizeof(node));
	nn->info=item;
	nn->left=NULL;
	nn->right=NULL;
	if(root==NULL)
	{
		root=nn;
		return;
	}
	node* temp= root;
	node* prev=NULL;
	while(temp!=NULL)
	{
		prev=temp;
		if(item<temp->info)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(item<prev->info)
		prev->left=nn;
	else
		prev->right=nn;
	return;
}
void display(node* root, int level)
{
	if(root==NULL)
		return;
	display(root->right,level+1);
	int i=0;
	for(i=0;i<level;i++)
		printf(" ");
	printf("%d\n",root->info);
	display(root->left,level+1);
	return;
}
void main()
{
	int size=0,i=0;
	printf("Enter No. Of Data\n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter Data\n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<size;i++)
		BST(arr[i]);
	printf("BST CREATED\n");
	display(root,0);
	return;
}

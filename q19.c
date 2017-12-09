#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
}node;
node* create()
{
	int x;
	printf("Enter data, -1 for no data\n");
	scanf("%d",&x);
	if(x==-1)
		return NULL;
	node* nn=(node*)malloc(sizeof(node));
	nn->info=x;
	printf("Enter left child of %d\n",x);
	nn->left=create();
	printf("Enter right child of %d\n",x);
	nn->right=create();	
	return nn;
}
void preorder(node* root)
{
	if(root==NULL)
		return;
	printf("%d\t",root->info);
	preorder(root->left);
	preorder(root->right);
	return;
}
void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d\t",root->info);
	inorder(root->right);
	return;
}
void postorder(node* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->info);
	return;
}
void main()
{
	printf("BT CREATION\n");
	node* root=create();
	int ch;
	for(;;)
	{
		printf("Menu\n1.Preorder\n2.Postorder\n3.Inorder\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: preorder(root);
				printf("\n");
				break;
			case 2: postorder(root);
				printf("\n");
				break;
			case 3: inorder(root);
				printf("\n");
				break;
			case 4: return;
			default: printf("invalid choice\n");
		}
	}
}

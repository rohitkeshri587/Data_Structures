#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node
{
    char info;
    struct node*left;
    struct node*right;
};
typedef struct node *NODE;
struct stack
{
    int top;
    NODE arr[50];
};

NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)printf("memory full\n");
    return x;
}
void push(struct stack*s,NODE ele)
{
    if(s->top==49)
        printf("stack full\n");
    else
    {
        s->top++;
        s->arr[s->top]=ele;
    }
}

NODE pop(struct stack*st)
{
    NODE x;
    if(st->top==-1)
    {
        printf("stack empty\n");
        return NULL;
    }
    x=st->arr[st->top];
    st->top--;
    return x;
}
void inorder(NODE root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%c\t",root->info);
    inorder(root->right);
    }
}
void postorder(NODE root)
{
    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
    printf("%c\t",root->info);
    }
}
NODE createroot(char postfix[])
{
    NODE root,temp;
    NODE lc,rc;
    char ch;
    int i;
    struct stack s;
    s.top=-1;
    for(i=0; i<strlen(postfix); i++)
    {
        ch=postfix[i];
        temp=getnode(ch);
        temp->info=ch;
        temp->left=NULL;
        temp->right=NULL;
        if(isdigit(postfix[i]))
        {
            push(&s,temp);
        }
        else
        {
           rc=pop(&s);
           lc=pop(&s);
           temp->right=rc;
           temp->left=lc;
           push(&s,temp);
        }
    }
    root=pop(&s);
    return root;
}
float evaluate(NODE root)
{
    switch(root->info)
    {
    case '+':return (evaluate(root->left)+evaluate(root->right));
    case '-':return (evaluate(root->left)-evaluate(root->right));
    case '*':return (evaluate(root->left)*evaluate(root->right));
    case '/':return (evaluate(root->left)/evaluate(root->right));
    case '^':return (pow(evaluate(root->left),evaluate(root->right)));
    case '$':return (pow(evaluate(root->left),evaluate(root->right)));
    default: return ((root->info)-'0');
    }
}
int main()
{
    char postfix[20]="";
    NODE root; float result;
    printf("enter postfix expression\n");
    scanf("%s",postfix);
    root=createroot(postfix);
    result=evaluate(root);
    inorder(root);
    printf("\n");
    printf("%f\n",result);
    return 0;
}

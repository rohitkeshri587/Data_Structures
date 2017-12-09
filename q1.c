#include<stdio.h>
#include<string.h>
#define size 20
int top=-1;
int g(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default : return 7;
    }
}
int f(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
        default : return 8;
    }
}
void push(char a[], char item)
{
    if(top==size-1)
    {
        printf("stack overflow\n");
        return;
    }
    a[++top]=item;
    return;
}
char pop(char a[])
{
    if(top==-1)
        return 0;
    char del;
    del=a[top--];
    return del;
}
void infix_to_postfix(char infix[], char postfix[])
{
    char symbol;
    char s[size];
    push(s,'#');
    int i=0,j=0;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        while(f(s[top])>g(symbol))
        {
            postfix[j++]=pop(s);
        }
        if(f(s[top])!=g(symbol))
        {
            push(s,symbol);
        }
        else
        {
            pop(s);
        }
    }
    while(s[top]!='#')
    {
        postfix[j++]=pop(s);
    }
    postfix[j]='\0';
    return;
}
void main()
{
    char infix[size], postfix[size];
    printf("Enter infix expression\n");
    scanf("%s",infix);
    infix_to_postfix(infix,postfix);
    printf("%s\n",postfix);
    return;
}

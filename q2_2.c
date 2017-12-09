#include<stdio.h>
#include<string.h>
#include<math.h>
int cal(char symbol, int op1, int op2)
{
    switch(symbol)
    {
        case '+':return(op1+op2);
        case '-':return(op1-op2);
        case '*':return(op1*op2);
        case '/':return(op1/op2);
        case '%':return(op1%op2);
        case '^':return pow(op1,op2);
    }
}
void main()
{
    char symbol,postfix[20];
    printf("enter valid postfix expression\n");
    scanf("%s",postfix);
    int i=0,top=-1;
    int op1,op2,res,s[20];
    for(i=0;i<strlen(postfix);i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
        {
            s[++top]=symbol-'0';
        }
        else
        {
            op2=s[top--];
            op1=s[top--];
            res=cal(symbol,op1,op2);
            s[++top]=res;
        }
    }
    res=s[top--];
    printf("result is %d\n",res);
    return;
}


#include<stdio.h>
void toh(int n, char s, char t, char d)
{
	if(n==1)
	{
		printf("move disc from %c to %c\n",s,d);
		return;
	}
	toh(n-1,s,d,t);
	printf("move disc from %c to %c\n",s,d);
	toh(n-1,t,s,d);
}
void main()
{
	int n;
	printf("enter number of discs\n");
	scanf("%d",&n);
	toh(n,'S','T','D');
	return;
}

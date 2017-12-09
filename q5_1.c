#include<stdio.h>
int gcd(int m, int n)
{
	if(n==0)
		return m;
	return(n,m%n);
}
void main()
{
	int m,n;
	printf("enter the value of m & n\n");	
	scanf("%d%d",&m,&n);
	printf("result is %d\n",gcd(m,n));
	return;
}

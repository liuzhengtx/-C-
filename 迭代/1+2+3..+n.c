#include <stdio.h>
long sum(long n)
{
	if(1==n)
		return 1;
	else
		return n+sum(n-1);
}

int main(void)
{
	long n,s;
	printf("please input a num��");
	scanf("%d",&n);
	printf("��ͣ�");
	printf("%d",sum(n));
	return 0;
 } 

/*
	Name: 
	Copyright: 
	Author: 
	Date: 31/01/18 09:20
	Description: 
*/
 #include <stdio.h>
 
int hantuota(int n,char A,char B,char C)
{
	if(1==n)
	{
		printf("%c-->%c",A,C);
		printf("\n");
		return n;
	}
	else
	{
		hantuota(n-1,A,C,B);
		printf("%c-->%c",A,C);
		printf("\n");
		hantuota(n-1,B,A,C);
		return n;
	}
//	���n=1
//		A-->C
//	����
//		ǰ(n-1)��A-->B 
//		Ȼ��A-->C
//		���ǰ(n-1)��B-->C 
}
 int main(void)
 {
	int n;
	while(1)
	{
		printf("please input hantuota num:");
		scanf("%d",&n);
		hantuota(n,'A','B','C');
	}
 	return 0;
 }

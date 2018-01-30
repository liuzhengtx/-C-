#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
	int data;
	struct node *next; 
}NODE,*PNODE; 
typedef struct stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;
//��ʼ��һ��ջ 
InitStack(PSTACK S)
{
	S->pTop=(PNODE)malloc(sizeof(NODE));
	if(NULL==S->pTop)
	{
		printf("stack init failure \n");
		exit(-1);
		
	}
	else
	{
		S->pBottom=S->pTop;
		S->pTop->next=S->pBottom->next=NULL;
		S->pBottom->data=0;
	}

}
//ѹջ
void PushStack(PSTACK S,int data)
{
	PNODE pNew=NULL;
	pNew=(PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
		printf("node creat failure \n");
		exit(-1);
	 } 
	 else
	 {
	 	pNew->data=data;
	 	pNew->next=S->pTop;
	 	S->pTop=pNew;
	 }
 } 
 //��ջ
 void PopStack(PSTACK S,int *val)
 {
// 	PNODE old=S->pTop;
// 	val=old->data;
//	S->pTop=old->next;
//	free(old); 
//	old=NULL;
 PNODE old = S->pTop;
 *val = old->data;
 S->pTop = old->next;
 free(old);
 old = NULL;
  } 
  //���ջ
 void ClearStack(PSTACK S)
 {
 	PNODE p,q;
 	p=S->pTop;
 	while(S->pBottom!=p)
 	{
 		q=p->next;
 		free(p);
 		p=q;
	 }
	 S->pTop = S->pBottom;
	 printf("clear done \n");
  } 
 //��ӡ 
 void PrintStack(PSTACK S)
 {
 	PNODE top=S->pTop;
 	while(S->pBottom!=top)
 	{
 		printf("%d ",top->data);
 		top=top->next;
	 }
	 printf("\n");
 }
int main(void)
{
	STACK S;
	int val;
	InitStack(&S);
	PushStack(&S,10);
	PushStack(&S,20);
	PushStack(&S,30);
	PushStack(&S,40);
	
	PrintStack(&S);
	
	PopStack(&S,&val);//�ı��val�ĵ�ַ�����Կ���ֱ�Ӵ��룬��PopStack(&S,val) ��Ҫ�з���ֵ�ſ���//// 
	printf("out is %d \n",val);
	PopStack(&S,&val);
	printf("out is %d \n",val);
	PrintStack(&S);
	ClearStack(&S);
	PrintStack(&S);
	
	return 0;
 } 

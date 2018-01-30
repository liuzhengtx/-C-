#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct queue
{
	int *pBase;
	int front;
	int rear;
	int maxsize;//��󳤶� 
}QUEUE,*PQUEUE;
//��ʼ��һ������
void InitQueue(PQUEUE Q,int maxsize)
{
	Q->pBase=(int*)malloc(sizeof(int)*maxsize) ;
	Q->front=Q->rear=0;
	Q->maxsize=maxsize;
 } 
//�ж϶����Ƿ�Ϊ��
bool IsEmpty(PQUEUE Q)
{
	if(Q->front==Q->rear)
	{
		return true;
	}
	else
		return false;
 } 
 //�ж϶����Ƿ���
bool IsFull(PQUEUE Q)
{
	if(Q->front==(Q->rear+1)%Q->maxsize)
	{
		return true;
	}
	else
		return false;
 } 
 //���
void InQueue(PQUEUE Q,int val)
{
	if(IsFull(Q))
	{
		printf("������������");
	}
	else
	{
		Q->pBase[Q->rear]=val;
		Q->rear=(Q->rear+1)%Q->maxsize;//Ϊ��ʹ���һ���ռ�Ϊ��(����Ԫ��)�����ܲ���(Q->rear)++ 
	}
		
 } 
 //���� 
 void OutQueue(PQUEUE Q,int *val)
 {
 	if(IsEmpty(Q)) 
 		printf("������Ϊ�գ���");
	else
	{
		*val=Q->pBase[Q->front];
 		Q->front=(Q->front+1)%Q->maxsize;
	 } 
  } 
 
 //��ӡ
void PrintQueue(PQUEUE Q)
{
	int i=Q->front;
	while(i!=Q->rear)
	{
		printf("%d ",Q->pBase[i]);
		i++;
	}
	printf("\n");
 } 
int main(void)
{
	QUEUE Q;
	int val,w;
	InitQueue(&Q,5);
	while(1)
	{
		printf("������һ��Ԫ�أ�");
		scanf("%d",&w);
		InQueue(&Q,w);
		PrintQueue(&Q);
	}
//	InQueue(&Q,5);
	PrintQueue(&Q);
	OutQueue(&Q,&val);
	printf("����Ԫ���ǣ�%d",val);
	printf("\n");
	printf("ʣ��Ԫ��Ϊ��");
	PrintQueue(&Q);
	OutQueue(&Q,&val);
	printf("����Ԫ���ǣ�%d",val);
	printf("\n");
	printf("ʣ��Ԫ��Ϊ��");
	PrintQueue(&Q);
	return 0;
 } 

#include <stdio.h>
#include <stdlib.h> 
#define MAXVEX 1000
typedef char VertexType;//��������
typedef int EdgeType;//Ȩֵ����

typedef struct EdgeNode//�߱��� 
{
	int adjvex;//�ڽ����
	EdgeType weight;//���ڴ洢Ȩֵ
	struct EdgeNode *next;//����ָ����һ���ڽ�� 
 } EdgeNode;
typedef struct VertexNode//�����ṹ
{
	VertexType data;//�����򣬴洢������Ϣ
	EdgeNode *firstedge;//�߱�ͷָ�� 
 } VertexNode,AdjList[MAXVEX] ;
typedef struct
{
	AdjList adjList;
	int numVertex,numEdges;//ͼ�е�ǰ�������ͱ��� 
}GraphList;
int Locate(GraphList *g,char ch)
{
	int i;
	for(i=0;i<MAXVEX;i++)
	{
		if(ch==g->adjList[i].data)
		{
			break;
		}
	}
	if(i>MAXVEX)
	{
		fprintf(stderr,"there is no vertex.\n");
		return -1; 
	}
	return i; 
}
//����ͼ���ڽӱ�ṹ
void CreateGraph(GraphList *g)
{
	int i,j,k;
	EdgeNode *e;//�߱���
	EdgeNode *f;
	printf("���붥�����ͱ�����\n");
	scanf("%d %d",&g->numVertex,&g->numEdges);
	for(i=0;i<g->numVertex;i++)
	{
		printf("�����붥��%d:\n",i);
		g->adjList[i].data=getchar();//���붥����Ϣ
		g->adjList[i].firstedge=NULL; 
		while(g->adjList[i].data=='\n')
		{
			g->adjList[i].data=getchar();
		}
	}
	//�����߱�
	for(k=0;k<g->numEdges;k++)
	{
		printf("����ߣ�vi,vj)�ϵĶ������:\n");
		char p,q;
		p=getchar();
		while(p=='\n')
		{
			p=getchar();
		}
		printf("p=%c\n",p);
		q=getchar();
		while(q=='\n')
		{
			q=getchar();
		}
		printf("q=%c\n",q);
		int m=-1;
		int n=-1;
		m=Locate(g,p);
		n=Locate(g,q);
        printf("m = %d\n", m);
        printf("n = %d\n", n);
		if(m==-1||n==-1)
		{
			return;
		}
		//���ڴ�����ռ䣬���ɱ߱���
		e=(EdgeNode *)malloc(sizeof(EdgeNode));
		if(e==NULL)
		{
			fprintf(stderr,"�ڴ����ʧ��"); 
			return; 
		 } 
		//�ڽ����Ϊj
		e->adjvex=n;
		//��eָ��ָ��ǰ����ָ��Ľṹ
		e->next=g->adjList[m].firstedge;
		//����ǰ�����ָ��ָ��e
		g->adjList[m].firstedge=e;
		f= (EdgeNode *)malloc(sizeof(EdgeNode));
		if(f==NULL)
		{
			fprintf(stderr,"�ڴ����ʧ��"); 
			return; 
		}
		f->adjvex=m;
		f->next=g->adjList[n].firstedge;
		g->adjList[n].firstedge = f;
	 } 
 } 
 //��ӡͼ
 void printGraph(GraphList *g)
 {
 	int i=0;
 	while(g->adjList[i].firstedge!=NULL&&i<MAXVEX)
 	{
 		printf("����%c: ",g->adjList[i].data);
 		EdgeNode *e=NULL;
 		e=g->adjList[i].firstedge;
 		while(e!=NULL)
 		{
 			printf("%d  ",e->adjvex);
 			e=e->next;
		 }
		 i++;
		 printf("\n");
	 }
  } 
int main(void)
{
	GraphList g;
    CreateGraph(&g);
    printGraph(&g);
	return 0;
}

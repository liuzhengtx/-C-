#include <stdio.h> 
#include <stdlib.h>
#define MAXVEX 100 //��󶥵���
#define INFINITY 65535 //��65535����������� 

typedef char VertexType;//��������
typedef int EdgeType; //���ϵ�Ȩֵ����

typedef struct
{
	VertexType vexs[MAXVEX];//����� 
	EdgeType arc[MAXVEX][MAXVEX];//�ڽӾ��󣬿ɿ�����
	int numVertexes,numEdges;// ͼ�е�ǰ�Ķ������ͱ��� 
} Graph; 
//��λ
int locates(Graph *g, char ch)
{
    int i = 0;
    for(i = 0; i < g->numVertexes; i++)
    {
        if(g->vexs[i] == ch)
        {
            break;
        }
    }
    if(i >= g->numVertexes)
    {
        return -1;
    }
     
    return i;
}
 //����һ��������ͼ���ڽӾ����ʾ
 void CreateGraph(Graph *g) 
{
 	int i,j,k,w;
 	printf("�����붥�����ͱ���:\n");
 	scanf("%d %d",&(g->numVertexes),&(g->numEdges));
 	printf("%d %d\n", g->numVertexes, g->numEdges);
 	for(i=0;i<g->numVertexes;i++)
 	{
 		g->vexs[i]=getchar();
 		while(g->vexs[i]=='\n')//�س����� 
 		{
 			g->vexs[i]=getchar();
		 }
	 }
	 for(i=0;i<g->numEdges;i++)
	 	for(j=0;j<g->numEdges;j++)
	 	{
	 		if(i==j)
			 {
			 	g->arc[i][j]=0;
			 } 
			 else
			 {
			 	g->arc[i][j]=INFINITY;//�ڽӾ����ʼ�� 
			  } 
		 }
	for(k=0;k<g->numEdges;k++)
	{
		char p,q;
		printf("������ߣ�vi,vj)�ϵ��±�i,�±�j��Ȩֵ��\n");
		p=getchar();
		while(p=='\n')
		{
			p=getchar();
		 } 
		q=getchar();
		while(q=='\n')
		{
			q=getchar();
		 }
		scanf("%d",&w);
		
		int m=-1;
		int n=-1;
		
		m=locates(g,p);
		n=locates(g,q);
		if(n==-1||m==-1)
		{
			fprintf(stderr,"there is no this vertex.\n");
			return;
		}
		g->arc[m][n]=w;
		g->arc[n][m]=g->arc[m][n];
	 } 
} 
//��ӡͼ
void printGraph(Graph g)
{
	int i,j;
    for(i = 0; i < g.numVertexes; i++)
    {
        for(j = 0; j < g.numVertexes; j++)
        {
            printf("%d     ", g.arc[i][j]);
        }
        printf("\n");
    }
 } 
int main(void)
{
	 Graph g;
     
    //�ڽӾ��󴴽�ͼ
    CreateGraph(&g);
    printGraph(g);
	return 0;
}

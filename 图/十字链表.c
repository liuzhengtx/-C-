#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTEX_NUM 20
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int VertexType;
typedef int Status;
typedef enum{
	DG,DN
}Graphkind;//ͼ�������������ͼ�������� 
//����Ϣ 
typedef struct ArcBox{
	int tailvex;//�û���β�����λ��
	int headvex;//�û���ͷ�����λ��
	struct ArcBox *hlink;//ָ����һ��������ͬ�Ļ�
	struct ArcBox *tlink;//ָ����һ���յ���ͬ�Ļ�
	int weight;//����Ȩֵ 
}ArcBox; 
//������Ϣ 
typedef struct VexNode{
	VertexType data;//���Ķ���
	ArcBox *firstin;//ָ��ö���ĵ�һ���뻡
	ArcBox *firstout;//ָ��ö���ĵ�һ������ 
}VexNode;
//ͼ��Ϣ
typedef struct{
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum;//��ǰ�Ķ�����
	int arcnum;//��ǰ�Ļ���
	Graphkind kind;//ͼ������ 
}OLGraph; 
//���ʱ������
int visited[MAX_VERTEX_NUM]; 
//����ͼ������ͼ/��������
Status CreateGraph(OLGraph *G);
//��λ����ֵv��λ��
int LocateVex(OLGraph G,VertexType v);
//����ͼ
Status CreateGraph(OLGraph *G)
{
	int i,j,k,w;
	VertexType tv,hv;//�������� 
	ArcBox *p;//��
	//ȷ��ͼ������
	printf("please enter the kind of graph(DG:0,DN:1:)") ;
	scanf("%d",&(*G).kind);
	//ȷ���������ͻ���
	printf("please enter the vexnum and arcnum:");
	scanf("%d %d",&(*G).vexnum,&(*G).arcnum);
	//ȷ����������
	printf("please enter each valve of graph:");
	for(i=0;i<(*G).vexnum;i++)
	{
		scanf("%d",&(*G).xlist[i].data);
		(*G).xlist[i].firstin=NULL;
		(*G).xlist[i].firstout=NULL;
	} 
	//�������������Ĺ�ϵ����������/����
	if((*G).kind==DN)
		printf("please enter the heads,tails and weights:\n"); 
	else 
		printf("please enter the heads and tails:\n");
	for(k = 0;k < (*G).arcnum ; k++)
	{
		if((*G).kind == DN)   
            scanf("%d,%d,%d",&tv,&hv,&w);  
        else  
            scanf("%d,%d",&tv,&hv); 
			i=LocateVex(*G,tv);//��β 
	j=LocateVex(*G,hv); //��ͷ
	
	p=(ArcBox*)malloc(sizeof(ArcBox)); 
	if(!p)
		exit(OVERFLOW);
	p->tailvex=i;//������㣬���
	p->headvex=j;//�����յ㣬����
	p->hlink=(*G).xlist[j].firstin;//ָ����һ�������ͬ�Ļ��ڵ�
	p->tlink=(*G).xlist[i].firstout;//ָ����һ���յ���ͬ�Ļ��ڵ�
	//ע�ⲻ���ǳ�����������ڱ�ͷ����ģ�<v1,v2>��ʾv1�г���v2����
	(*G).xlist[i].firstout=(*G).xlist[j].firstin=p;
	if((*G).kind==DN)
	{
		p->weight=w;
	} 
		
	}

	return OK;
	
 } 
int LocateVex(OLGraph G,VertexType v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.xlist[i].data==v)
		{
			return i;
		}
	}
}

int main(void)
{
	OLGraph G;
	CreateGraph(&G);
	
	return 0;
 } 

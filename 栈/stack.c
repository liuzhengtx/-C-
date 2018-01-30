#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
#include<stddef.h>
//������ṹ��
typedef struct Node
{
 int data;  //����
 struct Node * pNext; //ָ����һ����ָ��
} NODE, * PNODE;  //NODE�ȼ���struct Node, PNODE�ȼ���struct Node *
//����ջ�Ľṹ��
typedef struct Stack
{
 PNODE pTop;  //ջ�����
 PNODE pBottom;  //ջ�׽��
} STACK, * PSTACK;  //STACK�ȼ���struct Stack, PSTACK�ȼ���struct Stack *
//��������
void initStack(PSTACK pStack);  //��ջ���г�ʼ���ĺ���
void pushStack(PSTACK pStack, int val); //��ջ�ĺ���
bool popStack(PSTACK pStack, int * pVal);//��ջ�ĺ�����*pVal���������ջ��Ԫ������
void traverseStack(PSTACK pStack);  //����ջ�ĺ���
bool isEmpty(PSTACK pStack);  //�ж�ջ�Ƿ�Ϊ�յĺ���
void clearStack(PSTACK pStack);  //���ջ�ĺ���
int main(void)
{
 STACK stack;  //����һ��ջ����,STACK�ȼ���struct Stack
 int val;  //���������ջ������
 initStack(&stack); //����ջ�ĳ�ʼ������
 pushStack(&stack, 10); //������ջ�ĺ���
 pushStack(&stack, 20);
 pushStack(&stack, 30);
 pushStack(&stack, 50);
 traverseStack(&stack); //���ñ���ջ�ĺ���
 //���ó�ջ�ĺ���
 if(popStack(&stack, &val))
 printf("��ջ�ɹ�����ջ��Ԫ��ֵΪ��%d\n", val);
 else
 printf(" ��ջʧ��!");
 //�������ջ�ĺ���
 clearStack(&stack);
 traverseStack(&stack); //���ñ���ջ�ĺ���
 system("pause");
 return 0;
}

void initStack(PSTACK pStack)
{
 //����һ���ս�㣬��pTopָ����
 pStack->pTop = (PNODE)malloc(sizeof(NODE));
 if(NULL != pStack->pTop)
 {
 //��pBottomҲָ��սڵ�
 pStack->pBottom = pStack->pTop;
 pStack->pTop->data=0;
 //��տս���ָ����
 pStack->pTop->pNext = NULL;
 }
 else   //����ڴ����ʧ��
 {
 printf("�ڴ����ʧ��!�����˳�!\n");
 exit(-1);
 }
 return;
}

void pushStack(PSTACK pStack, int val)
{
 //��̬����һ���½��
 PNODE pNew = (PNODE)malloc(sizeof(NODE));
 //�����½����������ֵ
 pNew->data = val;
 //���½���ָ����ָ��֮ǰ���Ŀսڵ�
 pNew->pNext = pStack->pTop;  //pStack->pTop���ܻ���pStack->pBottom
 //pTopָ���µĽ��
 pStack->pTop = pNew;
 return;
}

bool popStack(PSTACK pStack, int * pVal)
{
 if(isEmpty(pStack))
 {
 return false;
 }
 else
 {
 //�ȱ���ջ��Ԫ�صĵ�ַ��Ȼ��pTopָ����һԪ��,����ͷ�֮ǰջ��Ԫ�ص��ڴ�
 PNODE rNode = pStack->pTop;
 *pVal = rNode->data;
 pStack->pTop = rNode->pNext;
 free(rNode);
 rNode = NULL;
 return true;
 }
}

void traverseStack(PSTACK pStack)
{
 //��ջ������һ����ʱ���,��Ϊ�ڱ���ջ��ʱ��������ջ
 PNODE pNode = pStack->pTop;
 //ѭ������ջ,ֱ��ջ��
 while(pStack->pBottom != pNode )
 {
 printf("%d ", pNode->data);
 pNode = pNode->pNext;
 }
 printf("\n");
 return;
}

bool isEmpty(PSTACK pStack)
{
 if(pStack->pTop == pStack->pBottom)
 return true;
 else
 return false;
}

void clearStack(PSTACK pStack)
{ //ջΪ�գ����˳��ú���
 if(isEmpty(pStack))
 {
 return;
 }
 else
 { 
 //�������ָ����������ͷ�ջ��Ԫ�ص��ڴ�
 PNODE p = pStack->pTop;
 PNODE q = NULL;
 //ѭ���ͷ��ڴ�
 while(p != pStack->pBottom)
 {
  q = p->pNext;
  free(p);
  p = q;
 }
 //��ջ����ջ��ָ��ͬһ��ָ����Ϊ�յĽ��
 pStack->pTop = pStack->pBottom;
 return;
 }
}


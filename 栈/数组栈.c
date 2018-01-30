#include<stdlib.h>
#include<stdio.h>
//����ջ�Ĵ�С
#define STACK_SIZE 50
static int stack[STACK_SIZE];
static int top_element = -1; 
//�ж�ջ�Ƿ�Ϊ��
int isEmpty(){
    return top_element == -1;
}
//�ж�ջ�Ƿ�����
int isFull(){
    return top_element == STACK_SIZE - 1;
}
//ѹ��Ԫ��
void push(int value){
    if (!isFull()) {
        stack[++top_element] = value;
    }
}
//����Ԫ��
void pop(){
    if (!isEmpty()) {
        top_element--;
    }
}
//ȡ����Ԫ��
int top(){
    if (!isEmpty()) {
        return stack[top_element];
    }
 
    return -32768;
}
//�Ӷ�����ʼ��ӡջԪ��
void printStack(){
 
    int i = top_element;
    printf("%s����ִ�У���ӡ����̬����ջ�����ֵ��\n",__FUNCTION__);
    if (i == -1) {
        printf("����һ����ջ\n");
    }else{
        while (i != -1) {
            printf("%d ",stack[i--]);
        }
        printf("\n");
    }
}
int main(void)
{
	push(4);push(6);push(1);push(9);push(2);push(8);
    printStack();
    printf("\n");
 
    pop();pop();pop();pop();
    printf("����pop��ջ��Ԫ��Ϊ:\n");
    printStack();
    printf("\n");
 
    printf("topԪ�ص�ֵ:%d\n",top());
     return 0;
 } 

    #include <stdbool.h> 
	#ifndef __QUEUE_H_  
    #define __QUEUE_H_  
    typedef struct queue   
    {  
        int *pBase;  
        int front;    //ָ����е�һ��Ԫ��  
        int rear;    //ָ��������һ��Ԫ�ص���һ��Ԫ��  
        int maxsize; //ѭ�����е����洢�ռ�  
    }QUEUE,*PQUEUE;  
      
    void CreateQueue(PQUEUE Q,int maxsize);  
    void TraverseQueue(PQUEUE Q);  
    bool FullQueue(PQUEUE Q);  
    bool EmptyQueue(PQUEUE Q);  
    bool Enqueue(PQUEUE Q, int val);  
    bool Dequeue(PQUEUE Q, int *val);  
    #endif  

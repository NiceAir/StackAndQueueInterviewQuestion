//˳��ѭ������
#ifndef _SEQUENTIAL_LOOP_QUEUE_H
#define _SEQUENTIAL_LOOP_QUEUE_H

#include "common.h"

typedef struct CircleQueue{
    int front;
    int tail;
    SNode Node[MAXLEN];
}CQueue;

void CircleQueueTest(void);//����ѭ������
void CircleQueueInit(CQueue *queue);    //˳��ѭ�����г�ʼ��
int CheckQueueIsFull(const CQueue queue);//�ж϶����Ƿ����ˡ��������򷵻�1��û���򷵻�0��
void QueuePush(CQueue *queue, SNode node);//Ԫ�������
int CheckQueueIsEmpty(const CQueue queue);//�ж϶����Ƿ�Ϊ�ա�Ϊ���򷵻�1�����򷵻�0��
SNode QueuePop(CQueue *queue); //Ԫ�س�����
int GetQueueCount(const CQueue queue); //��ȡ������Ԫ�صĸ���
SNode GetQueueTop(const CQueue queue); //��ȡ�������е�Ԫ��
SNode GetQueueTail(const CQueue queue); //��ȡ��������е�Ԫ��

#endif
#ifndef _QUEUE_BY_TWO_STACK_H
#define _QUEUE_BY_TWO_STACK_H

#include "StaticOrderStack.h"

typedef struct QueueBTS{
    SStack StackIn;
    SStack StackOut;
}QueueBTS;

void QueueBTSTest(void); //����QueueBTS����
void QueueBTSInit(QueueBTS *queue);  //��ʼ��
void QueueBTSPush(QueueBTS *queue, SNode Node); //������
SNode QueueBTSPop(QueueBTS *queue);  //������
int GetQueueBTSNodeCount(QueueBTS queue);    //��ȡ������Ԫ�صĸ���




#endif

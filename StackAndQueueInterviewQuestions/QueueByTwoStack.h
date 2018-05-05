#ifndef _QUEUE_BY_TWO_STACK_H
#define _QUEUE_BY_TWO_STACK_H

#include "StaticOrderStack.h"

typedef struct QueueBTS{
    SStack StackIn;
    SStack StackOut;
}QueueBTS;

void QueueBTSTest(void); //测试QueueBTS队列
void QueueBTSInit(QueueBTS *queue);  //初始化
void QueueBTSPush(QueueBTS *queue, SNode Node); //进队列
SNode QueueBTSPop(QueueBTS *queue);  //出队列
int GetQueueBTSNodeCount(QueueBTS queue);    //获取队列中元素的个数




#endif

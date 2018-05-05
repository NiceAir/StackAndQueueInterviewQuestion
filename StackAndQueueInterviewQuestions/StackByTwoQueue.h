#ifndef _STACK_BY_TWO_QUEUE_
#define _STACK_BY_TWO_QUEUE_
#include "SequentialLoopQueue.h"

typedef struct StackBTQ{
    CQueue QueueMain;
    CQueue QueueAssist;
}StackBTQ;

void StackBTQInit(StackBTQ *stack); //��ʼ��
void StackBTQPush(StackBTQ *stack, SNode node); //Ԫ�ؽ�ջ
SNode StackBTQPop(StackBTQ *stack); //Ԫ�س�ջ
int GetStackBTQCount(const StackBTQ stack); //��ȡջ��Ԫ�صĸ���
SNode GetStackBTQTop(const StackBTQ stack);//��ȡջ��Ԫ��
SNode GetStackBTQTail(const StackBTQ stack);//��ȡջ��Ԫ��
void StackBTQTest(void); //����StackBTQջ






#endif
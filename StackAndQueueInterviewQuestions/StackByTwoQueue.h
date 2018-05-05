#ifndef _STACK_BY_TWO_QUEUE_
#define _STACK_BY_TWO_QUEUE_
#include "SequentialLoopQueue.h"

typedef struct StackBTQ{
    CQueue QueueMain;
    CQueue QueueAssist;
}StackBTQ;

void StackBTQInit(StackBTQ *stack); //初始化
void StackBTQPush(StackBTQ *stack, SNode node); //元素进栈
SNode StackBTQPop(StackBTQ *stack); //元素出栈
int GetStackBTQCount(const StackBTQ stack); //获取栈中元素的个数
SNode GetStackBTQTop(const StackBTQ stack);//获取栈顶元素
SNode GetStackBTQTail(const StackBTQ stack);//获取栈底元素
void StackBTQTest(void); //测试StackBTQ栈






#endif
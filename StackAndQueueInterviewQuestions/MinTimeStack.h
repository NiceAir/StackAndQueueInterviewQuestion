//实现一个栈，要求实现Push(出栈)、Pop(入栈)、Min(返回最小值)的时间复杂度为O(1)
#ifndef _MIN_TIME_STACK_H
#define _MIN_TIME_STACK_H
#include "StaticOrderStack.h"
typedef struct MinTimeStack{
    SStack MainStack;
    SStack AssistStack;
}MTStack;

void MinTimeStackInit(MTStack *stack); //初始化最小时间栈
void MTStackPush(MTStack *stack, SNode node); //进栈
SNode MTStackPop(MTStack *stack); //出栈
SNode GetMinNode(MTStack stack); //获取最小元素

void MTStackTest(void);  //测试该栈

#endif
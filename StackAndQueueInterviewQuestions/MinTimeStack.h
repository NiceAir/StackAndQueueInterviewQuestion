//ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ)��ʱ�临�Ӷ�ΪO(1)
#ifndef _MIN_TIME_STACK_H
#define _MIN_TIME_STACK_H
#include "StaticOrderStack.h"
typedef struct MinTimeStack{
    SStack MainStack;
    SStack AssistStack;
}MTStack;

void MinTimeStackInit(MTStack *stack); //��ʼ����Сʱ��ջ
void MTStackPush(MTStack *stack, SNode node); //��ջ
SNode MTStackPop(MTStack *stack); //��ջ
SNode GetMinNode(MTStack stack); //��ȡ��СԪ��

void MTStackTest(void);  //���Ը�ջ

#endif
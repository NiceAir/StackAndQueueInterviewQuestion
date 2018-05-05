//��̬˳��ջ
#ifndef _STATIC_ORDER_STACK_H
#define _STATIC_ORDER_STACK_H

#include "common.h"

typedef struct StaticStack{
    int top;
    int bottom;
    SNode Node[MAXLEN];
}SStack;


void StaticStackTest(void); //���Ծ�̬ջ
void StaticStackInit(SStack *Stack); //��̬ջ�ĳ�ʼ��
int CheckStackIsFull(const SStack stack);    //���ջ�Ƿ���, û������0�����˷���1
int StackPush(SStack *stack, SNode node);//Ԫ����ջ,�ɹ�����1��ʧ�ܷ���0
int CheckStackIsEmpty(const SStack stack);//���ջ�Ƿ�Ϊ��,Ϊ�շ���0����Ϊ�շ���1
SNode StackPop(SStack *stack);//Ԫ�س�ջ����ջ�ɹ����س�����Ԫ�أ���ջʧ��������˳�
int GetStackNodeCount(const SStack stack);  //��ȡջ��Ԫ�ظ���
SNode GetStackTop(const SStack stack);   //��ȡջ��Ԫ��

#endif
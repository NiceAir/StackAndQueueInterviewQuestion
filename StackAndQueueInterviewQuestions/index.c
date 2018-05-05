#pragma once

#include "StaticOrderStack.h"
#include "SequentialLoopQueue.h"
#include "MinTimeStack.h"
#include "QueueByTwoStack.h"
#include "StackByTwoQueue.h"

int CheckInstackOutstackLegale(char instr[], int lenin, char outstr[], int lenout) //�жϽ�ջ�������ջ�����Ƿ����1��ʾ����
{
    SStack stack;
    SNode node;
    int IndexOut = 0;
    int IndexIn = 0;
    if (lenin != lenout)
        return 0;
    StaticStackInit(&stack);
    node.data = instr[IndexIn++];
    StackPush(&stack, node);
    while(IndexOut < lenout)
    {
        while(IndexIn<lenin && GetStackTop(stack).data != outstr[IndexOut])
        {
            node.data = instr[IndexIn++];
            StackPush(&stack, node);
        }
        if (StackPop(&stack).data == outstr[IndexOut])
            IndexOut++;
        else
            return 0;
    }
    return 1;
}

int main()
{
  //  StaticStackTest();    //���Ծ�̬˳��ջ
  //  CircleQueueTest();    //����˳��ѭ������   
  //  MTStackTest();        //���ԡ�������Сֵ����ջ��ջʱ���ΪO(1)����ջ
  //  QueueBTSTest();       //����QueueBTS����
  //  StackBTQTest();         //����StackBTQջ
    int result = CheckInstackOutstackLegale("12345", 5, "45521", 5);
    if (result == 1)
        printf("Yes\n");
    else
        printf("No\n");
    printf("Over\n");
    return 0;
}
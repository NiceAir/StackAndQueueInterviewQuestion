#pragma once

#include "StaticOrderStack.h"
#include "SequentialLoopQueue.h"
#include "MinTimeStack.h"
#include "QueueByTwoStack.h"
#include "StackByTwoQueue.h"

int CheckInstackOutstackLegale(char instr[], int lenin, char outstr[], int lenout) //判断进栈序列与出栈序列是否合理，1表示合理。
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
  //  StaticStackTest();    //测试静态顺序栈
  //  CircleQueueTest();    //测试顺序循环队列   
  //  MTStackTest();        //测试“返回最小值、进栈出栈时间均为O(1)”的栈
  //  QueueBTSTest();       //测试QueueBTS队列
  //  StackBTQTest();         //测试StackBTQ栈
    int result = CheckInstackOutstackLegale("12345", 5, "45521", 5);
    if (result == 1)
        printf("Yes\n");
    else
        printf("No\n");
    printf("Over\n");
    return 0;
}
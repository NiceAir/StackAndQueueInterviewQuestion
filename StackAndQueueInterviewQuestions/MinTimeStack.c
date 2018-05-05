#include "MinTimeStack.h"

void MinTimeStackInit(MTStack *stack) //初始化最小时间栈
{
    assert(stack);
    StaticStackInit(&(stack->MainStack));
    StaticStackInit(&(stack->AssistStack));
}

void MTStackPush(MTStack *stack, SNode node) //进栈
{
    assert(stack);
    if (CheckStackIsEmpty(stack->MainStack))
    {
        StackPush(&(stack->MainStack), node);
        StackPush(&(stack->AssistStack), node);
    }
    else
    {
        SNode cache = GetStackTop(stack->MainStack);
        if (node.data <= cache.data)
        {
            StackPush(&(stack->MainStack), node);
            StackPush(&(stack->AssistStack), node);
        }
        else
            StackPush(&(stack->MainStack), node);
    }
}

SNode MTStackPop(MTStack *stack) //出栈
{
    assert(stack);
    if (GetStackTop(stack->MainStack).data <= GetStackTop(stack->AssistStack).data)
    {
        StackPop(&(stack->AssistStack));    
    }
    return StackPop(&(stack->MainStack));
}

SNode GetMinNode(MTStack stack) //获取最小元素
{
    if (!CheckStackIsEmpty(stack.AssistStack))
    {
        return GetStackTop(stack.AssistStack);
    }
    printf("错误，栈为空！！\n");
}
void MTStackTest(void)  //测试该栈
{
    MTStack stack;
    SNode node[10];
    int i = 0;
    MinTimeStackInit(&stack);
    node[0].data = 4;
    node[1].data = 3;
    node[2].data = 2;
    node[3].data = 5;
    node[4].data = 1;
    node[5].data = 2;

    for (i = 0; i<6; i++)
    {
        MTStackPush(&stack, node[i]);
    }
    printf("MinNode = %d\n\n", GetMinNode(stack));
    printf("MTS中出栈-->%d\n", MTStackPop(&stack).data);
    printf("MinNode = %d\n\n", GetMinNode(stack));
    printf("MTS中出栈-->%d\n", MTStackPop(&stack).data);
    printf("MinNode = %d\n\n", GetMinNode(stack));
    printf("MTS中出栈-->%d\n", MTStackPop(&stack).data);
    printf("MinNode = %d\n\n", GetMinNode(stack));
    printf("MTS中出栈-->%d\n", MTStackPop(&stack).data);
    printf("MinNode = %d\n\n", GetMinNode(stack));
}

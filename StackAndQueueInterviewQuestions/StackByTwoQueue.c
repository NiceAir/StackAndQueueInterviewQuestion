#include "StackByTwoQueue.h"

void StackBTQInit(StackBTQ *stack) //初始化
{
   assert(stack);
   CircleQueueInit(&(stack->QueueMain));
   CircleQueueInit(&(stack->QueueAssist));
}

void StackBTQPush(StackBTQ *stack, SNode node) //元素进栈
{
    if (!CheckQueueIsEmpty(stack->QueueMain) && CheckQueueIsFull(stack->QueueAssist))
    {
        printf("栈已满，入栈失败\n");
        return;
    }

    if (CheckQueueIsFull(stack->QueueMain) && CheckQueueIsEmpty(stack->QueueAssist))
    {   
        while(!CheckQueueIsEmpty(stack->QueueMain))
        {
            QueuePush(&(stack->QueueAssist), QueuePop(&(stack->QueueMain)));
        }
    }
    QueuePush(&(stack->QueueMain), node);
}

SNode StackBTQPop(StackBTQ *stack) //元素出栈
{
    SNode node;
    if (CheckQueueIsEmpty(stack->QueueMain) && CheckQueueIsEmpty(stack->QueueAssist))
    {
        printf("出栈失败，栈已空\n");
        exit(0);
    }

    while(GetQueueCount(stack->QueueMain) > 1)
    {
        QueuePush(&(stack->QueueAssist), QueuePop(&(stack->QueueMain)));
    }
    node = QueuePop(&(stack->QueueMain));

    while(! CheckQueueIsEmpty(stack->QueueAssist))
    {
        QueuePush(&(stack->QueueMain), QueuePop(&(stack->QueueAssist)));
    }

    return node;
}

int GetStackBTQCount(const StackBTQ stack) //获取栈中元素的个数
{
    return GetQueueCount(stack.QueueMain) + GetQueueCount(stack.QueueAssist);
}

SNode GetStackBTQTop(const StackBTQ stack)//获取栈顶元素
{
    if (CheckQueueIsEmpty(stack.QueueMain) && CheckQueueIsEmpty(stack.QueueAssist))
    {
        printf("获取栈顶元素失败，栈已空\n");
        exit(0);
    }
    return GetQueueTop(stack.QueueMain);
}

SNode GetStackBTQTail(const StackBTQ stack)//获取栈底元素
{
    if (CheckQueueIsEmpty(stack.QueueMain) && CheckQueueIsEmpty(stack.QueueAssist))
    {
        printf("获取栈底元素失败，栈已空\n");
        exit(0);
    }
    if (!CheckQueueIsEmpty(stack.QueueAssist))
    {
        return GetQueueTail(stack.QueueAssist);
    }
    return GetQueueTail(stack.QueueMain);
}

void StackBTQTest(void) //测试StackBTQ栈
{
    StackBTQ stack;
    SNode Node[15];
    int i;
    StackBTQInit(&stack);
    for (i = 0; i<15; i++)
    {
        Node[i].data = i+1;
    }
    for (i = 0; i<4; i++)
    {
        StackBTQPush(&stack, Node[i]);
        printf("进栈-->%d\n", Node[i].data);
    }
    printf("栈中有%d个元素\n", GetStackBTQCount(stack));
    printf("栈顶元素为%d\n", GetStackBTQTop(stack).data);
    printf("栈底元素为%d\n\n", GetStackBTQTail(stack).data);

    printf("出栈-->%d\n", StackBTQPop(&stack).data);
    printf("栈中有%d个元素\n", GetStackBTQCount(stack));
    printf("栈顶元素为%d\n", GetStackBTQTop(stack).data);
    printf("栈底元素为%d\n\n", GetStackBTQTail(stack).data);

    for (i = 4; i<8; i++)
    {
        StackBTQPush(&stack, Node[i]);
        printf("进栈-->%d\n", Node[i].data);
    }
    printf("栈中有%d个元素\n", GetStackBTQCount(stack));
    printf("栈顶元素为%d\n", GetStackBTQTop(stack).data);
    printf("栈底元素为%d\n\n", GetStackBTQTail(stack).data);

    for (i = 8; i<9; i++)
    {
        StackBTQPush(&stack, Node[i]);
        printf("进栈-->%d\n", Node[i].data);
    }
    printf("栈中有%d个元素\n", GetStackBTQCount(stack));
    printf("栈顶元素为%d\n", GetStackBTQTop(stack).data);
    printf("栈底元素为%d\n\n", GetStackBTQTail(stack).data);

    for (i = 1; i<10; i++)
    {
        printf("出栈-->%d\n", StackBTQPop(&stack).data); 
        printf("栈中有%d个元素\n", GetStackBTQCount(stack));
        printf("栈顶元素为%d\n", GetStackBTQTop(stack).data);
        printf("栈底元素为%d\n\n", GetStackBTQTail(stack).data);
    }


}
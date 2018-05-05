#include "StackByTwoQueue.h"

void StackBTQInit(StackBTQ *stack) //��ʼ��
{
   assert(stack);
   CircleQueueInit(&(stack->QueueMain));
   CircleQueueInit(&(stack->QueueAssist));
}

void StackBTQPush(StackBTQ *stack, SNode node) //Ԫ�ؽ�ջ
{
    if (!CheckQueueIsEmpty(stack->QueueMain) && CheckQueueIsFull(stack->QueueAssist))
    {
        printf("ջ��������ջʧ��\n");
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

SNode StackBTQPop(StackBTQ *stack) //Ԫ�س�ջ
{
    SNode node;
    if (CheckQueueIsEmpty(stack->QueueMain) && CheckQueueIsEmpty(stack->QueueAssist))
    {
        printf("��ջʧ�ܣ�ջ�ѿ�\n");
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

int GetStackBTQCount(const StackBTQ stack) //��ȡջ��Ԫ�صĸ���
{
    return GetQueueCount(stack.QueueMain) + GetQueueCount(stack.QueueAssist);
}

SNode GetStackBTQTop(const StackBTQ stack)//��ȡջ��Ԫ��
{
    if (CheckQueueIsEmpty(stack.QueueMain) && CheckQueueIsEmpty(stack.QueueAssist))
    {
        printf("��ȡջ��Ԫ��ʧ�ܣ�ջ�ѿ�\n");
        exit(0);
    }
    return GetQueueTop(stack.QueueMain);
}

SNode GetStackBTQTail(const StackBTQ stack)//��ȡջ��Ԫ��
{
    if (CheckQueueIsEmpty(stack.QueueMain) && CheckQueueIsEmpty(stack.QueueAssist))
    {
        printf("��ȡջ��Ԫ��ʧ�ܣ�ջ�ѿ�\n");
        exit(0);
    }
    if (!CheckQueueIsEmpty(stack.QueueAssist))
    {
        return GetQueueTail(stack.QueueAssist);
    }
    return GetQueueTail(stack.QueueMain);
}

void StackBTQTest(void) //����StackBTQջ
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
        printf("��ջ-->%d\n", Node[i].data);
    }
    printf("ջ����%d��Ԫ��\n", GetStackBTQCount(stack));
    printf("ջ��Ԫ��Ϊ%d\n", GetStackBTQTop(stack).data);
    printf("ջ��Ԫ��Ϊ%d\n\n", GetStackBTQTail(stack).data);

    printf("��ջ-->%d\n", StackBTQPop(&stack).data);
    printf("ջ����%d��Ԫ��\n", GetStackBTQCount(stack));
    printf("ջ��Ԫ��Ϊ%d\n", GetStackBTQTop(stack).data);
    printf("ջ��Ԫ��Ϊ%d\n\n", GetStackBTQTail(stack).data);

    for (i = 4; i<8; i++)
    {
        StackBTQPush(&stack, Node[i]);
        printf("��ջ-->%d\n", Node[i].data);
    }
    printf("ջ����%d��Ԫ��\n", GetStackBTQCount(stack));
    printf("ջ��Ԫ��Ϊ%d\n", GetStackBTQTop(stack).data);
    printf("ջ��Ԫ��Ϊ%d\n\n", GetStackBTQTail(stack).data);

    for (i = 8; i<9; i++)
    {
        StackBTQPush(&stack, Node[i]);
        printf("��ջ-->%d\n", Node[i].data);
    }
    printf("ջ����%d��Ԫ��\n", GetStackBTQCount(stack));
    printf("ջ��Ԫ��Ϊ%d\n", GetStackBTQTop(stack).data);
    printf("ջ��Ԫ��Ϊ%d\n\n", GetStackBTQTail(stack).data);

    for (i = 1; i<10; i++)
    {
        printf("��ջ-->%d\n", StackBTQPop(&stack).data); 
        printf("ջ����%d��Ԫ��\n", GetStackBTQCount(stack));
        printf("ջ��Ԫ��Ϊ%d\n", GetStackBTQTop(stack).data);
        printf("ջ��Ԫ��Ϊ%d\n\n", GetStackBTQTail(stack).data);
    }


}
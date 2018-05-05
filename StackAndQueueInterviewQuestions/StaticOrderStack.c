
#include "StaticOrderStack.h"

void StaticStackInit(SStack *Stack) //��̬ջ�ĳ�ʼ��
{
    assert(Stack);
    Stack->bottom = 0;
    Stack->top = 0;
}

int CheckStackIsFull(const SStack stack)    //���ջ�Ƿ���, û������0�����˷���1
{
    return ((stack.top) < MAXLEN)?0:1;
}

int StackPush(SStack *stack, SNode node)    //Ԫ����ջ,�ɹ�����1��ʧ�ܷ���0
{
    assert(stack);
    if (!CheckStackIsFull(*stack))
    {
        stack->top++;
        stack->Node[stack->top-1] = node;
        return 1;
    }
    printf("ջ��������ջʧ��\n");
    return 0;
}

int CheckStackIsEmpty(const SStack stack)//���ջ�Ƿ�Ϊ��,Ϊ�շ���0����Ϊ�շ���1
{
    return stack.top <= stack.bottom ? 1 : 0;
}

SNode StackPop(SStack *stack)//Ԫ�س�ջ����ջ�ɹ����س�����Ԫ�أ���ջʧ��������˳�
{
    assert(stack);
    if (!CheckStackIsEmpty(*stack))
    {
        SNode node = stack->Node[stack->top-1];
        stack->top--;
        return node;
    }
    else
    {
        printf("ջ�ѿգ���ջʧ��\n");
        exit(0);
    }
}

int GetStackNodeCount(const SStack stack)  //��ȡջ��Ԫ�ظ���
{
    return (stack.top)-(stack.bottom);
}

SNode GetStackTop(const SStack stack)   //��ȡջ��Ԫ��
{
    if(!CheckStackIsEmpty(stack))
        return stack.Node[stack.top-1]; 
    else
        printf("����ջΪ��\n");
}



void StaticStackTest(void)
{
    SStack stack;
    SNode Node[MAXLEN];
    int i = 0;
    SNode node;
    for (i = 0; i<MAXLEN; i++)
    {
        Node[i].data = (i+1)*10+i+1;
    }
    StaticStackInit(&stack);
    printf("ջ��Ԫ�ظ���Ϊ-->%d\n", GetStackNodeCount(stack));
    for (i = 0; i<MAXLEN; i++)
    {
        StackPush(&stack, Node[i]);
        printf("��ջ-->%d\n", Node[i].data);
    }
    node.data = 99999;
    StackPush(&stack, node);
    for (i = 0; i<MAXLEN; i++)
    {
        printf("��ջ-->%d\n", StackPop(&stack).data);
    }
    printf("��ջ-->%d\n", StackPop(&stack).data);
}
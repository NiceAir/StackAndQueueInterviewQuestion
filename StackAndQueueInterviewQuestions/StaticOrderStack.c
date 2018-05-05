
#include "StaticOrderStack.h"

void StaticStackInit(SStack *Stack) //静态栈的初始化
{
    assert(Stack);
    Stack->bottom = 0;
    Stack->top = 0;
}

int CheckStackIsFull(const SStack stack)    //检查栈是否满, 没满返回0，满了返回1
{
    return ((stack.top) < MAXLEN)?0:1;
}

int StackPush(SStack *stack, SNode node)    //元素入栈,成功返回1，失败返回0
{
    assert(stack);
    if (!CheckStackIsFull(*stack))
    {
        stack->top++;
        stack->Node[stack->top-1] = node;
        return 1;
    }
    printf("栈已满，入栈失败\n");
    return 0;
}

int CheckStackIsEmpty(const SStack stack)//检查栈是否为空,为空返回0。不为空返回1
{
    return stack.top <= stack.bottom ? 1 : 0;
}

SNode StackPop(SStack *stack)//元素出栈。出栈成功返回出来的元素，出栈失败则程序退出
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
        printf("栈已空，出栈失败\n");
        exit(0);
    }
}

int GetStackNodeCount(const SStack stack)  //获取栈中元素个数
{
    return (stack.top)-(stack.bottom);
}

SNode GetStackTop(const SStack stack)   //获取栈顶元素
{
    if(!CheckStackIsEmpty(stack))
        return stack.Node[stack.top-1]; 
    else
        printf("错误，栈为空\n");
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
    printf("栈中元素个数为-->%d\n", GetStackNodeCount(stack));
    for (i = 0; i<MAXLEN; i++)
    {
        StackPush(&stack, Node[i]);
        printf("进栈-->%d\n", Node[i].data);
    }
    node.data = 99999;
    StackPush(&stack, node);
    for (i = 0; i<MAXLEN; i++)
    {
        printf("出栈-->%d\n", StackPop(&stack).data);
    }
    printf("出栈-->%d\n", StackPop(&stack).data);
}
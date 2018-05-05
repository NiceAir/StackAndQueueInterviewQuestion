#include "QueueByTwoStack.h"

void QueueBTSInit(QueueBTS *queue)  //初始化
{
    assert(queue);
    StaticStackInit(&(queue->StackIn));
    StaticStackInit(&(queue->StackOut));
}

void QueueBTSPush(QueueBTS *queue, SNode Node) //进队列
{
    assert(queue);
    if (CheckStackIsFull(queue->StackIn) && !CheckStackIsEmpty(queue->StackOut))
    {
        printf("进队列失败，队列已满\n");
        return;
    }
    if (CheckStackIsFull(queue->StackIn))
    {
        while(!CheckStackIsEmpty(queue->StackIn))
        {
            StackPush(&(queue->StackOut), StackPop(&(queue->StackIn)));   
        }
    }
    StackPush(&(queue->StackIn), Node);
}

SNode QueueBTSPop(QueueBTS *queue)  //出队列
{
    assert(queue);
    if (CheckStackIsEmpty(queue->StackIn) && CheckStackIsEmpty(queue->StackOut))
    {
        printf("错误，当前队列中为空\n");
        exit(0);
    }
    if (CheckStackIsEmpty(queue->StackOut))
    {
        while(!CheckStackIsEmpty(queue->StackIn))
        {
            StackPush(&(queue->StackOut), StackPop(&(queue->StackIn)));   
        }
    }
    return StackPop(&(queue->StackOut));
}

int GetQueueBTSNodeCount(QueueBTS queue)    //获取队列中元素的个数
{
    return GetStackNodeCount(queue.StackIn) + GetStackNodeCount(queue.StackOut);
}

void QueueBTSTest(void) //测试QueueBTS队列
{
    QueueBTS queue;
    SNode Node[15];
    int i = 0;
    QueueBTSInit(&queue);
    for (i = 0; i<15; i++)
        Node[i].data = i+1;
    for (i = 0; i<7; i++)
        QueueBTSPush(&queue, Node[i]);
    printf("队列中有%d个元素\n\n", GetQueueBTSNodeCount(queue));
    for (i = 7; i<15; i++)
    {   
        QueueBTSPush(&queue, Node[i]);
        printf("队列中有%d个元素\n\n", GetQueueBTSNodeCount(queue));
    }
    for (i = 0; i<15; i++)
    {
        printf("出队列-->%d\n", QueueBTSPop(&queue).data);
        printf("队列中有%d个元素\n\n", GetQueueBTSNodeCount(queue));
    }
   

}
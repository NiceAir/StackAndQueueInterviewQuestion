#include "SequentialLoopQueue.h"

void CircleQueueInit(CQueue *queue)    //顺序循环队列初始化
{
    assert(queue);
    queue->front = 0;
    queue->tail = 0;
}

int CheckQueueIsFull(const CQueue queue)//判断队列是否满了。队列满则返回1，没满则返回0。
{
    if (queue.tail == MAXLEN-1 && queue.front == 0)
        return 1;
    if (queue.front == queue.tail+1)
        return 1;
    return 0;
}

void QueuePush(CQueue *queue, SNode node)//元素入队列
{
    assert(queue);
    if (!CheckQueueIsFull(*queue))
    {
        if (queue->tail == MAXLEN-1)
            queue->tail = 0;
        else
            queue->tail++;
        queue->Node[queue->tail] = node;
    }
    else
        printf("入队列失败，队列已满\n");
}

int CheckQueueIsEmpty(const CQueue queue)//判断队列是否为空。为空则返回1，否则返回0。
{
    return (queue.front == queue.tail);
}

SNode QueuePop(CQueue *queue)//元素出队列
{
    assert(queue);
    if (!CheckQueueIsEmpty(*queue))
    {
        if (queue->front == MAXLEN-1)
            queue->front = 0;
        else
            queue->front++;
        return queue->Node[queue->front];
    }
    printf("出队列失败，队列已空\n");
    exit(0);
}

int GetQueueCount(const CQueue queue)//获取队列中元素的个数
{
    int count = 0;
    int point = queue.front;
    while(point != queue.tail)
    {
        if (point == MAXLEN-1)
            point = 0;
        else
            point++;
        count++;
    }
    return count;
}

SNode GetQueueTop(const CQueue queue) //获取最后进队列的元素
{
    if (CheckQueueIsEmpty(queue))
    {
        printf("获取最后进队列元素失败，队列为空\n");
        exit(0);
    }
    return queue.Node[queue.tail];
}

SNode GetQueueTail(const CQueue queue) //获取最早进队列的元素
{
    if (CheckQueueIsEmpty(queue))
    {
        printf("获取最早进队列元素失败，队列为空\n");
        exit(0);
    }
    if (queue.front == MAXLEN -1)
    {
        return queue.Node[0];
    }
    return queue.Node[queue.front+1];
}

void CircleQueueTest(void)//测试循环队列
{
    CQueue queue;
    SNode Node[10];
    int i = 0;
    for (i = 0; i<10; i++)
    {
        Node[i].data = (i+1)*10+i+1;
    }
    CircleQueueInit(&queue);
    for (i = 0; i<MAXLEN-1; i++)
    {
        QueuePush(&queue, Node[i]);
        printf("进队列-->%d\n", Node[i].data);
    }
    QueuePush(&queue, Node[i]);
    printf("此时有%d个元素\n\n",GetQueueCount(queue));
    for (i = 1; i<3; i++)
    {
        printf("出队列-->%d\n", QueuePop(&queue));
    }
    printf("此时有%d个元素\n\n",GetQueueCount(queue));
    QueuePush(&queue, Node[5]);
    printf("进队列-->%d\n", Node[5].data);
    QueuePush(&queue, Node[6]);
    printf("进队列-->%d\n", Node[6].data);
    printf("此时有%d个元素\n\n",GetQueueCount(queue));
    for (i = 1; i<8; i++)
    {
        printf("出队列-->%d\n", QueuePop(&queue));
    }
    printf("此时有%d个元素\n\n",GetQueueCount(queue));
    
}
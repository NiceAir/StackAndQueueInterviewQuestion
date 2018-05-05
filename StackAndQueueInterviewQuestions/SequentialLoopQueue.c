#include "SequentialLoopQueue.h"

void CircleQueueInit(CQueue *queue)    //˳��ѭ�����г�ʼ��
{
    assert(queue);
    queue->front = 0;
    queue->tail = 0;
}

int CheckQueueIsFull(const CQueue queue)//�ж϶����Ƿ����ˡ��������򷵻�1��û���򷵻�0��
{
    if (queue.tail == MAXLEN-1 && queue.front == 0)
        return 1;
    if (queue.front == queue.tail+1)
        return 1;
    return 0;
}

void QueuePush(CQueue *queue, SNode node)//Ԫ�������
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
        printf("�����ʧ�ܣ���������\n");
}

int CheckQueueIsEmpty(const CQueue queue)//�ж϶����Ƿ�Ϊ�ա�Ϊ���򷵻�1�����򷵻�0��
{
    return (queue.front == queue.tail);
}

SNode QueuePop(CQueue *queue)//Ԫ�س�����
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
    printf("������ʧ�ܣ������ѿ�\n");
    exit(0);
}

int GetQueueCount(const CQueue queue)//��ȡ������Ԫ�صĸ���
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

SNode GetQueueTop(const CQueue queue) //��ȡ�������е�Ԫ��
{
    if (CheckQueueIsEmpty(queue))
    {
        printf("��ȡ��������Ԫ��ʧ�ܣ�����Ϊ��\n");
        exit(0);
    }
    return queue.Node[queue.tail];
}

SNode GetQueueTail(const CQueue queue) //��ȡ��������е�Ԫ��
{
    if (CheckQueueIsEmpty(queue))
    {
        printf("��ȡ���������Ԫ��ʧ�ܣ�����Ϊ��\n");
        exit(0);
    }
    if (queue.front == MAXLEN -1)
    {
        return queue.Node[0];
    }
    return queue.Node[queue.front+1];
}

void CircleQueueTest(void)//����ѭ������
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
        printf("������-->%d\n", Node[i].data);
    }
    QueuePush(&queue, Node[i]);
    printf("��ʱ��%d��Ԫ��\n\n",GetQueueCount(queue));
    for (i = 1; i<3; i++)
    {
        printf("������-->%d\n", QueuePop(&queue));
    }
    printf("��ʱ��%d��Ԫ��\n\n",GetQueueCount(queue));
    QueuePush(&queue, Node[5]);
    printf("������-->%d\n", Node[5].data);
    QueuePush(&queue, Node[6]);
    printf("������-->%d\n", Node[6].data);
    printf("��ʱ��%d��Ԫ��\n\n",GetQueueCount(queue));
    for (i = 1; i<8; i++)
    {
        printf("������-->%d\n", QueuePop(&queue));
    }
    printf("��ʱ��%d��Ԫ��\n\n",GetQueueCount(queue));
    
}
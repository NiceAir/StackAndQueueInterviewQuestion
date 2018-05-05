#include "QueueByTwoStack.h"

void QueueBTSInit(QueueBTS *queue)  //��ʼ��
{
    assert(queue);
    StaticStackInit(&(queue->StackIn));
    StaticStackInit(&(queue->StackOut));
}

void QueueBTSPush(QueueBTS *queue, SNode Node) //������
{
    assert(queue);
    if (CheckStackIsFull(queue->StackIn) && !CheckStackIsEmpty(queue->StackOut))
    {
        printf("������ʧ�ܣ���������\n");
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

SNode QueueBTSPop(QueueBTS *queue)  //������
{
    assert(queue);
    if (CheckStackIsEmpty(queue->StackIn) && CheckStackIsEmpty(queue->StackOut))
    {
        printf("���󣬵�ǰ������Ϊ��\n");
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

int GetQueueBTSNodeCount(QueueBTS queue)    //��ȡ������Ԫ�صĸ���
{
    return GetStackNodeCount(queue.StackIn) + GetStackNodeCount(queue.StackOut);
}

void QueueBTSTest(void) //����QueueBTS����
{
    QueueBTS queue;
    SNode Node[15];
    int i = 0;
    QueueBTSInit(&queue);
    for (i = 0; i<15; i++)
        Node[i].data = i+1;
    for (i = 0; i<7; i++)
        QueueBTSPush(&queue, Node[i]);
    printf("��������%d��Ԫ��\n\n", GetQueueBTSNodeCount(queue));
    for (i = 7; i<15; i++)
    {   
        QueueBTSPush(&queue, Node[i]);
        printf("��������%d��Ԫ��\n\n", GetQueueBTSNodeCount(queue));
    }
    for (i = 0; i<15; i++)
    {
        printf("������-->%d\n", QueueBTSPop(&queue).data);
        printf("��������%d��Ԫ��\n\n", GetQueueBTSNodeCount(queue));
    }
   

}
以静态顺序栈（StaticOrderStack.h）和顺序环形队列（SequentialLoopQueue.h）为基础，完成了以下操作：

实现一个栈，要求实现Push(出栈)、Pop(入栈)、Min(返回最小值)的时间复杂度为O(1)。
相应头文件为：MinTimeStack.h

使用两个栈实现一个队列。
相应头文件为：QueueByTwoStack.h

使用两个队列实现一个栈。
相应头文件为：StackByTwoQueue.h

元素出栈、入栈顺序的合法性。如入栈的序列(1,2,3,4,5)，出栈序列为(4,5,3,2,1)。
相应函数为：int CheckInstackOutstackLegale(char instr[], int lenin, char outstr[], int lenout)；
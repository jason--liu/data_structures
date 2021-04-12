#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;
typedef int ElemType;

#define stackSize 100

typedef struct SeqStack {
    ElemType stack[stackSize];
    int top;
} SeqStack;

/* 1.栈的初始化
 * 2.取栈顶元素
 * 3.压栈：在栈S中插入元素e，使其成为新的栈顶元素
 * 4.出栈：删除S中的栈顶元素
 * 5.判断栈空
 */

//栈的初始化
Bool init(SeqStack* pStack)
{
    pStack->top = 0;
    return TRUE;
}

//栈的判空
Bool isEmpty(SeqStack* pStack) { return (pStack->top == 0); }

//压栈
// pStack表示顺序栈，x表示压入元素
Bool pushStack(SeqStack* pStack, ElemType x)
{
    if (pStack->top == stackSize) {
        printf("空间溢出\n");
        return FALSE;
    }
    pStack->top++;
    pStack->stack[pStack->top] = x;
    return TRUE;
}

//出栈
ElemType popStack(SeqStack* pStack)
{
    ElemType tmp;
    if (pStack->top == 0) {
        printf("当前是空栈\n");
        return -1;
    }
    tmp = pStack->stack[pStack->top];
    pStack->top--;  //逻辑上出栈
    return tmp;
}

//十进制转为二进制
void myConv(SeqStack* pStack, int n)
{
    int e;  //每一个元素
    while (n) {
        pushStack(pStack, n % 8);
        n = n / 8;
    }
    while (!isEmpty(pStack)) {
        e = popStack(pStack);
        printf("%d ", e);
    }
}

//获取栈顶元素
Bool GetSeqStack(SeqStack* s, ElemType* data)
{
    if (s->top == 0)
        return FALSE;

    *data = s->stack[s->top];
    return TRUE;
}
int main()
{
    SeqStack s;
    init(&s);
    printf("十进制1348,转为8进制:\n");
    myConv(&s, 1348);
    getchar();
    return 0;
}

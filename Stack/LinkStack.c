#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node {
    datatype data;
    struct node* pNext;
} LinkStack;

//入栈
LinkStack* PushLkStack(LinkStack* top, datatype x)
{
    LinkStack* p;
    p = (LinkStack*)malloc(sizeof(LinkStack));
    p->data = x;
    p->pNext = top;  //类似于首先将p链入链表
    top = p;
    return top;
}

//出栈
LinkStack* PopLkStack(LinkStack* top, datatype* pData)
{
    LinkStack* p;
    //一旦我们出栈，那么我们认为这个元素就不应当维护链表指向的关系了
    if (top != NULL) {
        *pData = top->data;
        p = top;  //此时将当前栈顶元素位置保存下来
        top = p->pNext;
        free(p);
    }
    return top;
}

int main()
{
    LinkStack* pTop = NULL; // debug me
    pTop = PushLkStack(pTop, 1);
    pTop = PushLkStack(pTop, 1);
    getchar();
    return 0;
}

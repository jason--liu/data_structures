#include <stdio.h>
#include <stdlib.h>
typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DLinkListNode;

DLinkListNode* Delete_DL(DLinkListNode* ptr)
{
    ptr->prior->next = ptr->next;
    ptr->next->prior = ptr->prior;
    return ptr;
}

void Insert_Before_DL(DLinkListNode* p, int x)

{
    DLinkListNode* s;
    s = (DLinkListNode*)malloc(sizeof(DLinkListNode));
    s->data = x;
    //将s的关系加入到链表
    s->prior = p->prior;
    if (p->prior)
        p->prior->next = s;
    s->next = p;
    p->prior = s;
}

int main()
{
    DLinkListNode x;
    DLinkListNode* head;
    DLinkListNode* ptr;

    ptr = &x;
    ptr->data = 3;
    ptr->prior = NULL;
    ptr->next = NULL;

    Insert_Before_DL(ptr, 1);
    Insert_Before_DL(ptr, 2);
    DLinkListNode *p, *q;
    p = &x;
    while (p) {
        printf("%d\n", p->data);
        if (!p->prior)
            q = p;  // q记录了第一个节点
        p = p->prior;
    }
    while (q) {
        printf("%d\n", q->data);
        q = q->next;
    }

    getchar();
    return 0;
}

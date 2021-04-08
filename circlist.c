#include <stdio.h>
#include <stdlib.h>

//循环链表的建立
//输入：顺序表集合，顺序表长度
//输出：循环链表的尾地址
typedef struct node {
    int data;
    struct node* pNext;
} LinkCircleListNode;

LinkCircleListNode* Create_Cricle_LkList(int arr[], int length)
{
    LinkCircleListNode *head, *p, *q;
    int i;

    head = (LinkCircleListNode*)malloc(sizeof(LinkCircleListNode));
    q = head;

    for (i = 0; i < length; i++) {
        p = (LinkCircleListNode*)malloc(sizeof(LinkCircleListNode));
        p->data = arr[i];
        q->pNext = p;
        q = p;
    }

    p->pNext = head;
    return p;
}

int main()
{
    int arr[] = {11, 22, 33, 44, 55};
    LinkCircleListNode* pRear = Create_Cricle_LkList(arr, 5);

    LinkCircleListNode* p = pRear->pNext;  // p=head

    // 因为遍历的时候，我们希望获得的是真正元素，
    // 所以首先让p移到
    p = p->pNext;  // p指向真正第一个元素
    /* while (p->pNext != pRear->pNext) { */
    // Fixme
    while (p != pRear->pNext) {
        printf("%d\n", p->data);
        p = p->pNext;
    }
    getchar();
    return 0;
}

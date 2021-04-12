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

// 遍历输出
void ShowCircleLkList(LinkCircleListNode* pRear)
{
    LinkCircleListNode* p = pRear->pNext;
    // 因为遍历的时候，我们希望获得的是真正元素，
    // 所以首先让p移到
    p = p->pNext;  // p指向真正第一个元素
    /* while (p->pNext != pRear->pNext) { */
    // Fixme
    while (p != pRear->pNext) {
        printf("%d\n", p->data);
        p = p->pNext;
    }
}

//两个循环链表合并
//输入为链表a的尾指针，a链表b的尾指针
LinkCircleListNode* Connect_Circle_LkList(LinkCircleListNode* ra,
                                          LinkCircleListNode* rb)
{
    LinkCircleListNode* p;
    //记录a的头节点
    p = ra->pNext;
    //将b的第一个元素节点链入a的尾部
    ra->pNext = rb->pNext->pNext;
    free(rb->pNext);
    rb->pNext = p;

    return rb;
}
int main()
{
    int arr[] = {11, 22, 33, 44, 55};
    LinkCircleListNode* pRear = Create_Cricle_LkList(arr, 5);

    /* ShowCircleLkList(pRear); */
    //测试合并
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    LinkCircleListNode *ra, *rb;
    ra = Create_Cricle_LkList(a, 3);
    rb = Create_Cricle_LkList(b, 3);

    pRear = Connect_Circle_LkList(ra, rb);
    ShowCircleLkList(pRear);

    getchar();
    return 0;
}

#include "LinkList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void LinkList_Test(void)
{
    LinkListNode *xPtr = NULL, *yPtr = NULL, *p = NULL;
    xPtr = (LinkListNode*)malloc(sizeof(LinkListNode));

    if (xPtr) {
        xPtr->pNext = NULL;
        xPtr->data = 100;
    }

    yPtr = (LinkListNode*)malloc(sizeof(LinkListNode));
    if (yPtr) {
        yPtr->data = 200;
        yPtr->pNext = NULL;
    }

    //非常关键
    xPtr->pNext = yPtr;
}

//创建带有头节点的空链表
LinkListNode* InitLinkList(void)
{
    LinkListNode* pHead = NULL;

    pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
    if (pHead) {
        pHead->pNext = NULL;
    }
    return pHead;
}

//求长度：求链表中的元素个数
int GetSizeLinkList(LinkListNode* pHead)
{
    int n = 0;
    //依次遍历每个元素
    while (pHead->pNext) {
        n++;
        pHead = pHead->pNext;
    }
    return n;
}

//取元素：取给定位置的元素指
//输入链表的头指针，要查找的编号，输出第i个元素的地址
// PHead:头指针
// pos:待查节点序号
LinkListNode* GetLinkListNode(LinkListNode* pHead, int pos)
{
    int j = 0;
    LinkListNode* p;
    p = pHead;

    if (pos == 0)
        return NULL;

    while (j < pos && p->pNext != NULL) {
        p = p->pNext;
        j++;
    }
    if (pos == j)
        return p;
    else
        return NULL;

    // TODO
}

//查元素：查找给定元素指的位置
//找到返回节点地址，否则返回NULL
LinkListNode* LocateLinkList(LinkListNode* pHead, int data)
{
    LinkListNode* p = NULL;

    p = p->pNext;  //跳过头节点
    while (p != NULL && p->data != data) {
        p = p->pNext;
    }

    return p;
}

//插入元素：在指定的位置插入给定的指
//因为链表这种结构的内存是由程序员管理，因此它的建立有一定的运算方法
//尾插法建立单链表，将逻辑上的顺序表放入单链表的结构中
//顺序表: 12,33,44,76,89,90(逻辑上的顺序表) => 单链表
//本例中我们用数组表示顺序表
// arr：顺序表 length:顺序表长度
LinkListNode* Create_Real_LkList(ElemType arr[], int length)
{
    LinkListNode *pHead, *p, *q;
    int i;  //循环变量，用来遍历全部顺序表

    pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
    q = pHead;  // q是获得了当前链表头节点

    for (i = 0; i < length; i++) {
        //获得一个单链表节点，将这个节点加入到pHead为头的链表中
        // p是一个可以加入链表的节点单元
        p = (LinkListNode*)malloc(sizeof(LinkListNode));
        p->data = arr[i];  //将顺序表的内存存入单链表节点

        q->pNext = p;
        q = p;  //把q移动到当前p节点
    }

    p->pNext = NULL;

    return pHead;
}

//头插法建立单链表1
LinkListNode* Create_Front_LkList(ElemType arr[], int length)
{
    LinkListNode *pHead, *p, *q;
    int i;  //循环变量，用来遍历全部顺序表

    pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
    pHead->pNext = NULL;
    q = pHead->pNext;
    //头插逆序遍历顺序表
    for (i = length - 1; i >= 0; i--) {
        p = (LinkListNode*)malloc(sizeof(LinkListNode));
        p->data = arr[i];
        p->pNext = q;      //使得新加入的节点串入了上一个节点
        pHead->pNext = p;  //头节点指向了当前新加入的节点
        q = pHead->pNext;  //让q指向当前的节点
    }

    return pHead;
}

//头插法建立单链表2
LinkListNode* Create_Front_LkList2(ElemType arr[], int length)
{
    LinkListNode *pHead, *p, *q;  // p是新加入的节点,q是当前节点
    int i;                        //循环变量，用来遍历全部顺序表
    q = NULL;
    for (i = length - 1; i >= 0; i--) {
        p = (LinkListNode*)malloc(sizeof(LinkListNode));
        p->data = arr[i];
        p->pNext = q;
        p = q;
    }
    pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
    pHead->pNext = q;

    return pHead;
}

//头插法建立单链表3
LinkListNode* Create_Front_LkList3(ElemType arr[], int length)
{
    LinkListNode *pHead, *p;
    int i;

    pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
    pHead->pNext = NULL;

    for (i = length - 1; i >= 0; i--) {
        p = (LinkListNode*)malloc(sizeof(LinkListNode));
        p->data = arr[i];
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    //之所以方法3可以节省方法1中的一个变量q
    //是因为，pHead不发生变化，而pHead中的pNext始终作为当前节点的指针
    return pHead;
}

//插入元素：在指定的位置插入给定的指
//在指定位置之后插入
void Insert_After_LkList(LinkListNode* ptr, ElemType x)
{
    LinkListNode* s;
    s = (LinkListNode*)malloc(sizeof(LinkListNode));
    s->data = x;
    s->pNext = ptr->pNext;
    ptr->pNext = s;
}

void Insert_Before_LkList(LinkListNode* pHead, LinkListNode* ptr, ElemType x)
{
    LinkListNode *s, *qPtr;
    s = (LinkListNode*)malloc(sizeof(LinkListNode));
    s->data = x;
    qPtr = pHead;  // qPtr是用来代替pHead来移动的
    while (qPtr->pNext != ptr)
        qPtr = qPtr->pNext;
    s->pNext = ptr;
    qPtr->pNext = s;

    //因为链表是单向的，虽然我知道当前节点是ptr
    //但是在语法层面上，我如果想知道ptr的前继节点只能从head遍历而来
    //查到了当前节点的前继，才能使用后插完成节点的加入
}

//删除:删除指定位置的值或者删除给定的值
//情形1：删除指定节点的后继节点
//情形2：删除第i个节点，假定头节点i=0
//删除返回目标节点的地址，并不涉及到动态空间的回收
//在动态回收空间的要求中，应该遵循原则是“谁污染谁治理”
//在顺序表中的删除就是逻辑上的删除，就是说节点不再存在于当前顺序表中
//删除节点：Ptr是需要删除的节点，将删除ptr的后继节点
LinkListNode* Delete_After_Lklist(LinkListNode* ptr)
{
    LinkListNode* fptr;
    //假定顺序表是A->B->C，假定要删除的是A的后续节点B，A->C
    fptr = ptr->pNext;         // ptr是A，ptr的next是B，所以fptr是B
    ptr->pNext = fptr->pNext;  // ptr是A，fptr是B，所以fptr->pNext是C
    return fptr;
}

//删除第i个节点
LinkListNode* Delete_i_LkList(LinkListNode* pHead, int i)
{
    LinkListNode *ptr, *qPtr = NULL;
    ptr = GetLinkListNode(pHead, i - 1);  //找到i的前继节点
    if (ptr != NULL && ptr->pNext != NULL)
        qPtr = Delete_After_Lklist(ptr);

    return qPtr;
}

//遍历
void ShowLklist(LinkListNode* pHead)
{
    LinkListNode* p = pHead->pNext;
    while (p != NULL) {
        printf(" %d", p->data);
        p = p->pNext;
    }
}
#if 0
int main()
{
#if 0
    LinkListNode x, y, *p;
    p = &x;
    x.data = 100;
    x.pNext = NULL;

    y.data = 200;
    y.pNext = NULL;

    x.pNext = &y;

    printf("y.data %d\n", x.pNext->data);
#endif
    /* LinkList_Test(); */
    LinkListNode* pHead = NULL;

    ElemType MySeq[] = {1, 2, 3, 4, 5};
    /* pHead = Create_Real_LkList(MySeq, 5); */
    pHead = Create_Front_LkList(MySeq, 5);
    printf("显示当前链表全部元素\n");
    ShowLklist(pHead);

    //插入测试
    LinkListNode* pPos = GetLinkListNode(pHead, 2);
    Insert_After_LkList(pPos, 999);
    printf("显示当前链表全部元素\n");
    ShowLklist(pHead);
    Insert_Before_LkList(pHead, pPos, 666);
    printf("显示当前链表全部元素\n");
    ShowLklist(pHead);

    //删除测试
    Delete_After_Lklist(pPos);
    printf("显示当前链表全部元素\n");
    ShowLklist(pHead);

    //求长度
    printf("list size : %d\n", GetSizeLinkList(pHead));

    getchar();
    return 0;
}
#endif

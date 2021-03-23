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

    if (pos == 0) return NULL;

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

    ElemType MySeq[] = {1, 2, 3, 4, 5};
    Create_Real_LkList(MySeq, 5);
    Create_Front_LkList(MySeq, 5);
    getchar();
    return 0;
}

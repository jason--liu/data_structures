#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int ElemType;
//
typedef struct node {
    int data;
    struct node* pNext;
} LinkListNode;
//求长度：求链表中的元素个数
int GetSizeLinkList(LinkListNode* pHead);
//取元素：取给定位置的元素指
//输入链表的头指针，要查找的编号，输出第i个元素的地址
// PHead:头指针
// pos:待查节点序号
LinkListNode* GetLinkListNode(LinkListNode* pHead, int pos);
//查元素：查找给定元素指的位置
//找到返回节点地址，否则返回NULL
LinkListNode* LocateLinkList(LinkListNode* pHead, int data);
//插入元素：在指定的位置插入给定的指
//因为链表这种结构的内存是由程序员管理，因此它的建立有一定的运算方法
//尾插法建立单链表，将逻辑上的顺序表放入单链表的结构中
//顺序表: 12,33,44,76,89,90(逻辑上的顺序表) => 单链表
//本例中我们用数组表示顺序表
// arr：顺序表 length:顺序表长度
LinkListNode* Create_Real_LkList(ElemType arr[], int length);
//头插法建立单链表1
LinkListNode* Create_Front_LkList(ElemType arr[], int length);
//头插法建立单链表2
LinkListNode* Create_Front_LkList2(ElemType arr[], int length);
//头插法建立单链表3
LinkListNode* Create_Front_LkList3(ElemType arr[], int length);
//插入元素：在指定的位置插入给定的指
//在指定位置之后插入
void Insert_After_LkList(LinkListNode* ptr, ElemType x);
void Insert_Before_LkList(LinkListNode* pHead, LinkListNode* ptr, ElemType x);
//删除:删除指定位置的值或者删除给定的值
//情形1：删除指定节点的后继节点
//情形2：删除第i个节点，假定头节点i=0
//删除返回目标节点的地址，并不涉及到动态空间的回收
//在动态回收空间的要求中，应该遵循原则是“谁污染谁治理”
//在顺序表中的删除就是逻辑上的删除，就是说节点不再存在于当前顺序表中
//删除节点：Ptr是需要删除的节点，将删除ptr的后继节点
LinkListNode* Delete_After_Lklist(LinkListNode* ptr);
//删除第i个节点
LinkListNode* Delete_i_LkList(LinkListNode* pHead, int i);
//遍历
void ShowLklist(LinkListNode* pHead);

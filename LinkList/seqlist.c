#include <stdio.h>

#include "LinkList.h"

LinkListNode* ReverseLkList(LinkListNode* pHead)
{
    LinkListNode *Pointer, *Next;  // Pointer是将来依次获得的当前节点
    // Next是将来获得的当前节点的原先的下一个节点
    LinkListNode* Back;  //原先节点的上一个节点
    // step1:将原先的next节点的next域变成pointer
    // step2:将原先的Pointer的next域变成back
    Back = pHead;  //原先就是从头节点开始的，因此首先将back作为头节点
    Pointer = Back->pNext;  //通过头节点获得了第一元素,pointer指向第一个元素

    Next = Pointer->pNext;  //此时pointer是第一个元素，因此它的PNext是第2个元素
    Pointer->pNext = Back;  // pointer->pNext变成了Back，又因为Back是节点，所以此时原先的第一个元素的后继已经变成了原先的头节点
    Back = Pointer;  // pointer是第一个元素，所以此时Back变成了第一个元素
    Pointer = Next;  //因为在15行Next已经是第2个元素了，因此此时Pointer指向了第2个元素
    while (Pointer->pNext != NULL) {
        Next = Pointer->pNext;
        Pointer->pNext = Back;
        Back = Pointer;
        Pointer = Next;
    }
    Pointer->pNext = Back;  //此时Pointer已经是原先链表中的最后一个元素了
    //因此必须要把Pointer和原先的前继节点联系起来，而原先的前继节点一定在Back

    //此时反转完毕，需要重新设置头节点
    pHead->pNext->pNext = NULL;
    //由于pHead没有变化，所以依然让它作为反转后链表的头节点
    pHead->pNext = Pointer;
    return pHead;
}

int main()
{
    LinkListNode* pHead = NULL;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    pHead = Create_Real_LkList(arr, 10);
    printf("当前元素有\n");
    ShowLklist(pHead);

    printf("\n当前元素有\n");
    pHead = ReverseLkList(pHead);
    ShowLklist(pHead);
    getchar();
}

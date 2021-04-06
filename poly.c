#include <stdio.h>
#include <stdlib.h>

//设计数据项的数据结构
typedef struct Polynode {
    int coef;  //系数
    int exp;   //指数
    struct Polynode* pNext;
} LinkPolyNode;

//需要新增节点，因为有可能在原链表中不存在
//新元素的地址
// coef:系数
// ext:幂指数
// pc：新节点要插入的位置
//返回值：新分配的节点地址
LinkPolyNode* attach(int coef, int ext, LinkPolyNode* pc)
{
    LinkPolyNode* p;
    p = (LinkPolyNode*)malloc(sizeof(LinkPolyNode));
    p->coef = coef;
    p->exp = ext;
    pc->pNext = p;
    return p;
}

//所有存储结构按照幂指数升序
//将PolyA和PolyB相加，将结果放入PolyC中
//函数的输入是PolyA和PolyB的首地址
//函数返回的是PolyC的首地址
LinkPolyNode* MergePoly(LinkPolyNode* headA, LinkPolyNode* headB)
{
    LinkPolyNode* headC;
    LinkPolyNode *pa, *pb, *pc, *p;
    int x;

    pa = headA->pNext;
    pb = headB->pNext;
    headC = (LinkPolyNode*)malloc(sizeof(LinkPolyNode));
    pc = headC;  //此时pc做C多项式的头节点

    while (pa && pb) {
        if (pa->exp == pb->exp) {
            x = pa->coef + pb->coef;
            if (x)
                pc = attach(x, pa->exp, pc);
            pa = pa->pNext;
            pb = pb->pNext;
            continue;
        }
        if (pa->exp < pb->exp) {
            p = pa;
            pa = pa->pNext;

        } else {
            p = pb;
            pb = pb->pNext;
        }
        pc = attach(p->coef, p->exp, pc);
    }

    p = pa;

    if (!pa)
        p = pb;

    while (p) {
        pc = attach(p->coef, p->exp, pc);
        p = p->pNext;
    }
    pc->pNext = NULL;

    return headC;
}

//假定多项式的最低项是常数项
// 显示辅助函数
void ShowList(LinkPolyNode* pHead)
{
    LinkPolyNode* p;
    p = pHead->pNext;
    while (p) {
        //常数项显示
        if (p->exp == 0) {
            printf("%d", p->coef);
            p = p->pNext;
            continue;
        }
        //一次项显示
        if (p->exp == 1) {
            /* printf("x"); */
            if (p->coef > 0) {
                printf("+%dx", p->coef);
            } else {
                printf("%dx", p->coef);
            }
            p = p->pNext;
            continue;
        }
        //高此项显示
        if (p->coef > 0) {
            printf("+%dx^%d", p->coef, p->exp);
        } else {
            printf("+%dx^%d", p->coef, p->exp);
        }
        p = p->pNext;
    }
}

// PolyA: 1+2X+3X^2
// PolyB:3x+x^4

int main()
{
    LinkPolyNode HeadA, A1, A2, A3;
    LinkPolyNode HeadB, B1, B2;

    HeadA.pNext = &A1;
    A1.pNext = &A2;
    A2.pNext = &A3;
    A3.pNext = NULL;

    HeadB.pNext = &B1;
    B1.pNext = &B2;
    B2.pNext = NULL;

    //建立多项式
    A1.coef = 1;
    A1.exp = 0;
    A2.coef = 2;
    A2.exp = 1;
    A3.coef = 3;
    A3.exp = 2;

    B1.coef = 3;
    B1.exp = 1;
    B2.coef = 1;
    B2.exp = 4;

    printf("\n**PolyA**\n");
    ShowList(&HeadA);
    printf("\n**PolyB**\n");
    ShowList(&HeadB);

    LinkPolyNode* pPolyC;
    pPolyC = MergePoly(&HeadA, &HeadB);
    printf("\n**PolyC**\n");
    ShowList(pPolyC);
    getchar();
    return 0;
}

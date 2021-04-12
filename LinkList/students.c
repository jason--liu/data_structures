#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int num;
    float score;
} node;

// 班级人数
#define LIST_SIZE 50
#define TRUE 1
#define FALSE 0

//定义顺序表的结构
typedef struct seq {
    node data[LIST_SIZE];
    int last;  //表明最后一个节点位置
} Seqlist;

//获取班级人数
int GetSize(Seqlist* pList) { return pList->last; }

//遍历输出全体学生信息
void ShowSeqList(Seqlist* pList)
{
    for (int i = 0; i < pList->last; i++) {
        printf("学生的学号是%d, 成绩是%f\n", pList->data[i].num,
               pList->data[i].score);
    }
}

//初始化
Seqlist* InitSeq()
{
    Seqlist* pList = NULL;
    pList = (Seqlist*)malloc(sizeof(Seqlist));
    if (pList)
        pList->last = 0;  //初始化成功，且长度为0
    return pList;
}

//插入元素
int InsertStuSeq(Seqlist* pList, node* pNode, int pos)
{
    int j;
    /* if (pList->last >= LIST_SIZE - 1) */
    /*     return FALSE; */
    /* 移到函数外，由业务维护 */

    /* 在本例中，假定pos是有效位置 */
    for (j = pList->last; j >= pos; j--) {
        pList->data[j + 1].num = pList->data[j].num;
        pList->data[j + 1].score = pList->data[j].score;
    }
    pList->data[pos].num = pNode->num;
    pList->data[pos].score = pNode->score;
    pList->last++;

    return TRUE;
}

int DelSeqList(Seqlist* pList, int pos)
{
    if (!pList->last)
        return FALSE;

    for (int j = pos; j <= pList->last; j++) {
        pList->data[j].num = pList->data[j + 1].num;
        pList->data[j].score = pList->data[j + 1].score;
    }

    pList->last--;
    return TRUE;
}

//实现按学号查找
void DisplayStu(Seqlist* pList, int stuNo)
{
    for (int i = 0; i < pList->last; i++) {
        if (pList->data[i].num == stuNo) {
            printf("该学生的成绩是%f\n", pList->data[i].score);
            return;
        }
    }
    printf("该学生不存在\n");
}

int main()
{
    Seqlist* stuList = InitSeq();
    node stu[2];
    stu[0].num = 1;
    stu[0].score = 99;
    stu[1].num = 2;
    stu[1].score = 100;
    if (stuList) {
        for (int i = 0; i < 2; i++) {
            InsertStuSeq(stuList, &stu[i], i);
        }
    }
    ShowSeqList(stuList);

    /* DelSeqList(stuList, 1); */
    /* ShowSeqList(stuList); */
    printf("\n***************\n");
    DisplayStu(stuList, 1);
    getchar();
    return 0;
}

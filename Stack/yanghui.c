#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 50;
    int queue[42] = {0, 1, 1, 0};  // 0是换行
    int front = 1, rear = 4;       //首先将杨辉三角的第一行输入
    for (int i = 0; i < n; i++) {
        queue[rear] = queue[front - 1] + queue[front];
        //将队头的两个元素和插入rear位置
        printf("%d ", queue[rear]);
        rear++;
        if (queue[front] == 0) {
            //添加新的分割
            queue[rear] = 0;
            rear++;
            printf("\n");
        }
        front++;
    }
    getchar();
    return 0;
}

#include <stdio.h>

int main()
{
    //奇数阶魔方阵构造规则：
    //从中间的第一行开始放置数字 1。
    //接下来的数字按规则放置：当前数字放在上一个数字的右上方，如果该位置已经被填充或者超出了矩阵的范围，则放置在当前数字的下方。
    int a[100][100] = { 0 };
    int n;
    int num = 1; 

    printf("请输入一个大于零的奇数定义魔方阵的大小：\n");
    while (1)
    {
        scanf_s("%d", &n);
        if (n % 2 != 0 && n > 0) break;
        else printf("请输入一个符合规定的数：\n");
    }
    
    //与原来只输出五阶不同，这里初始值的位置也要更改为(0,n/2)
    int i = 0, j = n/2;  

    while (num <= n * n)
    {
        a[i][j] = num;
        num++;

        // 下一个数移动到右上方的位置
        int i_next = i - 1;
        int j_next = j + 1;

        //环绕规则,来处理超出边界的情况
        if (i_next < 0) i_next = n-1;
        if (j_next >= n) j_next = 0;


        if (a[i_next][j_next] != 0)  // 如果右上方位置已填充，移动到下方
        {
            i = i + 1;
        }
        else
        {
            i = i_next;
            j = j_next;
        }
    }

    for (int x = 1; x <= n; x++)
        printf("—");
    printf("\n%d阶的魔方阵为：\n", n);
    for (int i = 0; i <= n-1; i++)
    {
        for (int j = 0; j <= n-1; j++)
        {
            printf("%6d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
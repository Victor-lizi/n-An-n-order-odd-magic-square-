#include <stdio.h>

int main()
{
    //������ħ���������
    //���м�ĵ�һ�п�ʼ�������� 1��
    //�����������ְ�������ã���ǰ���ַ�����һ�����ֵ����Ϸ��������λ���Ѿ��������߳����˾���ķ�Χ��������ڵ�ǰ���ֵ��·���
    int a[100][100] = { 0 };
    int n;
    int num = 1; 

    printf("������һ�����������������ħ����Ĵ�С��\n");
    while (1)
    {
        scanf_s("%d", &n);
        if (n % 2 != 0 && n > 0) break;
        else printf("������һ�����Ϲ涨������\n");
    }
    
    //��ԭ��ֻ�����ײ�ͬ�������ʼֵ��λ��ҲҪ����Ϊ(0,n/2)
    int i = 0, j = n/2;  

    while (num <= n * n)
    {
        a[i][j] = num;
        num++;

        // ��һ�����ƶ������Ϸ���λ��
        int i_next = i - 1;
        int j_next = j + 1;

        //���ƹ���,���������߽�����
        if (i_next < 0) i_next = n-1;
        if (j_next >= n) j_next = 0;


        if (a[i_next][j_next] != 0)  // ������Ϸ�λ������䣬�ƶ����·�
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
        printf("��");
    printf("\n%d�׵�ħ����Ϊ��\n", n);
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
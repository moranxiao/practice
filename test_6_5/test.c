int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int i = 0;
        int j = 0;
        //����
        for (i = 0; i < n; i++)
        {
            //һ��
            for (j = 0; j < n; j++)
            {
                //�к��еĺ�
                //������԰�������������������ܿ�����
                if (i + j < n - 1)
                {
                    printf("  ");
                }
                else
                {
                    printf("* ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
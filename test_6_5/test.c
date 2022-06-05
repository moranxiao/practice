int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int i = 0;
        int j = 0;
        //行数
        for (i = 0; i < n; i++)
        {
            //一行
            for (j = 0; j < n; j++)
            {
                //行和列的和
                //这里可以把行数和列数标出来就能看明白
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
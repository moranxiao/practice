void yangHuiTriangle(int n)
{
	int data[30] = { 1 };

	int i, j;
	printf("1\n"); //��һ�о�ֱ�Ӵ�ӡ��
	for (i = 1; i < n; i++) //�ӵڶ��п�ʼ
	{
		for (j = i; j > 0; j--) //�Ӻ���ǰ�������һ�е�������ʹ��ǰ�ͱ�����
		{
			data[j] += data[j - 1]; //��ʽͬ�ϣ����ڱ����һά����ʽҲ����ˡ�
		}

		for (j = 0; j <= i; j++) //��һ�������ֱ�Ӵ�ӡ�ˡ�
		{
			printf("%d ", data[j]);
		}
		putchar('\n');
	}
}
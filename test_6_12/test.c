void diveRank(int* p, int n)
{
	if (n >= 5) //��ʱ��n����������ѭ�������ġ�
	{
		if ((p[1] == 2) + (p[0] == 3) == 1 && //B�ڶ����ҵ���
			(p[1] == 2) + (p[4] == 4) == 1 && //�ҵڶ���E����
			(p[2] == 1) + (p[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
			(p[2] == 5) + (p[3] == 3) == 1 && //C����ҵ���
			(p[4] == 4) + (p[0] == 1) == 1 && //�ҵ��ģ�A��һ
			checkData(p)) //����
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%d ", p[i]);
			}
			putchar('\n');
		}
		return;
	}

	for (p[n] = 1; p[n] <= 5; p[n]++)
	{
		diveRank(p, n + 1); //ͨ���ݹ�ģ����ѭ����ÿ��һ�εݹ��൱�ڽ���һ���µ�ѭ����
	}
}

int main()
{
	int p[5];

	diveRank(p, 0);

	return 0;
}
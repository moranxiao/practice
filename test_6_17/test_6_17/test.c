void leftRound(char* src, int time)
{
	int i, j, tmp;
	int len = strlen(src);
	time %= len; //����Ϊ5������£���ת6��11��16...���൱��1�Σ�7��12��17...���൱��2�Σ��Դ����ơ�
	for (i = 0; i < time; i++) //ִ��k�εĵ���ƽ��
	{
		tmp = src[0];
		for (j = 0; j < len - 1; j++) //����ƽ��
		{
			src[j] = src[j + 1];
		}
		src[j] = tmp;
	}
}
void reverse_part(char* str, int start, int end) //���ַ�����start��end��һ������
{
	int i, j;
	char tmp;

	for (i = start, j = end; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

void leftRound(char* src, int time)
{
	int len = strlen(src);
	int pos = time % len;
	reverse_part(src, 0, pos - 1); //����ǰ��
	reverse_part(src, pos, len - 1); //������
	reverse_part(src, 0, len - 1); //��������
}
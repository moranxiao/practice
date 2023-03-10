void reverse_part(char* str, int start, int end) //将字符串从start到end这一段逆序
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
	reverse_part(src, 0, pos - 1); //逆序前段
	reverse_part(src, pos, len - 1); //逆序后段
	reverse_part(src, 0, len - 1); //整体逆序
}
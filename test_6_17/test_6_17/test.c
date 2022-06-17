void leftRound(char* src, int time)
{
	int i, j, tmp;
	int len = strlen(src);
	time %= len; //长度为5的情况下，旋转6、11、16...次相当于1次，7、12、17...次相当于2次，以此类推。
	for (i = 0; i < time; i++) //执行k次的单次平移
	{
		tmp = src[0];
		for (j = 0; j < len - 1; j++) //单次平移
		{
			src[j] = src[j + 1];
		}
		src[j] = tmp;
	}
}
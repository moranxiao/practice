void leftRound(char* src, int time)
{
	int len = strlen(src);
	int pos = time % len; //�Ͽ�λ�õ��±�
	char tmp[256] = { 0 }; //��׼ȷ�Ļ�����ѡ��malloc len + 1���ֽڵĿռ��������tmp

	strcpy(tmp, src + pos); //�Ƚ������ȫ��������
	strncat(tmp, src, pos); //Ȼ��ǰ�漸������
	strcpy(src, tmp); //��󿽻�ȥ
}

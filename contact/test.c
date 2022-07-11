#pragma warning(disable:4996)
#include "contact.h"

void meau()
{
	printf("*************************************\n");
	printf("****** 1.add       2.del_one  *******\n");
	printf("****** 3.search    4.modify   *******\n");
	printf("****** 5.show      6.sort     *******\n");
	printf("****** 7.del_all   0.exit     *******\n");
	printf("*************************************\n");
}
int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	LoadContact(&con);
	do
	{
		meau();
		printf("������ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL_ONE:
			DelOne(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case DEL_ALL:
			DelAll(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestoryContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}
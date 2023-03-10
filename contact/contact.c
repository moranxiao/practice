#include "contact.h"

void InitContact(Contact* con)
{
	assert(con);
	PeoInform* ptr = (PeoInform*)calloc(DEFAULT_CAP, sizeof(PeoInform));
	if (ptr == NULL)
		return;
	con->data = ptr;
	con->count = 0;
	con->capacity = DEFAULT_CAP;
}

void LoadContact(Contact* con)
{
	assert(con);
	FILE* pf = fopen("text.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	PeoInform tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInform), 1, pf) == 1)
	{
		if (con->capacity == con->count)
		{
			PeoInform* ptr = (PeoInform*)realloc(con->data, (con->capacity + INC_CAP) * sizeof(PeoInform));
			if (ptr == NULL)
			{
				printf("AddContact:%s", strerror(errno));
				printf("增容失败\n");
				return;
			}
			else
			{
				con->data = ptr;
				con->capacity += INC_CAP;
				printf("增容成功\n");
			}
		}
		con->data[con->count] = tmp;
		con->count++;
	}
	fclose(pf);
	pf = NULL;
}

void AddContact(Contact * con)
{
	assert(con);
	if (con->capacity == con->count)
	{
		PeoInform* ptr = (PeoInform*)realloc(con->data, (con->capacity + INC_CAP) * sizeof(PeoInform));
		if (ptr == NULL)
		{
			printf("AddContact:%s", strerror(errno));
			printf("增容失败\n");
			return;
		}
		else
		{
			con->data = ptr;
			con->capacity += INC_CAP;
			printf("增容成功\n");
		}
	}
	printf("请输入姓名:>");
	scanf("%s", con->data[con->count].name);
	printf("请输入性别:>");
	scanf("%s", con->data[con->count].sex);
	printf("请输入年龄:>");
	scanf("%d", &(con->data[con->count].age));
	printf("请输入电话:>");
	scanf("%s", con->data[con->count].tele);
	printf("请输入地址:>");
	scanf("%s", con->data[con->count].addr);
	con->count++;
	printf("增加成功\n");
}

void ShowContact(const Contact * con)
{
	assert(con);
	printf("%-20s%-10s%-5s%-12s%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
	int i = 0;
	for (i = 0; i < con->count; i++)
	{
		printf("%-20s%-10s%-5d%-12s%-30s\n", con->data[i].name
			, con->data[i].sex
			, con->data[i].age
			, con->data[i].tele
			, con->data[i].addr);
	}
}

static int SearchByName(const Contact * con, char* name)
{
assert(con);
int i = 0;
for (i = 0; i < con->count; i++)
{
	if (strcmp(name, con->data[i].name) == 0)
	{
		return i;
	}
}
return -1;
}

void DelOne(Contact * con)
{
	assert(con);
	int i = 0;
	char name[20];
	printf("请输入您想删除的联系人的名字>:");
	scanf("%s", name);
	int ret = SearchByName(con, name);
	if (-1 == ret)
	{
		printf("找不到此联系人\n");
		return;
	}
	for (i = ret; i < con->count - 1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->count--;
	printf("删除成功\n");
}

void SearchContact(const Contact * con)
{
	assert(con);
	char name[20];
	printf("请输入您想查找的联系人的名字>:");
	scanf("%s", name);
	int ret = SearchByName(con, name);
	if (-1 == ret)
	{
		printf("找不到该联系人\n");
		return;
	}
	printf("%-20s%-10s%-5s%-12s%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
	printf("%-20s%-10s%-5d%-12s%-30s\n", con->data[ret].name
		, con->data[ret].sex
		, con->data[ret].age
		, con->data[ret].tele
		, con->data[ret].addr);
}

void ModifyContact(Contact * con)
{
	assert(con);
	char name[20];
	printf("请输入您想修改的联系人的名字>:");
	scanf("%s", name);
	int ret = SearchByName(con, name);
	if (-1 == ret)
	{
		printf("找不到该联系人\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", con->data[ret].name);
	printf("请输入性别:>");
	scanf("%s", con->data[ret].sex);
	printf("请输入年龄:>");
	scanf("%d", &(con->data[ret].age));
	printf("请输入电话:>");
	scanf("%s", con->data[ret].tele);
	printf("请输入地址:>");
	scanf("%s", con->data[ret].addr);
	printf("修改成功\n");
}

void  DelAll(Contact * con)
{
	InitContact(con);
	printf("删除成功\n");
}

int CmpByName(const void* e1, const void* e2)
{
	return strcmp(((PeoInform*)e1)->name, ((PeoInform*)e2)->name);
}

void SortContact(Contact * con)
{
	qsort(con->data, sizeof(con->count), sizeof(con->data[0]), CmpByName);
	printf("排序成功\n");
}


void DestoryContact(Contact * con)
{
	assert(con);
	free(con->data);
	con->data = NULL;
}

void SaveContact(Contact * con)
{
	assert(con);
	FILE* pf = fopen("text.txt", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	int i = 0;
	for (i = 0; i < con->count; i++)
		fwrite(con->data + i, sizeof(PeoInform), 1, pf);
	fclose(pf);
	pf = NULL;
}
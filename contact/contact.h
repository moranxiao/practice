#pragma warning(disable:4996)

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR  30

#define MAX_DATA 100
#define DEFAULT_CAP 3
#define INC_CAP 2

enum opt
{
	EXIT,
	ADD,
	DEL_ONE,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	DEL_ALL
};

typedef struct PeoInform
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInform;
//typedef struct Contact
//{
//	struct PeoInform data[MAX_DATA];
//	int count;
//}Contact;

typedef struct Contact
{
    PeoInform* data;
	int count;
	int capacity;
}Contact;

extern void InitContact(struct Contact* con);

extern void AddContact(Contact* con);

extern void ShowContact(const Contact* con);

extern void DelOne(Contact* con);

extern void SearchContact(const Contact* con);

extern void ModifyContact(Contact* con);

extern void  DelAll(Contact* con);

extern void SortContact(Contact* con);

extern void DestoryContact(Contact* con);

extern void SaveContact(Contact* con);

extern void LoadContact(Contact* con);
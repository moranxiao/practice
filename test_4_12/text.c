#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    char password[20] = { 0 };
    printf("����������>:");
    scanf("%s", password);
    printf("��ȷ�����루Y/N)\n");
    getchar();
    if (getchar() == 'Y')
        printf("����ɹ�\n");
    else
        printf("����ʧ��\n");
    return 0;
    
     
}
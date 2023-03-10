#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    char password[20] = { 0 };
    printf("请输入密码>:");
    scanf("%s", password);
    printf("请确认密码（Y/N)\n");
    getchar();
    if (getchar() == 'Y')
        printf("输入成功\n");
    else
        printf("输入失败\n");
    return 0;
    
     
}
#include<stdio.h>
int main()
{
    int killer = 0;
    //�ֱ����������a,b,c,d,��˭������ʱ����3����˵���滰��һ����˵�˼ٻ�
    for (killer = 'a'; killer <= 'd'; killer++)
    {
        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
            printf("�����ǣ�%c", killer);
    }
    return 0;
}
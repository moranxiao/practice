#include<stdio.h>
int main()
{
    int killer = 0;
    //分别假设凶手是a,b,c,d,看谁是凶手时满足3个人说了真话，一个人说了假话
    for (killer = 'a'; killer <= 'd'; killer++)
    {
        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
            printf("凶手是：%c", killer);
    }
    return 0;
}
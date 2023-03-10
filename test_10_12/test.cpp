#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {
    int num1, num2, num3, num4;
    int a, b, c;
    scanf_s("%d %d %d %d", &num1, &num2, &num3, &num4);
    a = (num1 + num3) / 2;
    b = num3 - a;
    if ((a - b) != num1) {
        printf("NO");
        return 0;
    }
    c = num4 - b;
    if ((b - c) != num2)
    {
        printf("NO");
        return 0;
    }
    printf("%d %d %d", a, b, c);
    return 0;
}
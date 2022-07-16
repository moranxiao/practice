#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand((int)time(NULL));
	int arr[4] = { 0 };
	arr[0] = rand() % 9 + 1;
	int i = 1;
	int tmp = 0;
	while (i < 4){
		int flag = 0;
	    tmp = rand() % 9 + 1;
		for (int j = 0; j < i; j++){
			if (arr[j] == tmp)
				flag = 1;
		}
		if (flag){
			continue;
		}
		else{
			arr[i] = tmp;
			i++;
		}
	}
	return 0;
}
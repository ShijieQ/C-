#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	//���������
	int len = 1000, min = 0,max = 10000;
	int arr[len];
    srand(time(0));
    for(int i = 0;i < len;i++){
		arr[i] = rand() % max + min;
		printf("%d\t", arr[i]);
	}
	printf("\n");
	//����
	for(int j = 0;j < len - 1; j++){
		for(int k = j+1; k <= len; k ++){
			if(arr[j] < arr[k]){
				int temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}
		}
	}
    //ͳ�ƴ���
	int count = 1;
	for(int m = 0;m < len; m++){
		if(arr[m] == arr[m+1]){
			count++;
		}else{
			printf("%d������%d��\n", arr[m], count);
			count = 1;
		}
	}
    return 0;
}

#include<stdio.h>
int main()
{
	printf("a\nb\rc\0d\te\vf\bg\f");
    printf("158\r");//�س��������У� 
    printf("158\0");//���ַ� 
    printf("158\t");//ˮƽ�Ʊ�� 
    printf("158\v");//��ֱ�Ʊ�� 
    printf("158\b");//�˸� 
    printf("158\f");//��ֽ��ҳ 
    printf("158\a");//���屨�� 
    printf("158\x41");//1-2λʮ������ASC����ֵ��������ַ� 
	return 0;
}

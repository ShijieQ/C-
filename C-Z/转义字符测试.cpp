#include<stdio.h>
int main()
{
	printf("a\nb\rc\0d\te\vf\bg\f");
    printf("158\r");//回车（不换行） 
    printf("158\0");//空字符 
    printf("158\t");//水平制表符 
    printf("158\v");//垂直制表符 
    printf("158\b");//退格 
    printf("158\f");//走纸换页 
    printf("158\a");//响铃报警 
    printf("158\x41");//1-2位十六进制ASCⅡ码值所代表的字符 
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define maxn 2000
char mimaji[100][205];
int ans = 0;
int k;
char ch[200];
void jiemi(char *mima)
{
	for(int i = 0; i < strlen(mima); i++)
	{
		if(mima[i] >= 'A' && mima[i] < 'F')
		{
			mima[i] += 17;
		}	
		if(mima[i] >= 'F' && mima[i] <= 'Z')
		{
			mima[i] -= 5;
		} 	
	}
}

void duruwenjian()			//����ס�����ϵ��ļ����� 
{
	FILE *fp;
	int i=0;	
	fp=fopen("D:\\f1.txt","r+");
	if(fp==0)
	{
		printf("��ʧ�ܣ�");
		exit(1); 
	}
	
	char temp[205];
	fscanf(fp,"%s",temp);
	do
	{	
		char mima[105][205];
		if(strcmp(temp, "ENDOFINPUT") == 0)
			break;
		while(strcmp(temp,"START") != 0 && !feof(fp))
			fscanf(fp, "%s", temp);
		fscanf(fp, "%s", mima[0]);
		for(i = 1; i <= maxn && strcmp(mima[i-1], "END") != 0 && !feof(fp); i++)
			fscanf(fp, "%s", mima[i]);
		int num = i-1;
		fscanf(fp, "%s", temp);
		for(i = 0; i < num; i++)
			jiemi(mima[i]);
		for(i = 0; i < num; i++)
			printf("%s\n", mima[i]);
	}while(strcmp(temp, "ENDOFINPUT") != 0);
		
		
	fclose(fp);
} 
int zijishu(int ans=0)
{
	char flag[12];
	char flag1[12];
	while(strcmp(flag,"START"))
	{
		scanf("%s",&flag);//��ʼ����START 
	}	
	while(strcmp(flag,"ENDOFINPUT"))
	{
		char mima[205];
		scanf("%s",&mima);//����������Ϣ 
		do
		{
			scanf("%s",&flag1);//����END 
		}
		while(strcmp(flag1,"END")!=0);
		for(int i = 0; i < strlen(mima); i++)
		{
			if(mima[i] >= 'A' && mima[i] < 'F')
			{
				mima[i] += 17;
			}	
			if(mima[i] >= 'F' && mima[i] <= 'Z')
			{
				mima[i] -= 5;
			} 	
		}
		strcpy(mimaji[ans], mima);//�洢���� 
		ans++; 
		while(scanf("%s",&flag) )
		{
			if(strcmp(flag,"ENDOFINPUT") == 0)
			{
				for(int i = 0; i <= ans; i++)
					printf("%s\n",mimaji[i]);
				return 0;
			}
			else
			{
				if(strcmp(flag,"START") == 0)	break;
				else
				{
					printf( "FUCK!!!!!!!!!!!!!!!!!!!!!!!!�����䣡����������������������������" );
				}
			}
		}
	}
}

void zhucaidan(int ans)
{
	int k;
	printf("_____________________1.�Լ���\n");
	printf("_____________________2.�ļ�����\n");
	scanf("%d",&k);
	switch(k)
	{
		case 1:zijishu(ans);
			printf("_________________________1.�������˵�\n");
			printf("_________________________2.GAME OVER!\n");
			scanf("%d",&k);
			switch(k)
			{
				case 1:zhucaidan(ans);
					break;
			}
			break;
		case 2: duruwenjian();
			printf("_________________________1.�������˵�\n");
			printf("_________________________2.GAME OVER!\n");
			scanf("%d",&k);
			switch(k)
			{
				case 1:zhucaidan(ans);
					break;
			}
			break;
	}
}

int main()
{
	zhucaidan(ans);
	return 0;

}

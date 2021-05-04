#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	if(argc == 3){
		char a[100];
		char b[100];
		strcpy(a,argv[1]);
		strcpy(b,argv[2]);
		FILE *fp;
		int charCount=0,wordCount=0;
		char c;
		if((fp=fopen(b,"r"))==NULL)//判断文件打开是否正确 
		{
			printf("未检测到文件\n");
			return 0;
		}
		c=fgetc(fp); 	
		
		char t = c;
		while(c!=EOF)
		{		
			if((c==' ' || c==',' || c=='\n')&&(t!=' ' && t!=',' && t!='\n'))//如果c为空格逗号换行并且前一个字符不为空格逗号换行则单词数加1 
			{
				wordCount++;
			}
			charCount++;
			t=c;
			c=fgetc(fp);
		}
		if(t!=' ' && t!= ',' && t!='\n')
			wordCount++;
		if(a[1]=='c'){
			printf("字符数:%d\n",charCount);
		}else if(a[1]=='w'){
			printf("单词数:%d\n",wordCount);
		}else{
			printf("输入错误\n"); 
		} 
		fclose(fp);
		}
//	else{
//		printf("请输入三个参数\n");
//	}
	return 0;
}

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
		if((fp=fopen(b,"r"))==NULL)//�ж��ļ����Ƿ���ȷ 
		{
			printf("δ��⵽�ļ�\n");
			return 0;
		}
		c=fgetc(fp); 	
		
		char t = c;
		while(c!=EOF)
		{		
			if((c==' ' || c==',' || c=='\n')&&(t!=' ' && t!=',' && t!='\n'))//���cΪ�ո񶺺Ż��в���ǰһ���ַ���Ϊ�ո񶺺Ż����򵥴�����1 
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
			printf("�ַ���:%d\n",charCount);
		}else if(a[1]=='w'){
			printf("������:%d\n",wordCount);
		}else{
			printf("�������\n"); 
		} 
		fclose(fp);
		}
//	else{
//		printf("��������������\n");
//	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int numC(char *file);//cģʽ���ַ����� 
int numW(char *file);//wģʽ�´ʵ����� 

int main(int argc, char* argv[]){
	FILE *fp;
	int dataC,dataW;//cģʽ����wģʽ�� 
	char filename[150];//�ļ���ַ
	char mod[2]; //ģʽ 
	
	
	strcpy(mod,argv[1]);//���mod 
	strcpy(filename,argv[2]);//����ļ���ַ 

	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("����������ļ�");
		exit(-1);
	}
		
	else if(!strcmp(mod,"-c")) 
	{
		dataC=numC(filename);
		printf("\n���ļ��ַ���Ϊ%d\n",dataC);
	}
	
	else if(!strcmp(mod,"-w"))
	{
		dataW=numW(filename);
		printf("\n���ļ�������Ϊ%d\n",dataW);
	}
}

int numC(char *filename) {
    FILE *fp = NULL;
    int numCcount = 0;
    if ((fp=fopen(filename,"r"))== NULL) {
        printf("�ļ�Ѱ��ʧ�ܣ�\n");
        exit(-1);
    }
    char dataC;
  	dataC = fgetc(fp);
    while (!feof(fp)) {
        dataC = fgetc(fp);//��ȡ�ļ��е��ַ�
        numCcount++;//ͳ���ַ���
    }
    fclose(fp);
    return numCcount;
}

int numW(char *filename) {
    FILE *fp = NULL;
    int wordcount = 0;
    if ((fp = fopen(filename,"r")) == NULL) {
        printf("�ļ�Ѱ��ʧ�ܣ�\n");
        exit(-1);
    }
    char ch;
    int word=0;

    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch<'A' || (ch> 'Z'&&ch< 'a') || ch>'z')
        {
            word = 0;
        }
        else if (word == 0)
        {
            word = 1;
            wordcount++;
        }
    }
    return wordcount;
}


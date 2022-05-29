#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int numC(char *file);//c模式下字符数量 
int numW(char *file);//w模式下词的数量 

int main(int argc, char* argv[]){
	FILE *fp;
	int dataC,dataW;//c模式数，w模式数 
	char filename[150];//文件地址
	char mod[2]; //模式 
	
	
	strcpy(mod,argv[1]);//获得mod 
	strcpy(filename,argv[2]);//获得文件地址 

	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("不存在这个文件");
		exit(-1);
	}
		
	else if(!strcmp(mod,"-c")) 
	{
		dataC=numC(filename);
		printf("\n该文件字符数为%d\n",dataC);
	}
	
	else if(!strcmp(mod,"-w"))
	{
		dataW=numW(filename);
		printf("\n该文件单词数为%d\n",dataW);
	}
}

int numC(char *filename) {
    FILE *fp = NULL;
    int numCcount = 0;
    if ((fp=fopen(filename,"r"))== NULL) {
        printf("文件寻找失败！\n");
        exit(-1);
    }
    char dataC;
  	dataC = fgetc(fp);
    while (!feof(fp)) {
        dataC = fgetc(fp);//读取文件中的字符
        numCcount++;//统计字符数
    }
    fclose(fp);
    return numCcount;
}

int numW(char *filename) {
    FILE *fp = NULL;
    int wordcount = 0;
    if ((fp = fopen(filename,"r")) == NULL) {
        printf("文件寻找失败！\n");
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


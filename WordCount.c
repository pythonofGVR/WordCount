#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 1024

//张恒基 202131023207 
int flag = 0;
int r[2] = {2};

void *ReadChar(char *fileName);
void *ReadWord(char *fileName);
void Test(int argc,char* argv[]);
void WordCount(int argc,char* argv[]); 
int *GetOptions(int argc,char* argv[]);

int main(int argc,char* argv[]){
	Test(argc,argv);
}

void Test(int argc,char* argv[]){
	WordCount(argc,argv);
}

void WordCount(int argc,char* argv[]){
	char* fileName;
	if(argc<=1){
		exit(0);
	}
	GetOptions(argc,argv);
	fileName = argv[r[1]];
	switch(r[0]){
		case 1:
			ReadChar(fileName);
			break;
		case 2:
			ReadWord(fileName);
			break;
		default:
			break;
	}
}

int *GetOptions(int argc,char* argv[]){
	char* params;
	int i;
	if(argc>0){
		params = argv[argc-1];
	}
	for(i=0;i<argc;i++){
		params = argv[i];
		if(strcmp("-c",params)==0){
			r[0]+=2;
		}
		r[1] = argc - 1;
	}
	return r;
}

void *ReadChar(char* fileName)//字符数 
{
	char buf;
	int count[N] = {0},index = 0,i;
	FILE* fp = fopen(fileName,"r");
	while(!feof(fp))
	{
		buf = fgetc(fp);
		count[buf]++;
	}
	fclose(fp);
	for(i=0;i<N;i++){
		if(count[i]!=0)
		{
			index+=count[i];
		}
	}
	printf("%d",index);
}

void *ReadWord(char* fileName)//单词数 
{
	char buf[N];
	int d = 0;
	int sum = 0;
	int n,i;
	FILE* fp = NULL;
	fp = fopen(fileName,"r");
	while(!feof(fp))
	{
		fscanf(fp,"%s",buf);
		n = strlen(buf);
		for(i=1;i<n;i++){
			if(buf[i]==','||buf[i]==' '){
				d++;
			}
		}
		if(n>0){
			sum+=d+1;
			d=0;
		}
	}
	printf("%d",sum);
}



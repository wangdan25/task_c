#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reader.h"

#define N 500

char** reader(char* file_path, int* n)
{
  FILE* fp = fopen(file_path, "r");
  if (fp == NULL)
  {
    printf("Fail to open file! ");
    return NULL;
  }
  file_line(fp, n);
  //为指针数组开辟空间
  char** data = (char **)malloc(*n*sizeof(char*));
  get_file_data(fp, n, data);
  fclose(fp);
  return data;
}

void file_line(FILE* file, int* n)
{
  char temp[N] = {0};
  if (file == NULL)
  {
    return;
  }
  while(fgets(temp,N,file) != NULL)
  {
    (*n)++;
  }
  rewind(file);
}

void get_file_data(FILE* file, int* line, char** data)
{
  char temp[N] = {0};
  int i = 0;
  if (file == NULL)
  {
    return;
  }
  if (*line == -1)
  {
    return;
  }
  while(fgets(temp, N, file) != NULL)
  {
		//给当前行分配内存
		char* line_data = (char*)malloc(sizeof(char) * N);
		//将行数据拷贝到空间中
		strcpy(line_data, temp);
		data[i++] = line_data;
        memset(temp, 0, N);
  }

}
void show_data(char** data, int* len)
{
  int i =0;
  for (i=0; i<(*len); i++)
  {
    printf("环里的人是：%s\n", data[i]);
  }
}
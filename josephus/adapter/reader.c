#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reader.h"

#define N 100
#define SUCCESS 1
#define FALSE 0
#define OPEN_FILE_FAILED -1;

char** reader_data_new()
{  
  char** data = malloc(N*sizeof(char**));  
  return data;
}

void reader_data_destroy(char** data)
{
  free(data);
}

int reader(char* file_path,char** data, int* n)
{
  FILE* fp = fopen(file_path, "r");
  if (fp == NULL)
  {
    return OPEN_FILE_FAILED;
  }
  reader_get_file_line(fp, n);
  reader_get_file_data(fp, n, data);
  fclose(fp);
  return SUCCESS;
}

int reader_get_file_line(FILE* file, int* n)
{
  char temp[N] = {0};
  if (file == NULL)
  {
    return FALSE;
  }
  while(fgets(temp,N,file) != NULL)
  {
    (*n)++;
  }
  rewind(file);
  return SUCCESS;
}

int reader_get_file_data(FILE* file, int* line, char** data)
{
  char temp[N] = {0};
  int i = 0;
  if (file == NULL)
  {
    return FALSE;
  }
  if (*line == -1)
  {
    return FALSE;
  }
  while(fgets(temp, N, file) != NULL)
  {
		char* line_data = (char*)malloc(sizeof(char) * N);
		strcpy(line_data, temp);
		data[i++] = line_data;
    memset(temp, 0, N);
  }
  return SUCCESS;
}

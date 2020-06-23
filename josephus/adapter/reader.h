#include <stdio.h>
#ifndef READER_H
#define READER_H

char** reader_data_new();
void reader_data_destroy(char** data);
int reader(char* file_path, char** data, int* n);
int reader_get_file_line(FILE* file, int* n);
int reader_get_file_data(FILE* file, int* line, char** data);

#endif
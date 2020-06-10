#include <stdio.h>
#ifndef READER_H
#define READER_H

char** reader(char* file_path, int* n);
void file_line(FILE* file, int* n);
void get_file_data(FILE* file, int* line, char** data);



#endif
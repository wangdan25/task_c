#include <stdio.h>
#ifndef READER_H
#define READER_H

#include "person.h"

typedef struct Reader Reader; 

Reader* reader_new();
int reader_destroy(Reader* self);
int reader_init(Reader* self, char* path, int line);
int reader_get_line(char* path, int* line);
int reader_get_file_data(Reader* self, char** data);

#endif
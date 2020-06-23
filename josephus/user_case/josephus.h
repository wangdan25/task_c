#ifndef JOSEPHUS_H
#define JOSEPHUS_H

#include "person.h"

typedef struct josephus josephus;

josephus* josephus_new();
int josephus_destroy(josephus* self);
int josephus_init(josephus* self, char** data, int start, int step, int *len);
int josephus_get_result(josephus *self, Person** result, int* n);

#endif
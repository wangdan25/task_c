#ifndef JOSEPHUS_H
#define JOSEPHUS_H

#include "person.h"

typedef struct josephus josephus;

josephus* josephus_new();
int josephus_destroy(josephus* self);
int josephus_init(josephus* self,int start, int step);
int josephus_get_size(josephus* self);
int josephus_append(josephus* self, Person* someone);
int josephus_pop(josephus* self, Person** target, int index);
int josephus_result(josephus *self, Person** result, int* n);


#endif
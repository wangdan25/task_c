#include <stdio.h>
#include <stdlib.h>

#include "josephus.h"
#include "person.h"

#define N 100
#define SUCCESS 1
#define INVALID_START -1
#define INVALID_STEP -2


struct josephus
{
  int start;
  int step;
  Person **people;
};


josephus* josephus_new()
{
  josephus* self = malloc(N*sizeof(josephus));
  self->people = malloc(N*sizeof(Person*));
  return self;
}
 
int josephus_destroy(josephus* self)
{
  free(self);
  free(self->people);
  return SUCCESS;
}

int josephus_init(josephus* self, char** data, int start, int step, int *len)
{
  if (start < 0)
  {
   return INVALID_START; 
  }
  if (step < 1)
  {
    return INVALID_STEP;
  }
  self->start = start;
  self->step = step;
  for (int i=0;i<*len;i++)
  {
    self->people[i] = person_from_str(data[i]);
  }
  return SUCCESS;
}

int josephus_get_result(josephus *self, Person** result, int* n)
{
  int nonzero_step, i, id_ = self->start-1;
  int ring[10];
  for (i = 0; i < *n; i++)
    ring[i] = 1;
  for (i = 0; i < *n; i++)
  {
    nonzero_step = 0;
    while (nonzero_step < self->step)
    {
      if (id_ == *n)
        id_ = 0;
      if (ring[id_])
        nonzero_step++;
      id_++;
    }
    ring[id_ - 1] = 0;
    result[i] = self->people[id_ - 1];
  }
  return SUCCESS;
}

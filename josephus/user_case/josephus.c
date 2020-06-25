#include <stdio.h>
#include <stdlib.h>

#include "josephus.h"
#include "person.h"
#include "m-array.h"

#define N 100
#define SUCCESS 1
#define INVALID_START -1
#define INVALID_STEP -2

ARRAY_DEF (array_person, Person*, M_POD_OPLIST)

struct josephus
{
  int start;
  int step;
  array_person_t people;
};


josephus* josephus_new()
{
  josephus* self = malloc(N*sizeof(josephus));
  return self;
}
 
int josephus_destroy(josephus* self)
{
  free(self);
  return SUCCESS;
}

int josephus_init(josephus* self, int start, int step)
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
  array_person_init(self->people);
  return SUCCESS;
}

int josephus_get_size(josephus* self)
{
  return array_person_size(self->people);
}

int josephus_append(josephus* self, Person* someone)
{
  array_person_push_back(self->people, someone);
  return SUCCESS;
}

int josephus_pop(josephus* self, Person** target, int index)
{
  array_person_pop_at(target, self->people, index);
  return SUCCESS;
}

int josephus_result(josephus *self, Person** result, int* n)
{
  int current_id = self->start - 1;
  int length = array_person_size(self->people);

  for (int i = 0; i<length; i++)
  {
    current_id = (current_id + self->step - 1) % array_person_size(self->people);
    result[i] = *(array_person_get(self->people, current_id));
    array_person_pop_at(NULL, self->people, current_id);
  }
  
  return SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

#include "josephus.h"
#include "person.h"

Person* create_josephus_person(char** data, int* n)
{
  Person* person = (Person*)malloc(*n*sizeof(Person));
  for (int i=0;i<*n;i++)
  {
      person[i] = str_to_person(data[i]);
  }
  return person;
}

Person* out_people(Person* person, int* n, int step, int start)
{
  Person* result = (Person*)malloc(*n*sizeof(Person));
  int nonzero_step, i, id_ = start-1;
  int *ring = (int *)malloc(*n*sizeof(int));
  for (i = 0; i < *n; i++)
    ring[i] = 1;
  for (i = 0; i < *n; i++)
  {
    nonzero_step = 0;
    while (nonzero_step < step)
    {
      if (id_ == *n)
        id_ = 0;
      if (ring[id_])
        nonzero_step++;
      id_++;
    }
    ring[id_ - 1] = 0;
    result[i] = person[id_ - 1];
  }
  free(ring);
  return result;
}
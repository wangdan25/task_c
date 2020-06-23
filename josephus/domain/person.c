#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

#define SUCCESS 1
#define N 100
#define INVALID_AGE -1;

struct Person
{
    char name[10];
    int age;
};

Person* person_new()
{  
  Person* self = malloc(N*sizeof(Person));  
  return self;
}

void person_destroy(Person* self)
{
  free(self->name);
}

int person_init(Person* self, char* name, int age)
{
  if (age < 0)
  {
    return INVALID_AGE;
  }
  self->age = age;
  strcpy(self->name, name);
  return SUCCESS;
}

Person* person_from_str(char* data)
{
    Person *self = person_new();
    char name[10] = {0};
    char age[3];
    int split_index = 0;
    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == ',')
        {
            split_index = i;
            break;
        }
    }
    
    for (int i = 0; i < split_index; i++)
    {
        name[i] = data[i];
    }

    for (int i = 0; i < strlen(data) - split_index - 1; i++)
    {
        age[i] = data[i + split_index + 1];
    }
    int age1 = atoi(age);
    person_init(self, name, age1);
    return self;
}

void person_show(Person** person, int* n)
{
  char age[3];
  for (int i=0;i<*n;i++)
  {
    itoa(person[i]->age, age, 10);
    printf("名字是%s,年龄是%s\n", person[i]->name, age);
  }
}
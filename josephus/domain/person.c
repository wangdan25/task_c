#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Person str_to_person(char* data)
{
    Person person;
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
    strcpy(person.name, name);
    person.age = atoi(age);
    return person;
}

void show_people(Person* person, int* n)
{
  char age[3];
  for (int i=0;i<*n;i++)
  {
    itoa(person[i].age, age, 10);
    printf("名字是%s,年龄是%s\n", person[i].name, age);
  }
}
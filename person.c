#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

Person str_to_person(char* data)
{
    Person person;
    char *name = malloc(10);
    char age[3];
    int split_index;
    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == ',')
        {
            split_index = i;
            break;
        }
        if (i == strlen(data))
        {
            exit(1);
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
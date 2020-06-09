#ifndef PERSON_H
#define PERSON_H

typedef struct person
{
    char name[10];
    int age;
}Person;

Person str_to_person(char* data);

#endif
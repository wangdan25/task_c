#ifndef PERSON_H
#define PERSON_H

typedef struct person
{
    char name[10];
    int age;
}Person;

Person* create_josephus_person(char** data, int* n);
Person str_to_person(char* data);
void show_people(Person* person, int* n);

#endif
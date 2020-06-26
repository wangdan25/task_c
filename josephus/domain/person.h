#ifndef PERSON_H
#define PERSON_H

typedef struct Person Person;

Person* person_new();
int person_destroy(Person* person);
Person* person_from_str(char* data);
char* person_get_name(Person* self);
int person_get_age(Person* self);

#endif
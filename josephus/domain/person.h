#ifndef PERSON_H
#define PERSON_H

typedef struct Person Person;

Person* person_new();
int person_destroy(Person* person);
Person* person_from_str(char* data);
void person_show(Person** person, int* n);

#endif
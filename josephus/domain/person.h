#ifndef PERSON_H
#define PERSON_H

typedef struct Person Person;

Person* person_new();
void person_destroy(Person* person);
int person_create_josephus_ring(char** data, Person** person, int* n);
// Person* person_from_str(char* data);
Person* person_from_str(char* data);
void person_show(Person** person, int* n);

#endif
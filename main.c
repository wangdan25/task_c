#include <stdio.h>
#include <stdlib.h>

#include "person.h"
#include "josephus.h"
#include "reader.h"

int main()
{
    int len = 0;
    Reader* reader = reader_new();
    char* path = "person.txt";
    reader_get_line(path, &len);
    reader_init(reader, path, len);
    char** data = malloc(500*sizeof(char*));
    reader_get_file_data(reader, data);

    Person** ring = malloc(100*sizeof(Person*));
    for (int i= 0; i<len; i++)
    {
        ring[i] = person_from_str(data[i]);
    }
    printf("---------------ring--------------\n");
    for (int i = 0;i < len; i++)
    {
        char* name = person_get_name(ring[i]);
        int age = person_get_age(ring[i]);
        printf("name: %s, age: %d\n", name, age);
    }
    printf("**********************************\n");

    int step, start;
    step = 2;
    start =1;
    josephus* self = josephus_new();
    josephus_init(self, start, step);
    for (int i= 0; i<len; i++)
    {
        josephus_append(self, ring[i]);
    }

    Person** result = malloc(100*sizeof(Person*));
    josephus_result(self, result, &len);
    printf("---------------result--------------\n");
    for (int i = 0;i < len; i++)
    {
        char* name = person_get_name(result[i]);
        int age = person_get_age(result[i]);
        printf("name: %s, age: %d\n", name, age);
    }
    printf("***********************************\n");

    free(ring);
    free(result);
    free(data);
    reader_destroy(reader);
    josephus_destroy(self);
    system("pause");
    return 0;
}
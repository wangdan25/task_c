#include <stdio.h>
#include <stdlib.h>

#include "person.h"
#include "josephus.h"
#include "reader.h"

int main()
{
    int len = 0;
    char** data = reader_data_new();
    reader("person.txt", data, &len);

    Person** ring = malloc(100*sizeof(Person*));
    for (int i= 0; i<len; i++)
    {
        ring[i] = person_from_str(data[i]);
    }
    printf("---------------ring--------------\n");
    person_show(ring, &len);
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
    person_show(result, &len);
    printf("***********************************\n");

    reader_data_destroy(data);
    free(ring);
    free(result);
    josephus_destroy(self);
    system("pause");
    return 0;
}
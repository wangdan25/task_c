#include <stdio.h>
#include <stdlib.h>

#include "person.h"
#include "josephus.h"
#include "reader.h"

int main()
{
    int step, start;
    step = 2;
    start =1;
    int len = 0;
    josephus* self = josephus_new();
    char** data = reader_data_new();
    reader("person.txt", data, &len);
    josephus_init(self,data, start, step, &len);
    // printf("约瑟夫环里原始的人是：\n");
    // person_show(self->people, &len);
    // printf("**********************************************\n");
    Person** result = malloc(100*sizeof(Person*));
    josephus_get_result(self, result, &len);
    printf("淘汰的人是：\n");
    person_show(result, &len);
    reader_data_destroy(data);
    free(result);
    josephus_destroy(self);
    system("pause");
    return 0;
}
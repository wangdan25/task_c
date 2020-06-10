#include <stdio.h>
#include <stdlib.h>

#include "person.h"
#include "josephus.h"
#include "reader.h"

int main()
{
    int step, start;
    int len = 0;
    int *n = &len;
    char** data = reader("person.txt", n);
    Person* person = create_josephus_person(data, n);
    printf("约瑟夫环里原始的人是：\n");
    show_people(person, n);
    printf("**********************************************\n");
    printf("请输入步进和起始值（用空格隔开）：\n");
    scanf("%d %d",&step, &start);
    Person* result = out_people(person, n, step, start);
    printf("淘汰的人是：\n");
    show_people(result, n);
    system("pause");
    return 0;
}
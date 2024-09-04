#include <cstdint>

typedef unsigned long long size_t;

extern "C" int scanf(const char*, ...);
extern "C" int printf(const char*, ...);
extern "C" void* malloc(size_t);
extern "C" void free(void*);
extern "C" int memcmp(const void*, const void*, size_t);
extern "C" size_t strlen(const char* str);
extern "C" int strcmp(const char*, const char*);

#define ERROR 1

typedef char surname_student[100];
typedef char name_student[100];    
typedef uint8_t course_student;

struct table_student {
    name_student name;
    surname_student surname;
    course_student course;
};

table_student* ptr_to_struct = nullptr;

int set_student_table(size_t& SIZE) {
    printf("Enter table size:\n");
    scanf("%zu", &SIZE);
    ptr_to_struct = (table_student*)malloc(sizeof(table_student) * SIZE);
    if (ptr_to_struct == nullptr) {
        printf("Memory allocation failed\n");
        return ERROR;
    }

    for (size_t i = 0; i < SIZE; ++i) {
        printf("Enter name for student %zu:\n", i + 1);
        scanf("%99s", ptr_to_struct[i].name);  
        printf("Enter surname for student %zu:\n", i + 1);
        scanf("%99s", ptr_to_struct[i].surname);  
        printf("Enter course for student %zu:\n", i + 1);
        scanf("%hhu", &ptr_to_struct[i].course);
    }
    return 0;
}

int find_student(table_student* ptr_to_struct, size_t SIZE, name_student nm, surname_student snm) {
    for (size_t i = 0; i < SIZE; ++i) {
        if (strcmp(ptr_to_struct[i].name, nm) == 0 && 
            strcmp(ptr_to_struct[i].surname, snm) == 0) {
            printf("User found\n");
            return 0;
        }
    }
    return ERROR; 
}

int main() {
    size_t SIZE = 0; 
    uint8_t descriptor_set = set_student_table(SIZE);
    if (descriptor_set != 0) {
        printf("Error in set_student_table()\n");
        return ERROR;
    }

    name_student buffer_name;
    printf("Enter (name): \n");
    scanf("%99s", buffer_name); 

    surname_student buffer_surname; 
    printf("Enter (surname): \n");
    scanf("%99s", buffer_surname); 

    uint8_t descriptor_find = find_student(ptr_to_struct, SIZE, buffer_name, buffer_surname);
    if (descriptor_find == ERROR) {
        printf("Not found\n");
    }

    free(ptr_to_struct);
    return 0;
}

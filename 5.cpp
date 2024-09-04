#include <cstdint>


typedef unsigned long long size_t;

extern "C" int		scanf(const char*, ...);
extern "C" int		printf(const char*, ...);
extern "C" void*	malloc(size_t);
extern "C" void*	free(void*);
extern "C" int		memcmp(const void*, const void*, size_t count);
extern "C" size_t   strlen(const char* str);

#define ERROR 1


typedef const char* surname_student;
typedef const char* name_student;
typedef uint8_t		course_student;

struct table_student {
	name_student	name[100];
	surname_student	surname[100];
	course_student	course;
};


table_student* ptr_to_struct = nullptr;

const size_t SIZE = 0U;

int set_student_table() {
	printf("enter table size:\n");
	scanf("%d", &SIZE);
	ptr_to_struct = (table_student*)malloc(sizeof(table_student) * SIZE);
	if (ptr_to_struct == nullptr) {
		printf("Memory allocation failed\n");
		return ERROR;
	}


	for (size_t i = 0; i < SIZE; ++i) {
		printf("Enter name for student %zu:\n", i + 1);
		scanf("%s", ptr_to_struct[i].name);
		printf("Enter surname for student %zu:\n", i + 1);
		scanf("%s", ptr_to_struct[i].surname);
		printf("Enter course for student %zu:\n", i + 1);
		scanf("%hhu", &ptr_to_struct[i].course);
	}
	return 0;
}

int find_student(table_student* ptr_to_struct, name_student nm, surname_student snm) {
	for (size_t i = 0; i < SIZE; ++i) {
		if (memcmp(ptr_to_struct[i].name, nm, strlen(nm)) &&
			memcmp(ptr_to_struct[i].surname, snm, strlen(snm))
			== 0) { printf("user found"); return 0; }
	}
	ERROR;

}



int main(int argc, char** argv) {
	uint8_t descriptor_set = set_student_table();
	if (descriptor_set != 0) {
		printf("Error in set_student_table()");
		return ERROR;
	}

	char buffer_name[100];
	printf("Enter (name): \n");
	scanf("%s", buffer_name);

	char buffer_surname[100]; 
	printf("Enter (surname): \n");
	scanf("%s", buffer_surname);

	uint8_t descriptor_find = find_student(ptr_to_struct, buffer_name, buffer_surname);
	if (descriptor_find == ERROR) {
		printf("not found\n");
	}

	free(ptr_to_struct);
	return 0;
}



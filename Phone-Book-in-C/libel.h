#ifndef _LIBCL_H_
#define _LIBCL_H_
#define MAXPPL 500
#define MAXLEN 25


//ADD STRUCTURE(S) HERE

typedef struct personal_info{
	char first[MAXLEN];
	char last[MAXLEN];
	char position[MAXLEN];
	double salary;
}pi;
typedef struct employee_list{
	pi person[MAXPPL];
	int num_people;
}el;	

//ADD PROTOTYPES HERE

void load_el(el * emp_list, const  char * filename);
void add_person(el * emp_list, pi person);
void search_el(el emp_list, char find_name[ ]);
void save_el(el * emp_list, const char * filename);
void gen_csv_sal(el * emp_list);
void gen_csv_pos(el * emp_list);
char * gen_file_name(char * filename, int filename_size, char * suffix, int suffix_size);
#endif



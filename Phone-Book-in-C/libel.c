#include "libel.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//ADD FUNCTION DEFINITIONS FOR LOAD_EL, SAVE_EL, ADD_PERSON, AND SERACH_EL HERE

void load_el(el * emp_list, const  char * filename)
{
	int c,i;
	//emp_list->num_people=9;
	FILE *fp;
	fp=fopen(filename,"r");
	fscanf(fp,"%d", &emp_list->num_people);	
	for(i=0;i<(emp_list->num_people);i++){
	  fscanf(fp,"%s %s %s %lf",emp_list->person[i].first,emp_list->person[i].last,emp_list->person[i].position,&emp_list->person[i].salary);}	
	fclose(fp);
}

void add_person(el * emp_list, pi person)
{
	emp_list->person[emp_list->num_people] = person;
	emp_list->num_people++;
}

void search_el(el emp_list, char find_name[ ])
    {        
        int X,i, count=0; 

        for (i = 0; i<emp_list.num_people; i++){      
            X = strcmp(find_name,emp_list.person[i].first);
            if(X==0){
                printf("\nName: %s %s (%s)\n", emp_list.person[i].first, emp_list.person[i].last,emp_list.person[i].position);
		printf("Salary: %0.2lf\n",emp_list.person[i].salary);
                count++;
            }        
        }
        
        if(count==0){
            printf("No entries with that name.\n");}
    }

void save_el(el * emp_list, const char * filename)
{
   	int i;
	FILE *fp;
	fp=fopen(filename,"w");
	fprintf(fp,"%d\n",emp_list->num_people);
	for(i=0;i<(emp_list->num_people);i++){
	  fprintf(fp,"%s\n%s\n%s\n%lf\n",emp_list->person[i].first,emp_list->person[i].last,emp_list->person[i].position,emp_list->person[i].salary);}
	fclose(fp);
}

//ADD FUNCTIONALITY TO THE BELOW FUNCTIONS

void gen_csv_sal(el * emp_list){
char csv_prefix[14] = "csv_list_sal";
char csv_suffix[5] = ".csv";
char * filename = gen_file_name(csv_prefix, 14, csv_suffix, 5);
FILE * fp = fopen(filename, "w");
int i,search = -1;
double sal;
char ml[5];

while(search == -1) {

    printf("Search for salaries (format: 65000.00 less  or  100000 more): ");
    scanf("%lf %s", &sal, ml);
    if(strcmp(ml,"less")==0){/*if 'ml' is "less"*/

        //ADD CODE HERE TO PRINT TO THE CSV FILE AND SCREEN
	
    	for(i=0;i<(emp_list->num_people);i++){
	  if((emp_list->person[i].salary)<sal){
            fprintf(fp,"%s,%s,%s,%lf\n",emp_list->person[i].first,emp_list->person[i].last,emp_list->person[i].position,emp_list->person[i].salary);
	    printf("Wrote: %s,%s,%s,%lf\n",emp_list->person[i].first,emp_list->person[i].last,emp_list->person[i].position,emp_list->person[i].salary);
	  }
	}        
	search = 0;
    }
    else if(strcmp(ml,"more")==0){/*if 'ml' is "more"*/

        //AD CODE HERE TO PRINT TO THE CSV FILE AND SCREEN
	for(i=0;i<(emp_list->num_people);i++){
	  if((emp_list->person[i].salary)>sal){
          fprintf(fp,"%s,%s,%s,%lf\n",emp_list->person[i].first,emp_list->person[i].last,emp_list->person[i].position,emp_list->person[i].salary);
	  printf("Wrote: %s,%s,%s,%lf\n",emp_list->person[i].first,emp_list->person[i].last,emp_list->person[i].position,emp_list->person[i].salary);
	  }
	}
        search = 0;
    }
    else
        printf("Must type more or less\n");
	
}
fclose(fp);
printf("CSV generated: %s\n\n", filename);
return;
}

//ADD FUNCTIONALITY TO THE BELOW FUNCTION

void gen_csv_pos(el * emp_list){
char csv_prefix[14] = "csv_list_pos";
char csv_suffix[5] = ".csv";
char * filename = gen_file_name(csv_prefix, 14, csv_suffix, 5);
FILE * fp = fopen(filename, "w");
    
char pos[25];
printf("Enter company position to search for: ");
scanf("%s", pos);
    
//ADD CODE HERE TO PRINT TO THE CSV FILE AND SCREEN
int i;
for(i=0;i<(emp_list->num_people);i++){
	if(strcmp(pos,(emp_list->person[i].position))==0){
          fprintf(fp,"%s,%s,%s,%lf\n",emp_list->person[i].first,emp_list->person[i].last,emp_list->person[i].position,emp_list->person[i].salary);
	  printf("Wrote: %s,%s,%s,%lf\n",emp_list->person[i].first,emp_list->person[i].last,emp_list->person[i].position,emp_list->person[i].salary);
	}
}
fclose(fp);
printf("CSV generated: %s\n\n", filename);
return;
}


char * gen_file_name(char * filename, int filename_size, char * suffix, int suffix_size){
	FILE *fp;
    char file_num[3];
    int max_file_num = 99, i;
    char * new_filename = (char *) malloc((filename_size + suffix_size + 2) * sizeof(char));
    for(i = 0;i <= max_file_num; i++){
        strcpy(new_filename, filename);
        sprintf(file_num, "%d", i);
        strcat(new_filename, file_num);
        strcat(new_filename, suffix);
        if (fopen(new_filename, "r") ==NULL) {//if the filename doesnt exsist
            fp = fopen(new_filename, "r");
            break;
        }
    }
       //printf("NEW File name generated: %s\n", new_filename);
    
    return new_filename;
}


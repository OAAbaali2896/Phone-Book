#include <stdio.h>
#include <string.h>
#include "libel.h"


int main () {
const char * filename = "directory.txt";
char * csv_prefix = "csv_list";
char find_name[25];
pi person;
el emp_list;
emp_list.num_people = 0;
load_el(&emp_list, filename);
printf("%d employees loaded.\n", emp_list.num_people);
char cont = 'x', //initialize continue to something other than 'Y' or 'N'
     tmp; //
int state = -1,
    correct_search_val;
char srch_critera[25] = "init";
while (state != 4){
    while(state < 1 || state > 4){
        printf("1:\tAdd employee and salary\n");
        printf("2:\tSearch directory by first name\n");
        printf("3:\tGenerate CSV\n");
        printf("4:\tSave and exit program\n");
        printf("Enter an option (1-4): ");
        scanf("%d", &state);
        if(state < 1 || state > 4) {
            printf("\nError: number not in range\n\n");
        }
    }

    switch(state) {

        //add employee and salary
        case 1:
            //add one person
            printf("Enter a first name: ");
            scanf("%s", person.first);
            printf("Enter %s's last name: ", person.first);
            scanf("%s", person.last);
            printf("Enter %s's occupation: ", person.first);
            scanf("%s", person.position);
            printf("Enter %s's Salary: ", person.first);
            scanf("%lf", &person.salary);
            scanf("%c", &tmp);
            printf("Employee added.\n");
            add_person(&emp_list, person);
            //determine to add more people to the employee list
            while(cont != 'N' && emp_list.num_people < MAXPPL) {
                cont = 'x';
                while(cont != 'Y' && cont != 'N'){
                    printf("Would you like to enter another name (Y/N): "); 
                    scanf("%c", &cont);
                    if (cont != 'Y' && cont != 'N') {
                        printf("Error: User entered '%c'. Must enter either 'Y' or 'N'\n", cont);
                    }
                    scanf("%c", &tmp);
                }
                if(cont != 'N') {
                    printf("Enter a first name: ");
                    scanf("%s", person.first);
                    printf("Enter %s's last name: ", person.first);
                    scanf("%s", person.last);
                    printf("Enter %s's occupation: ", person.first);
                    scanf("%s", person.position);
                    printf("Enter %s's Salary: ", person.first);
                    scanf("%lf", &person.salary);
                    scanf("%c", &tmp);
                    printf("Employee added.\n");
                    add_person(&emp_list, person);
                }
            }
            printf("\nReturning to main menu...\n\n");
            state = -1;
            break;


        //search directory by first name
        case 2:

            cont = 'x'; //reset continue to neither 'Y' nor 'N'
            while(cont != 'N'){
                cont = 'x';
                printf("Enter a person's name to search for: ");
                scanf("%s", find_name);
                scanf("%c", &tmp);
                search_el(emp_list, find_name);
                while(cont != 'Y' && cont != 'N'){
                    printf("\nContinue (Y/N)? "); 
    
                    scanf("%c", &cont); fflush(stdout); //, &tmp);
                    scanf("%c", &tmp);
                    if (cont != 'Y' && cont != 'N') {
                        printf("Error: User entered '%c'. Must enter either 'Y' or 'N'.\n", cont);
                    }


                }
            }
            printf("\nReturning to main menu...\n\n");
            state = -1;
            break;

        
        //generate CSV file
        case 3:
            correct_search_val = -1;
            while(correct_search_val != 0) {
                printf("Generate CSV based on? (\"Salary\", \"Position\"): ");
                scanf("%s", srch_critera);
                if(!strcmp(srch_critera, "Salary")){
                    printf("Generating CSV based on salary...\n");
                    gen_csv_sal(&emp_list);
                    correct_search_val = 0;
                }
                else if(!strcmp(srch_critera, "Position")){
                    printf("Generating CSV based on position...\n");
                    gen_csv_pos(&emp_list);
                    correct_search_val = 0;
                }
                else
                    printf("Options are: \"Salary\", \"Position\"\n");
            }
            printf("Returning to main menu...\n\n");
            state = -1;


        case 4:
        break;
    }//end switch
}//end while

//save the employee list
save_el(&emp_list, filename);
printf("%d employees saved.\n", emp_list.num_people);
return 0;
}//end main

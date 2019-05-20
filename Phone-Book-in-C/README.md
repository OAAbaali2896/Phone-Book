# Phone-Book-in-C
This program is written in C.

# Main file (employee list.c):
Main function is found in **employee_list.c** and begins by loading the employees that are already
saved in a file named “**directory.txt**”. Loading the employee list is done by calling the function
**load_el()**. A state machine is then entered to determine what the user would like to do. Options
1-4 are given: 1 adds a employee, 2 searches all employees by first name, 3 generates a CSV, and
4 saves the changes to the file and exits the program. If any other number is entered, the program
remains at this menu. A more detailed description of each option is given below.

## 1: Add Employee and Salary
If the user enters 1, the function **add_person()** is called, and the program enters a loop. The
user is prompted to enter ‘Y’ or ‘N’. If ‘Y’ is entered, the function is called again. The loop only
breaks when ‘N’ is entered. The program then returns to the main menu.

## 2: Search Directory by First Name
If the user enters 2, **search_el()** is called. The user is prompted to enter ‘Y’ or ‘N’, if the user
enters ‘Y’ then **search el()** is called again. The searching continues until the user enters ‘N’. The
program then returns to the main menu.

## 3: Generate CSV
If the user enters 3, a prompt is given to enter a string. If the string matches “Position” then
the function **gen_csv_pos()** is called; if the string matches “Salary” then **gen_csv_sal()** is called.
If any other string is entered, the user is reminded of the options and prompted again. After one
of the functions is called, the program returns to the main menu.

## 4: Save and Exit Program
If the user enters 4, the program breaks out of the state machine, saves the employee list (by
calling **save_el()**), and exits the program. Note that the employee list is only saved if the user
enters 4, NOT if the user presses **ctrl+c**.

# After Executing the Program
In the file, **Phone-Book-in-C**:
* **directory.txt** contains the list of 7 entries.
* **csv_list_sal0.csv** is displays the entries that have their salaries less than $300,000.
* **a.out** is the executable file after writting the command line in Linux Terminal: **gcc employee_list.c libel.c**.

# Thank You
## Email: osamaafz@buffalo.edu / osama.afzal96@gmail.com
## Linkedin - https://www.linkedin.com/in/osamaabaali/

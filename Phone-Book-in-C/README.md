# Phone-Book-in-C (Programming in C/C++ Course)
This program is written in C.

# A - Main file (employee_list.c)
Main function is found in **employee_list.c** and begins by loading the employees that are already
saved in a file named “**directory.txt**”. Loading the employee list is done by calling the function
**load_el()**. A state machine is then entered to determine what the user would like to do. Options
1-4 are given:

### 1: Add Employee and Salary
If the user enters 1, the function **add_person()** is called, and the program enters a loop. The
user is prompted to enter ‘Y’ or ‘N’. If ‘Y’ is entered, the function is called again. The loop only
breaks when ‘N’ is entered. The program then returns to the main menu.

### 2: Search Directory by First Name
If the user enters 2, **search_el()** is called. The user is prompted to enter ‘Y’ or ‘N’, if the user
enters ‘Y’ then **search el()** is called again. The searching continues until the user enters ‘N’. The
program then returns to the main menu.

### 3: Generate CSV
If the user enters 3, a prompt is given to enter a string. If the string matches “Position” then
the function **gen_csv_pos()** is called; if the string matches “Salary” then **gen_csv_sal()** is called.
If any other string is entered, the user is reminded of the options and prompted again. After one
of the functions is called, the program returns to the main menu.

### 4: Save and Exit Program
If the user enters 4, the program breaks out of the state machine, saves the employee list (by
calling **save_el()**), and exits the program. Note that the employee list is only saved if the user
enters 4, NOT if the user presses **ctrl+c**.

# B - Structures (libel.h)
The system uses two structures. The first structure holds information about each employee. This
structure is named **personal_info**. **personal_info** is to have 3 character arrays (of length
**MAXLEN** defined in **libel.h**) to hold the employee’s first name, last name, position. The structure
must also hold a double for the salary. In the line directly below the structure, add the following
line: `typedef struct personal_info pi;`

This line literally renames ‘**struct personal_info**’ to ‘**pi**’. This means that create a new instance
of this structure, ‘**pi newpi;’** may be written instead of `struct personal info newpi;` (it saves
quite a bit of typing).

The second structure is a list of all the employees. It contains an array of **personal_info** structures,
and an integer to store the current number of people in the employee list. The name of this structure
is **employee list**. The maximum number of people in the array is **MAXPPL**, which is also defined in
**libel.h**. 

# C - Functions (libel.c)
### 1: void load_el(el * emp_list, const  char * filename)
This function loads the employee list from a text file, **directory.txt**. This function must take a pointer to a **employee_list**, and a **const char*** string (which is the filename). After all the employees have been loaded from the file, print **''%d employees loaded.\n''**, where **%d** is the number of employees loaded.

### 2: void add_person(el * emp_list, pi person)
This function add an employee **personal_info (pi)** to the **employee_list (el)**,
After the new employee information is entered, the program will call the function **add_person()** and pass this information to the function.

### 3: void search el(el emp_list, char find_name[ ]); 
This function searches the employee list for a first name. If there is no employee found, print **'No entries with that name.\n'**.

### 4: void save_el(el * emp_list, const char * filename)
This function saves the employee list in the same manner as directory.txt.

### 5: void gen_csv_sal(el * emp_list)
This function generates a CSV based on salary.

The first if (in the while loop) should check if the variable (string) **ml** is equal to **“less”**. If the strings are equal, then generate a Comma Separated Variable (CSV) file of all the people in the employee list with a salary **LESS** than **sal**.

The second (**else if**) statement should check if the string **ml** is equal to **“more”**. If this is true, generate a CSV of all the people in the employee list with a salary **MORE** than **sal**.

### 6: void gen_csv_pos(el * emp_list)
This function generatesa CSV based on occupation. The code should compare pos to the company position (occupation) of each employee in the list. If the occupation is the occupation we are searching for, write it to the CSV with the file pointer **fp**.

# After Executing the Program
In the file, **Phone-Book-in-C**:
* **directory.txt** contains the list of 7 entries.
* **csv_list_sal0.csv** displays the entries that have their salaries less than $300,000.
* **csv_list_pos0.csv** displays the entries that have their occupation to students.
* **a.out** is the executable file after writting the command line in Linux Terminal: **gcc employee_list.c libel.c**.

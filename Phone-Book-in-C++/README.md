# Phone Book in C++
This program is written in C++.

# A - Class personal_info
**Private member function prototypes for the personal_info class:** 
```C++
strings first;                           
strings last;                        
strings position;                        
double salary;                 
```
**Public member function prototypes for the personal_info class:**                              
```C++
void setFirst(string first);                                  
void setLast(string last);                    
void setPosition(string position);                      
void setSalary(double salary);                      
string getFirst();                                
string getLast();                           
string getPosition();                           
double getSalary();                           
```
To access private members of a class, there are typically *public* get and set functions. Get/set member function prototypes for the data members of the class **personal_info**. There is a get and a set for each *private data member*.
A set function will set the private member equal to the functions input.
A get function will return the private member’s value.

# B - Class employee_list
**Private member function prototypes for the employee_list class:** 
```C++
vector<personal_info> people
```
**Public member function prototypes for the employee_list class:** 
```C++
void load el(string filename);
void save el(string filename);
void add person(personal info person);
void search el(string find name);
void gen csv sal();
void gen csv pos();
int get num people();
```
The only difference between the code written in C & C++ is by rewriting the structures (C) to classes (C++).
Overall, the structure of this code is very similar.

# After Executing the Program
In the folder:
* directory.txt contains the list of 7 entries.
* csv_list_sal0.csv displays the entries that have their salaries more than $45,000.
* csv_list_pos0.csv displays the entries that have their occupation to chef.
* a.out is the executable file after writting the command line in Linux Terminal: g++ -std=c++11 libel.cpp employee_list.cpp.               

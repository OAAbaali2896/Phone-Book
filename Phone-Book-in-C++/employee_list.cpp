#include "libel.hpp"

int main () {
    string filename = "directory.txt";
    string csv_prefix = "csv_list";
    string find_name;
    personal_info person;
    employee_list emp_list;
    string first, last, position;
    double salary;

    
    emp_list.load_el(filename);
    
    cout << emp_list.get_num_people() << " employees loaded." << endl;
    char cont = 'x', //initialize continue to something other than 'Y' or 'N'
    tmp; //
    int state = -1,
    correct_search_val;
    string srch_critera = "init";


while (state != 4){
    while(state < 1 || state > 4){
        cout << "1:\tAdd employee and salary\n";
        cout << "2:\tSearch directory by first name\n";
        cout << "3:\tGenerate CSV\n";
        cout << "4:\tSave and exit program\n";
        cout << "Enter an option (1-4): ";
        cin >> state;
        if(state < 1 || state > 4) {
            cout << "\nError: number not in range\n\n";
        }
    }

    switch(state) {

        //add employee and salary
        case 1:
            //add one person
            cout << "Enter a first name: ";
            cin >> first;
            cout << "Enter " << first << "'s last name: ";
            cin >> last;
            cout << "Enter " << first << "'s occupation: ";
            cin >> position;
            cout << "Enter " << first << "'s Salary: ";
            cin >> salary;
            person.setFirst(first);
            person.setLast(last);
            person.setPosition(position);
            person.setSalary(salary);
            emp_list.add_person(person);
            cout << "Employee added.\n";
            
            //determine to add more people to the employee list
            while(cont != 'N' && emp_list.get_num_people() < MAXPPL) {
                cont = 'x';
                while(cont != 'Y' && cont != 'N'){
                    cout << "Would you like to enter another name (Y/N): ";
                    cin >> cont;
                    if (cont != 'Y' && cont != 'N') {
                        cout << "Error: User entered " << cont << ". Must enter either 'Y' or 'N'\n";
                    }
                }
                if(cont != 'N') {
                    cout << "Enter a first name: ";
                    cin >> first;
                    cout << "Enter " << first << "'s last name: ";
                    cin >> last;
                    cout << "Enter " << first << "'s occupation: ";
                    cin >> position;
                    cout << "Enter " << first << "'s Salary: ";
                    cin >> salary;
                    person.setFirst(first);
                    person.setLast(last);
                    person.setPosition(position);
                    person.setSalary(salary);
                    emp_list.add_person(person);
                    cout << "Employee added.\n";
                }
            }
            cout << "\nReturning to main menu...\n\n";
            state = -1;
            break;


            
            
        //search directory by first name
        case 2:

            cont = 'x'; //reset continue to neither 'Y' nor 'N'
            while(cont != 'N'){
                cont = 'x';
                cout << "Enter a person's name to search for: ";
                cin >> find_name;
                emp_list.search_el(find_name);
                while(cont != 'Y' && cont != 'N'){
                    cout << "\nContinue (Y/N)? ";
    
                    cin >> cont;
                    if (cont != 'Y' && cont != 'N') {
                        cout << "Error: User entered " << cont << ". Must enter either 'Y' or 'N'.\n";
                    }


                }
            }
            cout << "\nReturning to main menu...\n\n";
            state = -1;
            break;

        
        //generate CSV file
        case 3:
            correct_search_val = -1;
            while(correct_search_val != 0) {
                cout << "Generate CSV based on? (\"Salary\", \"Position\"): ";
                cin >> srch_critera;
                if(srch_critera == "Salary"){
                    cout << "Generating CSV based on salary..." << endl;
                    emp_list.gen_csv_sal();
                    correct_search_val = 0;
                }
                else if(srch_critera == "Position"){
                    cout << "Generating CSV based on position..." << endl;
                    emp_list.gen_csv_pos();
                    correct_search_val = 0;
                }
                else
                    cout << "Options are: \"Salary\", \"Position\"\n";
            }
            cout << "Returning to main menu...\n\n";
            state = -1;

            
        case 4:
        break;
    }//end switch
}//end while


     
//save the employee list
emp_list.save_el(filename);
cout << emp_list.get_num_people() << " employees saved." << endl;
return 0;

}//end main

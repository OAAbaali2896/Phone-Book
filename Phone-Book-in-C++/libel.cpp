#include "libel.hpp"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

//ADD FUNCTION DEFINITIONS FOR LOAD_EL, SAVE_EL, ADD_PERSON, AND SERACH_EL HERE

void personal_info::setFirst(string first1)
{
	first=first1;
}
string personal_info::getFirst()
{
	return first;
}
void personal_info::setLast(string last1)
{
	last=last1;
}
string personal_info::getLast()
{
	return last;
}
void personal_info::setPosition(string position1)
{
	position = position1;
}
string personal_info::getPosition()
{
	return position;
}
void personal_info::setSalary(double salary1)
{
	salary = salary1;
}
double personal_info::getSalary()
{
	return salary;
}

int employee_list::get_num_people()
{
    return people.size();
}
void employee_list::load_el(string filename)
{
    string first1,last1,position1;
    double salary1;
    ifstream ist {filename};
    personal_info per;
   
    while( ist>>first1>>last1>>position1>>salary1){
        per.setFirst(first1);
        per.setLast(last1);
        per.setPosition(position1);
        per.setSalary(salary1);
        people.push_back(per);
    }
}


void employee_list::add_person(personal_info person)
{
	people.push_back(person);
}
void employee_list::search_el(string find_name)
{
	int i,num_found=0;
	for(i=0;i<get_num_people();i++){
		if(find_name==people[i].getFirst()){
			cout<<"\nName: "<<people[i].getFirst()<<" "<<people[i].getLast()<<" ("<<people[i].getPosition()<<")"<<endl;
			cout<<"Salary: "<<people[i].getSalary()<<endl;
			num_found++;
		}
	}
	if(num_found==0){
		cout<<"No entries with that name."<<endl;
	}
}
void employee_list::save_el(string filename)
{
    int i;
    ofstream ost {filename};
    
    for(i=0;i<get_num_people();i++){
	ost<<people[i].getFirst()<<endl;
	ost<<people[i].getLast()<<endl;
	ost<<people[i].getPosition()<<endl;
    ost<<people[i].getSalary()<<endl;}
}


//ADD FUNCTIONALITY TO THE BELOW FUNCTIONS

void employee_list::gen_csv_sal(){
string csv_prefix = "csv_list_sal";
string csv_suffix = ".csv";
string  filename = gen_file_name(csv_prefix, csv_suffix);
 ofstream ost {filename};
int i,search = -1;
double sal;
string ml;

while(search == -1) {

 cout<<"Search for salaries (format: 65000.00 less  or  100000 more): ";
    cin>>sal>>ml;
    if(ml=="less"){//if 'ml' is "less"

        //ADD CODE HERE TO PRINT TO THE CSV FILE AND SCREEN
	
    	for(i=0;i<get_num_people();i++){
	        if((people[i].getSalary())<sal){
                cout<<"Wrote: "<<people[i].getFirst()<<","
                               <<people[i].getLast()<<","
                               <<people[i].getPosition()<<","
                               <<people[i].getSalary()<<endl;
             ost<<people[i].getFirst()<<","
             <<people[i].getLast()<<","
             <<people[i].getPosition()<<","
             <<people[i].getSalary()<<endl;
            }
	    }
	search = 0;
    }
    else if(ml=="more"){//if 'ml' is "more"

        //AD CODE HERE TO PRINT TO THE CSV FILE AND SCREEN
        for(i=0;i<get_num_people();i++){
            if((people[i].getSalary())>sal){
                cout<<"Wrote: "<<people[i].getFirst()<<","
                                <<people[i].getLast()<<","
                                <<people[i].getPosition()<<","
                                <<people[i].getSalary()<<endl;
                ost<<people[i].getFirst()<<","
                <<people[i].getLast()<<","
                <<people[i].getPosition()<<","
                <<people[i].getSalary()<<endl;
            }
        }
        search = 0;
    }
    else
        cout<<"Must type more or less"<<endl;
	
}
cout<<"CSV generated: "<< filename<<endl<<endl;
return;
}

//ADD FUNCTIONALITY TO THE BELOW FUNCTION

void employee_list::gen_csv_pos(){
string csv_prefix = "csv_list_pos";
string csv_suffix = ".csv";
string filename = gen_file_name(csv_prefix, csv_suffix);
ofstream ost {filename};
    
string pos;
cout<<"Enter company position to search for: ";
    cin>>pos;
    
//ADD CODE HERE TO PRINT TO THE CSV FILE AND SCREEN
int i;
for(i=0;i<(get_num_people());i++){
    if(people[i].getPosition()==pos){
        cout<<"Wrote: "<<people[i].getFirst()<<","
        <<people[i].getLast()<<","
        <<people[i].getPosition()<<","
        <<people[i].getSalary()<<endl;
        ost<<people[i].getFirst()<<","
        <<people[i].getLast()<<","
        <<people[i].getPosition()<<","
        <<people[i].getSalary()<<endl;
    }
}
       cout<<"CSV generated: "<<filename<<endl<<endl;
return;
}
string gen_file_name(string filename, string suffix){
    string file_num;
    string new_filename;
    int max_file_num=99;
    int j;
    for(j=0;j<=max_file_num;j++){
        new_filename=filename;
        file_num=to_string(j);
        new_filename=new_filename+file_num;
        new_filename=new_filename+suffix;
        ifstream isu (filename);
        if(!isu){
            break;
        }
    }
    return new_filename;
}

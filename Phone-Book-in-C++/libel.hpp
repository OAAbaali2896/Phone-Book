#ifndef _LIBEL_HPP_
#define _LIBEL_HPP_
#define MAXPPL 500
#define MAXLEN 25
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class personal_info {
public:
	void setFirst(string first);
	void setLast(string last);
	void setPosition(string position);
	void setSalary(double salary);
	string getFirst();
	string getLast();
	string getPosition();
	double getSalary();
private:
	string first;
	string last;
	string position;
	double salary;
};

class employee_list {
public:
	void load_el(string filename);
	void save_el(string filename);
	void add_person(personal_info person);
	void search_el(string find_name);
	void gen_csv_sal();
	void gen_csv_pos();
	int get_num_people();
private:
	vector<personal_info> people;
};
string gen_file_name(string filename, string suffix);
#endif

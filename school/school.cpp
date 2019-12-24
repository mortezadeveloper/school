
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

//---------------------------------------------------------
void split(const string& s, char delim, vector<string>& v);
void adminmenu();
void addstudent(vector<string>& student);
void PrintStudent(vector<string> student);
void EditStudent(vector<string>& student);
void DeleteStudent(vector<string>& student);
void empmenu();
//---------------------------------------------------------

int main()
{
	vector<string>student;
	string username,Password;
	bool exit = false;
	while (exit == false)
	{
		bool login = true;
		system("cls");
		cout << "Hello !\nPlease enter username :" << endl;
		getline(cin, username);
		cout << "Please enter password :" << endl;
		getline(cin, Password);
		while (login == true)
		{

			if (username == "admin" && Password == "123")
			{
				system("cls");
				adminmenu();
				int select1;
				cin >> select1;
				switch (select1)
				{
				case 1:
				{
					addstudent(student);
				}
				break;
				case 2:
				{
					PrintStudent(student);
				}
				break;
				case 3:
				{
					DeleteStudent(student);
				}
				break;
				case 4:
				{
					EditStudent(student);
				}
				break;
				case 5:
				{

					login = false;
				}
				break;
				default:
				{
					cout << "try again !!" << endl;

				}
				break;
				}




			}
			else if (username == "emp" && Password == "456")
			{
				system("cls");
				empmenu();
				int select2;
				cin >> select2;
				switch (select2)
				{
				case 1:
				{
					PrintStudent(student);
				}
				break;
				case 2:
				{
					login = false;
				}
				break;
				default:
				{
					cout << "try again !!" << endl;
					cin.get();
				}
					break;
				}

			}
			else
			{
				cout << "Wrong username or password\nPlease try again" << endl;
				login = false;
			}
		}

	}

}

//---------------------------------------------------------
void adminmenu() {
	cout << "1)Add student" << endl;
	cout << "2)Print student" << endl;
	cout << "3)Delete student" << endl;
	cout << "4)Edit student" << endl;
	cout << "5)log off" << endl;
}
void split(const string& s, char delim, vector<string>& v) {
	auto i = 0;
	auto pos = s.find(delim);
	while (pos != string::npos) {
		v.push_back(s.substr(i, pos - i));
		i = ++pos;
		pos = s.find(delim, pos);

		if (pos == string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}
void addstudent(vector<string>& student) {
	system("cls");
	cin.get();
	string name, surName, age;
	cout << "Please enter name :" << endl;
	getline(cin, name);
	cout << "Please enter surname :" << endl;
	getline(cin, surName);
	cout << "Please enter age :" << endl;
	getline(cin, age);
	string fullname = name + "," + surName + "," + age+",1";
	student.push_back(fullname);
}
void PrintStudent(vector<string> student)
{
	system("cls");

	for (size_t i = 0; i < student.size(); i++)
	{
		vector<string>inf;
		split(student[i], ',', inf);
		if (inf[3] == "1")
		{
			cout << "Name : " << inf[0] << endl;
			cout << "surName : " << inf[1] << endl;
			cout << "Age : " << inf[2] << endl;
			cout << "*************************************" << endl;

		}

	}
	cin.get();
	cin.get();
}
void DeleteStudent(vector<string>& student)
{

	system("cls");
	cin.get();
	string search;
	cout << "Enter Surname" << endl;
	getline(cin, search);
	bool find = false;
	for (size_t i = 0; i < student.size(); i++)
	{
		vector<string>inf;
		split(student[i], ',', inf);
		if (inf[1] == search)
		{
			find = true;
			string name = inf[0];
			string surname = inf[1];
			string age = inf[2];

			string format = name + "," + surname + "," + age + ",0";
			student[i] = format;

		}
	}
	if (!find)
	{
		cout << "User Not Found" << endl;
	}
	cin.get();
	cin.get();



}
void EditStudent(vector<string>& student)
{

	system("cls");
	cin.get();
	string search;
	cout << "Enter Surname" << endl;
	getline(cin, search);
	bool find = false;
	for (size_t i = 0; i < student.size(); i++)
	{
		vector<string>inf;
		split(student[i], ',', inf);
		if (inf[1] == search)
		{
			find = true;
			string name, Surname, age;
			cout << "Enter Name" << endl;
			getline(cin, name);
			cout << "Enter Surname" << endl;
			getline(cin, Surname);
			cout << "Enter Age" << endl;
			getline(cin, age);
			string format = name + "," + Surname + "," + age + ",1";
			student[i] = format;

		}
	}
	if (!find)
	{
		cout << "User Not Found" << endl;
	}
	cin.get();
	cin.get();



}
void empmenu() {
	cout << "1)print student" << endl;
	cout << "2)log off" << endl;
}
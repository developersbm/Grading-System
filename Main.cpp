/*
	Bastida Marin, Sebastian (Team Leader)
	Lee, Kevin
	Zhang, Kevin
	
	Project: Grade Report
*/

#include "InputHandler.h"
#include "OutputHandler.h"

#include <iostream>

using namespace std;

const string TEXT_FILE = "student_data.txt";

void displayMenu();
void processChoice(StudentList& paramStudentList, double tuitionRate);

int main()
{
	StudentList studentList;
	double number = 0.0;
	readStudentData(TEXT_FILE, studentList, number);

	processChoice(studentList, TUITION_RATE);
}

void displayMenu()
{
	cout << "\n*** MAIN MENU ***\n"
		 << "\nSelect one of the following:\n"
		 << "\n    1: Print all students\n"
		 << "    2: Print student information\n"
		 << "    3: Search student by last name\n"
		 << "    4: Print students by course\n"
		 << "    5: Print students on hold\n"
		 << "    6: Print students to file\n"
		 << "    7: Change student's first name\n"
		 << "    8: To exit\n"
		 << "\nEnter your choice: ";
}

void processChoice(StudentList& paramStudentList, double tuitionRate)
{
	int choice = 0, id = 0, courseNumber = 0;
	string lastName, coursePrefix;

	while (choice != 8)
	{
		displayMenu();
		cin >> choice;
		switch (choice)
		{
			case 1:
				paramStudentList.printAllStudents(tuitionRate);
				break;
			case 2:
				cout << "\nPlease enter student's ID: ";
				cin >> id;
				paramStudentList.printStudentByID(id, tuitionRate);
				break;
			case 3:
				cout << "\nPlease enter the student's last name: ";
				cin >> lastName;
				paramStudentList.printStudentByName(lastName);
				break;
			case 4:
				cout << "\nPlease enter the course prefix: ";
				cin >> coursePrefix;
				cout << "Please enter the course number: ";
				cin >> courseNumber;
				cout << '\n';
				paramStudentList.printStudentsByCourse(
					coursePrefix,courseNumber);
				break;
			case 5:
				paramStudentList.printStudentsOnHold(tuitionRate);
				break;
			case 6:
				printAllStudentsToFile(paramStudentList, tuitionRate);
				break;
			case 7:
				paramStudentList.changeStudentFirstName();
				break;
			case 8:
				cout << "\nThank you for using the OCC Gradebook."
					 << " Good-bye!\n";
				break;
			default:
				cout << "\nSorry. That is not a selection.\n";
				break;
		}
		cout << endl;
		system("Pause");
	}
}
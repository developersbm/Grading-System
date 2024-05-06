/*
	Bastida Marin, Sebastian (Team Leader)
	Lee, Kevin
	Zhang, Kevin

	Project: Grade Report
*/

#include "StudentList.h"
#include "InputHandler.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void StudentList::addStudent(const Student& paramStudent)
{
	Node* newNode = new Node(paramStudent, nullptr);

	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
	}
	else if (last != nullptr)
	{
		last->setNext(newNode);
		last = newNode;
	}
	count++;
}

int StudentList::getNoOfStudents() const
{
	return count;
}

void StudentList::printStudentByID(int idNumber,
	double tuitionRate) const
{
	Node* current = first;
	bool found = false;
	if(count == 0)
	{
		found = false;
	}
	else
	{
		while (current != nullptr && !found)
		{
			if (current->getStudent().getID() == idNumber)
			{
				current->getStudent().printStudentInfo(tuitionRate);
				found = true;
			}
			else
			{
				current = current->getNext();
			}
		}
	}

	if(!found)
	{
		cerr << "\nNo students with ID " << idNumber 
			 << " found in the list.\n";
	}
}

void StudentList::printStudentByName(const string& lastName) const
{
	bool found = false;
	if (count == 0)
	{
		found = false;
	}
	else
	{
		Node* current = first;

		while (current != nullptr)
		{
			if (current->getStudent().getLastName() == lastName)
			{
				cout << '\n' << current->getStudent().getID() << " - "
					 << current->getStudent().getLastName() << ", " 
					 << current->getStudent().getFirstName() << '\n';
				found = true;
			}
			current = current->getNext();
		}
	}
	if (!found)
	{
		cerr << "\nNo students with last name " << lastName 
			 << " is on the list.\n";
	}
}

void StudentList::printStudentsByCourse(const string& coursePrefix,
	int courseNumber) const
{
	Node* current = first;
	bool found = false;

	if(count == 0)
	{
		found = false;
	}
	else
	{
		while(current != nullptr)
		{
			for (const auto& course : 
			current->getStudent().getCoursesCompleted())
			{
				if (course.first.getCoursePrefix() == coursePrefix &&
					course.first.getCourseNumber() == courseNumber)
				{
					found = true;
					current->getStudent().printStudent();
				}
			}

			current = current->getNext();
		}	
	}

	if(!found)
	{
		cerr << "\nNo students enrolled in " << coursePrefix << " " 
			 << courseNumber << ".\n";
	}
}

void StudentList::printAllStudents(double tuitionRate) const
{
	Node* current = first;

	while (current != nullptr)
	{
		current->getStudent().printStudentInfo(tuitionRate);
		current = current->getNext();
	}
}

void StudentList::printStudentsToFile(ofstream& outputFile, 
	double tuitionRate) const 
{
	Node* current = first;
	while (current != nullptr) 
	{
		Student currentStudent = current->getStudent();
		
		outputFile << "Student Name: " << currentStudent.getLastName() 
				   << ", " << currentStudent.getFirstName() << '\n'
				   << "Student ID: " << currentStudent.getID() << '\n'
				   << "Number of courses completed: " 
				   << currentStudent.getNumberOfCourses() << '\n'
				   << "\nCourseNo   Units   Grade" << '\n';

		for (const auto& course : currentStudent.getCoursesCompleted())
		{
			outputFile << setw(5) << left 
				<< course.first.getCoursePrefix() +
				" " + to_string(course.first.getCourseNumber())
				<< setw(6) << right << course.first.getCourseUnits()
				<< setw(8) << right << course.second << "\n";
		}

		outputFile << "\nTotal number of credit hours: " 
				   << currentStudent.getUnitsCompleted() << '\n'
				   << "Current Term GPA: " << fixed << setprecision(2)
				   << currentStudent.calculateGPA() << '\n'
				   << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";

		current = current->getNext();
	}
}

void StudentList::printStudentsOnHold(double tuitionRate) const
{
	Node* current = first;
	bool found = false;

	while (current != nullptr)
	{
		Student currentStudent = current->getStudent();
		if (!currentStudent.isTuitionPaid())
		{
			found = true;
			cout << '\n' << currentStudent.getID() << " - " 
				 << currentStudent.getLastName() << ", "
				 << currentStudent.getFirstName() << "\n"
				 << "    Amount Due: $" << fixed << setprecision(2)
				 << currentStudent.billingAmount(tuitionRate);
		}
		current = current->getNext();
	}
	cout << '\n';
	if (!found)
	{
		cout << "\nThere are no students on hold.\n";
	}
}

void StudentList::changeStudentFirstName()
{
	if (count == 0)
	{
		cerr << "Student List is empty.\n";
	}
	else
	{
		bool found = false;
		Node* current = first;
		int id;
		string firstName, lastName, newFirstName;

		cout << "\nPlease enter student's ID: ";
		cin >> id;

		while (current != nullptr && !found)
		{
			if(current->getStudent().getID() == id)
			{
				found = true;
			}
			else
			{
				current = current->getNext();
			}
		}
		
		if (!found)
		{
			cout << "\nNo student with ID " << id 
				 << " exists in the list.\n";
		}
		else
		{
			cout << "Please enter student's first name: ";
			cin >> firstName;

			if (current->getStudent().getFirstName() == firstName)
			{
				cout << "Please enter student's last name: ";
				cin >> lastName;

				if (current->getStudent().getLastName() == lastName)
				{
					cout << "Please enter student's new first name: ";
					cin >> newFirstName;

					Student tempStudent;
					tempStudent.setStudent(current->getStudent());
					tempStudent.setFirstName(newFirstName);
					current->setStudent(tempStudent);
					current->getStudent().printStudent();
					found = true;
				}
				else
				{
					cout << "\nThe last name, " << lastName 
						 << ", does not match the ID " << id << ".\n";
				}
			}
			else
			{
				cout << "\nThe first name, " << firstName 
					 << ", does not match the ID " << id << ".\n";
			}
		}
	}
}

void StudentList::clearStudentList()
{
	if (count != 0)
	{
		if (count == 1)
		{
			delete first;
		}
		else
		{
			Node* current = first;

			while (current != nullptr)
			{
				Node* tempCurrent = current->getNext();
				delete current;
				current = nullptr;
				current = tempCurrent;
			}
		}
	}
	first = nullptr;
	last = nullptr;
	count = 0;
}

StudentList::~StudentList()
{
	clearStudentList();
}
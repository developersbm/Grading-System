/*
	Bastida Marin, Sebastian (Team Leader)
	Lee, Kevin
	Zhang, Kevin

	Project: Grade Report
*/

#include "Student.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Student::setStudent(const Student& aStudent)
{
	studentID = aStudent.studentID;
	firstName = aStudent.firstName;
	lastName = aStudent.lastName;
	numberOfCourses = aStudent.numberOfCourses;
	tuitionWasPaid = aStudent.tuitionWasPaid;
	coursesCompleted = aStudent.coursesCompleted;
}

void Student::setStudentInfo(int aStudentID, const string& aFirstName,
const string& aLastName, bool paramTuitionPaid, const multimap<Course,
char>& paramCoursesCompleted)
{
	studentID = aStudentID;
	firstName = aFirstName;
	lastName = aLastName;
	numberOfCourses = static_cast<int>(paramCoursesCompleted.size());
	tuitionWasPaid = paramTuitionPaid;
	coursesCompleted = paramCoursesCompleted;
}

void Student::setFirstName(const std::string& newFirstName)
{
	firstName = newFirstName;
}

int Student::getID() const
{
	return studentID;
}

string Student::getFirstName() const 
{
	return firstName;
}

string Student::getLastName() const 
{
	return lastName;
}

void Student::getName(string& paramFirstName, 
	string& paramLastName) const
{
	paramFirstName = firstName;
	paramLastName = lastName;
}

int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}

int Student::getUnitsCompleted() const
{
	int unitsCompleted = 0;
	
	for(const auto& course: coursesCompleted)
	{
		unitsCompleted += course.first.getCourseUnits();
	}

	return unitsCompleted;
}

multimap<Course, char> Student::getCoursesCompleted() const
{
	return coursesCompleted;
}

bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

bool Student::isCourseCompleted(const string& prefix, int number) const
{
	if(numberOfCourses == 0)
	{
		return false;
	}
	else
	{
		for(const auto& course : coursesCompleted)
		{
			if(prefix == course.first.getCoursePrefix() 
			&& number == course.first.getCourseNumber())
			{
				return true;
			}
		}
		return false;
	}
}

double Student::calculateGPA() const
{
	double totalGradePoints = 0.0;
	double totalCourseUnits = 0.0;

	for (const auto& course : coursesCompleted)
	{
		char grade = course.second;

		double gradePoint = 0.0;

		switch (grade)
		{
			case 'A': gradePoint = 4.0; break;
			case 'B': gradePoint = 3.0; break;
			case 'C': gradePoint = 2.0; break;
			case 'D': gradePoint = 1.0; break;
			case 'F': gradePoint = 0.0; break;

			default:
				cerr << "Value for grade inputted is wrong\n";
		}

		totalGradePoints += course.first.getCourseUnits() * gradePoint;
		totalCourseUnits += course.first.getCourseUnits();
	}
	return (totalCourseUnits != 0.0 ?
	(totalGradePoints / totalCourseUnits) : 0.0);
}

double Student::billingAmount(double tuitionRate) const
{
	return static_cast<int>(coursesCompleted.size()) * tuitionRate;
}

void Student::printStudent() const
{
	cout << '\n' << studentID << " - " 
		 << lastName << ", " << firstName << '\n';
}

void Student::printStudentInfo(double tuitionRate) const
{
	cout << "\nStudent Name: " << lastName << ", "
		 << firstName << '\n' << "Student ID: "
		 << studentID << '\n'
		 << "Number of courses completed: "
		 << numberOfCourses << '\n'
		 << "\nCourseNo   Units   Grade" << '\n';

	for (const auto& course : coursesCompleted)
	{
		cout << setw(5) << left << course.first.getCoursePrefix() +
			 " " + to_string(course.first.getCourseNumber())
			 << setw(6) << right << course.first.getCourseUnits()
			 << setw(8) << right << course.second << "\n";
	}

	if (isTuitionPaid())
	{
		cout << "\nTotal number of credit hours: " 
			 << getUnitsCompleted() << '\n' << "Current Term GPA: " 
			 << fixed << setprecision(2) << calculateGPA() << '\n'
			 << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
	}
	else
	{
		cout << "\nTotal number of credit hours: " 
			 << getUnitsCompleted() << '\n'
			 << "*** Grades are being held for not paying the tuition. ***\n"
			 << "Amount Due: $" << fixed << setprecision(2) 
			 << billingAmount(tuitionRate) << '\n' 
			 << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
	}
}
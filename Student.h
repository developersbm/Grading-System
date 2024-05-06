/*
	Bastida Marin, Sebastian (Team Leader)
	Lee, Kevin
	Zhang, Kevin

	Project: Grade Report
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

#include <map>
#include <string>

class Student
{
public:
	Student() : studentID(0), numberOfCourses(0), tuitionWasPaid(false) {}

	void setStudent(const Student& aStudent);
	void setStudentInfo(int aStudentID, const std::string& aFirstName,
		const std::string& aLastName, bool paramTuitionPaid, 
		const std::multimap<Course, char>& paramCoursesCompleted);
	void setFirstName(const std::string& newFirstName);

	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	void getName(std::string& paramFirstName,
		 std::string& paramLastName) const;
	int getNumberOfCourses() const;
	int getUnitsCompleted() const;
	std::multimap<Course, char> getCoursesCompleted() const;

	bool isTuitionPaid() const;
	bool isCourseCompleted(const std::string& prefix,
		 int number) const;

	double calculateGPA() const;
	double billingAmount(double tuitionRate) const;

	void printStudent() const;
	void printStudentInfo(double tuitionRate) const;

	~Student(){}

private:
	int studentID;
	std::string firstName;
	std::string lastName;
	int numberOfCourses;
	bool tuitionWasPaid;
	std::multimap<Course, char> coursesCompleted;
};
#endif
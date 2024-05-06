/*
	Bastida Marin, Sebastian (Team Leader)
	Lee, Kevin
	Zhang, Kevin

	Project: Grade Report
*/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <string>

class Node
{
public:
	Node() : student(), next(nullptr) {}
	Node(const Student& paramStudent, Node* newNext)
		: next(newNext) { student.setStudent(paramStudent); }
	Node* getNext() const { return next; }
	Student getStudent() const { return student; }
	void setStudent(Student paramStudent) { student.setStudent(paramStudent); }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}

private:
	Student student;
	Node* next;
};

class StudentList
{
public:
	StudentList() : first(nullptr), last(nullptr), count(0) {}
	StudentList(const StudentList& rightSide);

	void addStudent(const Student& paramStudent);

	int getNoOfStudents() const;

	void printStudentByID(int idNumber, double tuitionRate) const;
	void printStudentByName(const std::string& lastName) const;
	void printStudentsByCourse(const std::string& coursePrefix,
		int courseNumber) const;
	void printAllStudents(double tuitionRate) const;

	void printStudentsToFile(std::ofstream& outputFile, 
		double tuitionRate) const;
	void printStudentsOnHold(double tuitionRate) const;

	void clearStudentList();
	void changeStudentFirstName();

	StudentList& operator=(const StudentList& paramObject);

	~StudentList();

private:
	Node* first;
	Node* last;
	int count;

	void copyCallingObjIsEmpty(const StudentList& paramObject);
	void copyObjectsSameLength(const StudentList& paramObject);
	void copyCallingObjLonger(const StudentList& paramObject);
	void copyCallingObjShorter(const StudentList& paramObject);
};
#endif
/*
	Bastida Marin, Sebastian (Team Leader)
	Lee, Kevin
	Zhang, Kevin

	Project: Grade Report
*/

#include "StudentList.h"

#include <iostream>

using namespace std;

StudentList::StudentList(const StudentList& paramObject)
{
	if (paramObject.first != nullptr)
	{
		Node* currentParam = paramObject.first;
		first = new Node(currentParam->getStudent(), nullptr);
		Node* current = first;

		while (currentParam->getNext() != nullptr)
		{
			currentParam = currentParam->getNext();
			current->setNext(new Node(
				currentParam->getStudent(), nullptr));
			current = current->getNext();
		}
		last = current;
	}
	else
	{
		first = nullptr;
		last = nullptr;
	}
	count = paramObject.count;
}

StudentList& StudentList::operator=(const StudentList& paramObject)
{
	if (this == &paramObject)
	{
		cerr << "Attempted assignment to itself.";
	}
	else if (paramObject.count == 0)
	{
		clearStudentList();
	}
	else if (count == 0)
	{
		copyCallingObjIsEmpty(paramObject);
	}
	else if (count == paramObject.count)
	{
		copyObjectsSameLength(paramObject);
	}
	else if (count > paramObject.count)
	{
		copyCallingObjLonger(paramObject);
	}
	else
	{
		copyCallingObjShorter(paramObject);
	}
	
	return *this;
}

void StudentList::copyCallingObjIsEmpty(const StudentList& paramObject)
{
	Node* currentParam = paramObject.first;
	first = new Node(currentParam->getStudent(), nullptr);
	Node* current = first;

	while (currentParam->getNext() != nullptr)
	{
		currentParam = currentParam->getNext();
		Node* newNode = new Node(currentParam->getStudent(), nullptr);
		current->setNext(newNode);
		current = current->getNext();
	}

	last = current;
}

void StudentList::copyObjectsSameLength(const StudentList& paramObject)
{
	if (count == paramObject.count)
	{
		Node* current = first;
		Node* paramCurrent = paramObject.first;

		while (paramCurrent != nullptr)
		{
			current->setStudent(paramCurrent->getStudent());
			paramCurrent = paramCurrent->getNext();

			if (paramCurrent == nullptr){last = current; }

			current = current->getNext();
		}
	}
}

void StudentList::copyCallingObjLonger(const StudentList& rightSide)
{
	if (count > rightSide.count)
	{
		Node* current = first;
		Node* paramCurrent = rightSide.first;

		while (paramCurrent != nullptr)
		{
			current->setStudent(paramCurrent->getStudent());

			paramCurrent = paramCurrent->getNext();
			current = current->getNext();

			if (paramCurrent == rightSide.last)
			{
				last = current;
				last->setNext(nullptr);
			}
		}

		while (current != nullptr)
		{
			Node* temp = current;
			delete temp;
			temp = nullptr;
			current = current->getNext();
		}
	}
}

void StudentList::copyCallingObjShorter(const StudentList& paramObject)
{
	if (count < paramObject.count)
	{
		Node* current = first;
		Node* paramCurrent = paramObject.first;

		while (current != nullptr)
		{
			current->setStudent(paramCurrent->getStudent());

			paramCurrent = paramCurrent->getNext();
			current = current->getNext();
		}

		Node* lastCurrent = last;
		while (paramCurrent != nullptr)
		{
			lastCurrent->setNext(new Node
				(paramCurrent->getStudent(), nullptr));

			paramCurrent = paramCurrent->getNext();
			lastCurrent = lastCurrent->getNext();

			if (paramCurrent == nullptr)
			{
				last = lastCurrent;
			}
		}
		count = paramObject.count;
	}
}
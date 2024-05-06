/*
	Bastida Marin, Sebastian (Team Leader)
	Lee, Kevin
	Zhang, Kevin

	Project: Grade Report
*/

#include "Course.h"

using namespace std;

void Course::setCourseInfo(const string& paramCoursePrefix, 
	int paramCourseNumbers, int paramCourseUnits)
{
	coursePrefix = paramCoursePrefix;
	courseNumber = paramCourseNumbers;
	courseUnits = paramCourseUnits;
}

string Course::getCoursePrefix() const
{
	return coursePrefix;
}

int Course::getCourseNumber() const
{
	return courseNumber;
}

int Course::getCourseUnits() const
{
	return courseUnits;
}

bool Course::operator<(const Course& otherCourse) const
{
	return ((coursePrefix != otherCourse.coursePrefix) ?
		coursePrefix < otherCourse.coursePrefix :
		courseNumber < otherCourse.courseNumber);
}
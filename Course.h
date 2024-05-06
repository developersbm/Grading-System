/*
	Bastida Marin, Sebastian (Team Leader)
	Lee, Kevin
	Zhang, Kevin

	Project: Grade Report
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
public:
	Course() : courseNumber(0), courseUnits(0) {};

	void setCourseInfo(const std::string& paramCoursePrefix, 
		int paramCourseNumbers, int paramCourseUnits);

	std::string getCoursePrefix() const;
	int getCourseNumber() const;
	int getCourseUnits() const;

	bool operator<(const Course& otherCourse) const;

	~Course() {}

private:
	std::string coursePrefix;
	int courseNumber;
	int courseUnits;
};
#endif
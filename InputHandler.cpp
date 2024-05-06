#include "InputHandler.h"

#include "Course.h"
#include "Student.h"

#include <string>
#include <map>

void createStudentList(std::ifstream& infile,
	StudentList& studentList, double& tuitionRate)
{
	tuitionRate = TUITION_RATE;

	std::string firstName,
		lastName;
	int id = 0,
		noOfCourses = 0;
	char isPaid = 'N';
	bool isTuitionPaid = false;

	std::string coursePrefix;
	int courseNumber = 0,
		units = 0;
	char grade = 'I';

	Course courseTemp;
	Student studentTemp;

	infile >> id;

	while (id != 0)
	{
		infile >> firstName >> lastName >> isPaid >> noOfCourses;

		isTuitionPaid = (isPaid == 'Y');

		std::multimap<Course, char> coursesCompleted;

		for (int i = 0; i < noOfCourses; ++i)
		{
			infile >> coursePrefix >> courseNumber >> units >> grade;
			courseTemp.setCourseInfo(coursePrefix, courseNumber, units);
			coursesCompleted.insert(std::make_pair(courseTemp, grade));
		}

		studentTemp.setStudentInfo(id, firstName,
			lastName, isTuitionPaid, coursesCompleted);
		studentList.addStudent(studentTemp);

		infile >> id;
	}
}

void readStudentData(const std::string& fileName,
	StudentList& studentList, double& tuitionRate)
{
	std::ifstream infile;

	infile.open(fileName);

	if (!infile)
	{
		std::cerr << "Input file does not exist.\n";
	}
	else
	{
		createStudentList(infile, studentList, tuitionRate);
	}

	infile.close();
}
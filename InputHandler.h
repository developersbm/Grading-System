#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "StudentList.h"

#include <iostream>
#include <fstream>

const double TUITION_RATE = 350.0;

void createStudentList(std::ifstream& infile,
	StudentList& studentList, double& tuitionRate);

void readStudentData(const std::string& fileName,
	StudentList& studentList, double& tuitionRate);

#endif
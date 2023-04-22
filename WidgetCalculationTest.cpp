#include "TestHarness.h"
#include "WidgetCalculations.h"
#include <iostream>
#include <array>
// To add your own unit tests
// 
// 1) Rename this file using a name that describes the software entity under test. E.g., if you were testing std::vector
//    rename this file as VectorTest.cpp
// 2) Add additional test files as needed. E.g., if you were testing a class named Animal and another class named Zoo you
//    would have two test files. AnimalTest.cpp and ZooTest.cpp
// 3) Remove the sample tests from this file

TEST(average, DataAverage)
{
	WidgetCalculations t("WidgetData.txt");
	CHECK_DOUBLES_EQUAL(0, t.getAverage(0),0.01);
	CHECK_DOUBLES_EQUAL(4.00401, t.getAverage(5), 0.001);
	CHECK_DOUBLES_EQUAL(0.996844, t.getAverage(7), 0.001);
	CHECK_DOUBLES_EQUAL(2.99423, t.getAverage(12), 0.001);
}

TEST(STD, DataSTD)
{
	WidgetCalculations t("WidgetData.txt");
	CHECK_DOUBLES_EQUAL(0, t.getSTD(0), 0.01);
	CHECK_DOUBLES_EQUAL(0.0951352, t.getSTD(5), 0.001);
	CHECK_DOUBLES_EQUAL(0.0920382, t.getSTD(7), 0.001);
	CHECK_DOUBLES_EQUAL(0.104239, t.getSTD(12), 0.001);
}

TEST(Cp, DataCapability)
{
	WidgetCalculations t("WidgetData.txt");
	//CHECK_DOUBLES_EQUAL(0, t.getCp(0), 0.01);
	
	if (!t.getCp(0)<=0) {
		CHECK_FAIL("Can not divide by 0");
	}
	CHECK_DOUBLES_EQUAL(0.350378, t.getCp(5), 0.001);
	CHECK_DOUBLES_EQUAL(0.362169, t.getCp(7), 0.001);
	CHECK_DOUBLES_EQUAL(0.319777, t.getCp(12), 0.001);
}

TEST(DefectCount, DataDefect)
{
	WidgetCalculations t("WidgetData.txt");
	//CHECK_DOUBLES_EQUAL(0, t.getCp(0), 0.01);

	CHECK_EQUAL(33, t.getDefectCount()[3]);
	CHECK_EQUAL(32, t.getDefectCount()[5]);
	CHECK_EQUAL(42, t.getDefectCount()[7]);
	CHECK_EQUAL(31, t.getDefectCount()[12]);
}

TEST(Pareto, DataPareto)
{
	WidgetCalculations t("WidgetData.txt");
	//CHECK_DOUBLES_EQUAL(0, t.getCp(0), 0.01);

	CHECK_EQUAL(7, t.paretoList()[0]);
	CHECK_EQUAL(5, t.paretoList()[5]);
	CHECK_EQUAL(4, t.paretoList()[7]);
	CHECK_EQUAL(0, t.paretoList()[12]);
}



TEST(equality, strings)
{
	std::stringstream os;
	WidgetCalculations t("WidgetData.txt");
	/*std::cout<< t.getAverage(5) <<"\n";
	std::cout << t.getSTD(5) << "\n";*/
	
	/*for (int arr : t.getDefectCount()) {
		std::cout << arr << ", ";
	}
	std::cout << "\n";*/
	/*t.streamReport(os);
	std::cout << os.str();*/
	//CHECK_EQUAL("Hello", hello);
}



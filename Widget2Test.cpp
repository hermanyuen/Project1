#include "TestHarness.h"
#include "Widget2.h"
#include "WidgetCalculations.h"

// To add your own unit tests
// 
// 1) Rename this file using a name that describes the software entity under test. E.g., if you were testing std::vector
//    rename this file as VectorTest.cpp
// 2) Add additional test files as needed. E.g., if you were testing a class named Animal and another class named Zoo you
//    would have two test files. AnimalTest.cpp and ZooTest.cpp
// 3) Remove the sample tests from this file

TEST(PartNumber, DataPart2)
{
	Widget2 part(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);

	CHECK_EQUAL(1, part.getPartNumber());
	CHECK_EQUAL(2, part.getId());
	CHECK_DOUBLES_EQUAL(3.0, part.getLength(), 0.01);
	CHECK_DOUBLES_EQUAL(4.0, part.getWidth(), 0.01);
	CHECK_DOUBLES_EQUAL(5.0, part.getMidLength(), 0.01);
	CHECK_DOUBLES_EQUAL(6.0, part.getHeight(), 0.01);
	CHECK_DOUBLES_EQUAL(7.0, part.getMidHeight(), 0.01);
	CHECK_DOUBLES_EQUAL(8.0, part.getHoleSize1(), 0.01);
	CHECK_DOUBLES_EQUAL(9.0, part.getHolePosition1(), 0.01);
	CHECK_DOUBLES_EQUAL(10.0, part.getHoleDepth1(), 0.01);
	CHECK_DOUBLES_EQUAL(11.0, part.getHoleSize2(), 0.01);
	CHECK_DOUBLES_EQUAL(12.0, part.getHolePosition2(), 0.01);
	CHECK_DOUBLES_EQUAL(13.0, part.getHoleDepth2(), 0.01);
}

TEST(PartNumber, DataObj2)
{
	WidgetCalculations test("WidgetData.txt");

	CHECK_EQUAL(2, test.get(99).getPartNumber());
	CHECK_EQUAL(50, test.get(99).getId());
	CHECK_DOUBLES_EQUAL(6.161, test.get(99).getLength(), 0.01);
	CHECK_DOUBLES_EQUAL(3.952, test.get(99).getWidth(), 0.01);
	CHECK_DOUBLES_EQUAL(3.892, test.get(99).getMidLength(), 0.01);
	CHECK_DOUBLES_EQUAL(3.159, test.get(99).getHeight(), 0.01);
	CHECK_DOUBLES_EQUAL(1.152, test.get(99).getMidHeight(), 0.01);
	CHECK_DOUBLES_EQUAL(0.9938, test.get(99).getHoleSize1(), 0.01);
	CHECK_DOUBLES_EQUAL(0.9388, test.get(99).getHolePosition1(), 0.01);
	CHECK_DOUBLES_EQUAL(0.7815, test.get(99).getHoleDepth1(), 0.01);
	CHECK_DOUBLES_EQUAL(0.8605, test.get(99).getHoleSize2(), 0.01);
	CHECK_DOUBLES_EQUAL(3.03, test.get(99).getHolePosition2(), 0.01);
	CHECK_DOUBLES_EQUAL(0.6389, test.get(99).getHoleDepth2(), 0.01);

}
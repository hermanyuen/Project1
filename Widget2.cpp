#include "Widget2.h"

Widget2::Widget2(
	const int& partNumber,
	const int& id,
	const double& length,
	const double& width,
	const double& midLength,
	const double& height,
	const double& midHeight,
	const double& holeSize1,
	const double& holePosition1,
	const double& holeDepth1,
	const double& holeSize2,
	const double& holePosition2,
	const double& holeDepth2) :
	partNumber(partNumber), id(id), length(length), width(width),
	midLength(midLength), height(height), midHeight(midHeight),
	holeSize1(holeSize1), holePosition1(holePosition1), holeDepth1(holeDepth1),
	holeSize2(holeSize2), holePosition2(holePosition2), holeDepth2(holeDepth2)
{
}

int Widget2::getId() const {
	return id;
}
int Widget2::getPartNumber() const {
	return partNumber;
}
const double& Widget2::getLength() const {
	return length;
}
const double& Widget2::getWidth() const {
	return width;
}
const double& Widget2::getMidLength() const {
	return midLength;
}
const double& Widget2::getHeight() const {
	return height;
}
const double& Widget2::getMidHeight() const {
	return midHeight;
}
const double& Widget2::getHoleSize1() const {
	return holeSize1;
}
const double& Widget2::getHolePosition1() const {
	return holePosition1;
}
const double& Widget2::getHoleDepth1() const {
	return holeDepth1;
}
const double& Widget2::getHoleSize2() const {
	return holeSize2;
}
const double& Widget2::getHolePosition2() const {
	return holePosition2;
}
const double& Widget2::getHoleDepth2() const {
	return holeDepth2;
}
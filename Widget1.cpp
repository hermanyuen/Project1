#include "Widget1.h"

Widget1::Widget1(
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
	partNumber(partNumber), id(id),length(length),width(width),
	midLength(midLength),height(height),midHeight(midHeight),
	holeSize1(holeSize1),holePosition1(holePosition1),holeDepth1(holeDepth1),
	holeSize2(holeSize2),holePosition2(holePosition2),holeDepth2(holeDepth2) 
{
}

int Widget1::getId() const {
	return id;
}
int Widget1::getPartNumber() const {
	return partNumber;
}
const double& Widget1::getLength() const {
	return length;
}
const double& Widget1::getWidth() const {
	return width;
}
const double& Widget1::getMidLength() const {
	return midLength;
}
const double& Widget1::getHeight() const {
	return height;
}
const double& Widget1::getMidHeight() const {
	return midHeight;
}
const double& Widget1::getHoleSize1() const {
	return holeSize1;
}
const double& Widget1::getHolePosition1() const {
	return holePosition1;
}
const double& Widget1::getHoleDepth1() const {
	return holeDepth1;
}
const double& Widget1::getHoleSize2() const {
	return holeSize2;
}
const double& Widget1::getHolePosition2() const {
	return holePosition2;
}
const double& Widget1::getHoleDepth2() const {
	return holeDepth2;
}